/*designHomeWork2.ino*/
#include "EspMQTTClient.h"
#include <WiFiManager.h>
#include <Stepper.h>
#include <ESP8266WiFi.h> 
#include <time.h> 
#include <stdio.h>

#define BUZZER_PIN D0
#define BUZZER_ON HIGH
#define BUZZER_OFF LOW
String mqtt_payload;
const int stepsPerRev = 2048; //360
Stepper stepper (stepsPerRev, D4, D2, D3, D1); //IN4, IN2, IN3, IN1

WiFiManager wm;
WiFiManagerParameter wifi_ssid("SSID", "default_ssid", "Enter SSID", 20);
WiFiManagerParameter wifi_psk("Password", "default_password", "Enter Password", 20);
bool res; 
char wifissid_char[128];
char wifipassword_char[128];
String wifissid = "....";
String wifipassword = "....";

int timezone = 3; 
int dst = 0; 
unsigned long previousMillis = 0;
const long interval = 1000; 

#define mqtt_broker "sweetdream.iptime.org"
#define MQTTUsername "iot"
#define MQTTPassword "csee1414"
#define mqtt_clienname "JJLee"

EspMQTTClient mqtt_client(
  wifissid_char,
  wifipassword_char,
  mqtt_broker,  // MQTT Broker server ip
  MQTTUsername,   // Can be omitted if not needed
  MQTTPassword,   // Can be omitted if not needed
  mqtt_clienname,     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);

const char *pub_feed = "iot/22100579/last_feed";
const char *sub_topic = "iot/22100579";
int check_wifi = 1;
int check_mqtt = 1;

bool connectWifi(){
  res = wm.autoConnect(); // password protected ap
  if(!res) Serial.println("Failed to connect");
  else Serial.println("connected...yeey :)");
  return res;
}


void setup(){
  Serial.begin(115200);
  Serial.println("... setup ...");

  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, BUZZER_OFF); //off
  
  stepper.setSpeed(10); //speed set
  

  wm.addParameter(&wifi_ssid);
  wm.addParameter(&wifi_psk);
  while(!connectWifi()) Serial.println("Cannot connect wifi... retrying....");

  wifissid = WiFi.SSID();
  wifipassword = WiFi.psk();
  wifissid.toCharArray(wifissid_char, wifissid.length()+1);
  wifipassword.toCharArray(wifipassword_char, wifipassword.length()+1);

  WiFi.mode(WIFI_STA); 
  WiFi.begin(wifissid, wifipassword); 
  configTime(3 * 3600, 0, "pool.ntp.org", "time.nist.gov"); 

  digitalWrite(BUZZER_PIN, BUZZER_OFF); 

}

String addTimeGap(String time_str){
  int hour_1 = time_str.charAt(0) - '0';
  int hour_2 = time_str.charAt(1) - '0';
  int hour = hour_1*10 + hour_2;
  hour += 6;
  hour %= 24;
  if(hour >= 10){
    hour_1 = 1;
    hour_2 = hour - 10;
  }else{
    hour_1 = 0;
    hour_2 = hour;
  }
  time_str.setCharAt(0, (hour_1+'0'));
  time_str.setCharAt(1, (hour_2+'0'));

  return time_str;

}

void onConnectionEstablished(){
  Serial.println("... onConnectEstablished ...");

  mqtt_client.subscribe(sub_topic, [](const String & payload) {
    Serial.print("mqtt subscribe: ");
    Serial.println(payload);

    if(payload == "feed"){
      // TODO 작동시간을 mqtt에 쏴
      
      //mqtt_payload = String("{\"Day\" : ") + getTimeString(now) + String(", \"Time\": ") + getDateString(now) +String("}");
      time_t now = time(nullptr); 
      //Serial.println(ctime(&now)); 
      String times = ctime(&now);
      String day_str = times.substring(0, 10);
      String time_str = times.substring(11, 19);
      
      mqtt_payload = String("{\"Day\" : \"") + day_str + String("\", \"Time\": \"") + addTimeGap(time_str) +String("\"}");
      Serial.println(mqtt_payload);
      mqtt_client.publish(pub_feed, mqtt_payload); 

      // 모터를 작동시켜
      stepper.step(stepsPerRev); //360

      //  부저를 울려
      digitalWrite(BUZZER_PIN, BUZZER_ON); 
      delay(1000);
      digitalWrite(BUZZER_PIN, BUZZER_OFF); 
    }

  });
  mqtt_client.publish(sub_topic, "Hello from nodeMCU"); //send it once
  
}

void loop(){

  if(check_wifi == 1 && mqtt_client.isWifiConnected()) {
  Serial.println("Wifi connected!");
  Serial.print("SSID: ");
  Serial.println(wifissid_char);
  Serial.print("PW: ");
  Serial.println(wifipassword_char);
  check_wifi = 0;
  }else if(check_wifi = 0 && mqtt_client.isWifiConnected()) {
    Serial.println("Wifi connection lost...\ntry to reconnect\n");
    connectWifi();
  }else{

    if(check_mqtt == 1 && mqtt_client.isMqttConnected()) {
      Serial.println("MQTT connected");
      check_mqtt = 0;
    }
    mqtt_client.loop(); 
  }

}

/*hw4_nodeMCU_DHT_OLED_HASS.ino*/
#include "EspMQTTClient.h"
#include "DHTesp.h"
#include <Adafruit_SSD1306.h>
#include <WiFiManager.h>

#define LED_PIN D0
#define USBLED_PIN D4
#define DHT_PIN D3
#define CDS_PIN A0
#define DHTTYPE DHTesp::DHT22
#define LED_ON HIGH
#define LED_OFF LOW
#define USBLED_ON LOW
#define USBLED_OFF HIGH

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHTesp dht;
float temperature = 0, humidity = 0;
int lightValue = 0, prevLightValue = 0;
int led_state, usbled_state;
String mqtt_payload;
long long timer = 0;
#define interval 3000

WiFiManager wm;
WiFiManagerParameter wifi_ssid("SSID", "default_ssid", "Enter SSID", 20);
WiFiManagerParameter wifi_psk("Password", "default_password", "Enter Password", 20);

bool res; 
char wifissid_char[128];
char wifipassword_char[128];
String wifissid = "....";
String wifipassword = "....";

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

const char *pub_dht = "iot/22100579/dht22";
const char *pub_cds = "iot/22100579/cds";
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

  pinMode(LED_PIN, OUTPUT);  // LED 
  pinMode(USBLED_PIN, OUTPUT);  // USBLED 
  pinMode(CDS_PIN, INPUT);
  dht.setup(DHT_PIN, DHTTYPE);

  digitalWrite(LED_PIN, LED_OFF);
  digitalWrite(USBLED_PIN, USBLED_OFF);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.setTextSize(1); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.cp437(true); 

  // Show initial display buffer contents on the screen --
  display.display();

  
  wm.addParameter(&wifi_ssid);
  wm.addParameter(&wifi_psk);

  while(!connectWifi()){
    Serial.println("Cannot connect wifi... retrying....");
  }

  wifissid = WiFi.SSID();
  wifipassword = WiFi.psk();
  wifissid.toCharArray(wifissid_char, wifissid.length()+1);
  wifipassword.toCharArray(wifipassword_char, wifipassword.length()+1);

  led_state = LED_OFF;
  usbled_state = USBLED_OFF;

}

void onConnectionEstablished(){
  Serial.println("... onConnectEstablished ...");

  // about LED and USBLED control... 
  mqtt_client.subscribe(sub_topic, [](const String & payload) {
    Serial.print("mqtt subscribe: ");
    Serial.println(payload);
    
    if(payload == "led"){
      if(led_state == LED_ON) led_state == LED_OFF;
      else led_state = LED_ON;
    }
    if(payload == "ledon") led_state = LED_ON ;
    if(payload == "ledoff") led_state = LED_OFF ;

    if(payload == "usbled"){
      if(usbled_state == USBLED_ON) usbled_state == USBLED_OFF;
      else usbled_state = USBLED_ON;
    }
    if(payload == "usbledon") usbled_state = USBLED_ON ;
    if(payload == "usbledoff") usbled_state = USBLED_OFF ;

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
  }

  if(check_wifi = 0 && mqtt_client.isWifiConnected()) {
    Serial.println("Wifi connection lost...");
    connectWifi();

  }else{
    if(check_mqtt == 1 && mqtt_client.isMqttConnected()) {
      Serial.println("MQTT connected");
      check_mqtt = 0;
    }

    mqtt_client.loop(); //on

    display.clearDisplay();

    //sensing dht22 and pub dht22, cds
    if(timer < millis()){

      humidity = dht.getHumidity();
      temperature = dht.getTemperature();
      lightValue = analogRead(CDS_PIN);
      if(isnan(temperature) || isnan(humidity)) Serial.println("loop: cannot read from DHT22");

      mqtt_payload = String("{\"Temp\" : ") + String(temperature) + String(", \"Humi\" : ") + String(humidity) + String("}");
      mqtt_client.publish(pub_dht, mqtt_payload); 
      mqtt_payload = String("{\"Light\" : ") + String(lightValue) + String("}");
      // Serial.println("loop:" + mqtt_payload);
      mqtt_client.publish(pub_cds, mqtt_payload); 

      display.setCursor(10, 5);
      display.print(F("T: "));
      display.print(temperature);
      display.print(char(248)) ;
      display.println("C");
      display.display();
      display.setCursor(10, 15);
      display.print(F("H: "));
      display.print(humidity);
      display.println("%");

      display.display();      // Show initial text

      timer = millis() + interval;
    }

    digitalWrite(LED_PIN, led_state);
    digitalWrite(USBLED_PIN, usbled_state);
  }

  


}

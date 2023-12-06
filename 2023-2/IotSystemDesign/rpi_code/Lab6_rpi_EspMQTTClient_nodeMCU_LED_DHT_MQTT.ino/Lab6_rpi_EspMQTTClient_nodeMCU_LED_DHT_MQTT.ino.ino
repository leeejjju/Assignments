 /*Lab6_rpi_EspMQTTClient_NodeMCU_LED_DHT_MQTT.ino*/
#include "EspMQTTClient.h"
#include "DHTesp.h"

#define LED_PIN D0
#define USBLED_PIN D4
#define DHT_PIN D3
#define CDS_PIN A0

// Sensors and Actuators
#define DHTTYPE DHT22
#define LED_ON HIGH
#define LED_OFF LOW
#define RELAY_ON LOW // active low
#define RELAY_OFF HIGH
#define USBLED_ON RELAY_ON
#define USBLED_OFF RELAY_OFF

int led_state = LED_OFF, usbled_state = USBLED_OFF;
float temperature = 0, humidity = 0;
int lightValue = 0;

DHTesp dht;

const char *WifiSSID = "NTH413";
const char *WifiPassword = "cseenth413";
#define mqtt_broker "sweetdream.iptime.org"
#define MQTTUsername "iot"
#define MQTTPassword "csee1414"
#define mqtt_clienname "JJLee"
// const char *WifiSSID = "leeejjju";
// const char *WifiPassword = "18639158";
// #define mqtt_broker "192.168.137.140"
// #define mqtt_clienname "JJLee"

EspMQTTClient mqtt_client(
  WifiSSID, //wifi information 
  WifiPassword,
  mqtt_broker,  // MQTT Broker server ip
  MQTTUsername,   // Can be omitted if not needed
  MQTTPassword,   // Can be omitted if not needed
  mqtt_clienname,     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);

const char *pub_dht_temp = "iot/22100579/dht22_t";
const char *pub_dht_humi = "iot/22100579/dht22_h";
const char *pub_cds = "iot/22100579/cds";
const char *sub_topic = "iot/22100579";
int check_wifi = 1;
int check_mqtt = 1;

void setup(){
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);  // LED 연결단자
  pinMode(USBLED_PIN, OUTPUT);  // USBLED 연결단자
  led_state = LED_OFF;
  usbled_state = USBLED_OFF;

  pinMode(CDS_PIN, INPUT);
  dht.setup(DHT_PIN, DHTesp::DHTTYPE);

}


long long next_time = 0;

void onConnectionEstablished(){
  Serial.println("... onConnectEstablished ...");

  mqtt_client.subscribe(sub_topic, [](const String & payload) {
    Serial.print(payload);
    led_state = digitalRead(LED_PIN);

    if(payload == "ledon"){
      led_state = LED_ON;
      Serial.println(" :LED turnd on");
    }else if(payload == "ledoff"){
      led_state = LED_OFF;
      Serial.println(" :LED turnd off");
    }else if(payload == "usbledon"){
      usbled_state = USBLED_ON;
      Serial.println(" :USBLED turnd on");
    }else if(payload == "usbledoff"){
      usbled_state = USBLED_OFF;
      Serial.println(" :USBLED turnd off");
    }

    // else if(payload.equals("led") != -1){
    //   if(led_state == LED_ON) led_state = LED_OFF;
    //   else led_state = LED_ON;
    //   Serial.println(" :LED toggled");
    // }else if(payload.equals("usbled") != -1){
    //   if(usbled_state == USBLED_ON) usbled_state = USBLED_OFF;
    //   else usbled_state = USBLED_ON;
    //   Serial.println(" :USBLED toggled");
    // }

    digitalWrite(LED_PIN, led_state);
    digitalWrite(USBLED_PIN, usbled_state);

  });

  mqtt_client.publish(sub_topic, "Hello from nodeMCU");
  
}

void loop(){
  // mqtt_client.loop();
  if(check_wifi == 1 && mqtt_client.isWifiConnected()) {
  Serial.println("Wifi connected!");
  check_wifi = 0;
  }
  else if(check_mqtt == 1 && mqtt_client.isMqttConnected()) {
  Serial.println("MQTT connected");
  check_mqtt = 0;
  }

  mqtt_client.loop();

  if(next_time < millis()){

    String mqtt_payload;
    humidity = dht.getHumidity();
    temperature = dht.getTemperature();
    mqtt_payload = String(temperature);
    mqtt_client.publish(pub_dht_temp, mqtt_payload);
    mqtt_payload = String(humidity);
    mqtt_client.publish(pub_dht_humi, mqtt_payload);
    //Serial.println(" :dht22 value sent");

    lightValue = analogRead(CDS_PIN);
    mqtt_payload = String(lightValue);
    mqtt_client.publish(pub_cds, mqtt_payload);
    //Serial.println(" :cds value sent");

    next_time = millis() + 1000;
  }

}

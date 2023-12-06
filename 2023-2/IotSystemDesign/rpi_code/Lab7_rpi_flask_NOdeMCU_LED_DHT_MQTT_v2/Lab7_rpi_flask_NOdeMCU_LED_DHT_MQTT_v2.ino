 /*Lab7_rpi_flask_NOdeMCU_LED_DHT_MQTT_v2.ino*/
#include "EspMQTTClient.h"
#include "DHTesp.h"

#define LED_PIN D0
#define RELAY2_PIN D4
#define USBLED_PIN RELAY2_PIN 
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

// const char *WifiSSID = "NTH413";
// const char *WifiPassword = "cseenth413";
// #define mqtt_broker "203.252.106.154"
#define MQTTUsername "iot"
#define MQTTPassword "csee1414"
#define mqtt_clienname "JJLee"

const char *WifiSSID = "leeejjju";
const char *WifiPassword = "18639158";
#define mqtt_broker "sweetdream.iptime.org"
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

const char *pub_dht = "iot/22100579/dht22";
const char *pub_cds = "iot/22100579/cds";
const char *sub_topic = "iot/22100579";

int check_wifi = 1;
int check_mqtt = 1;


void setup(){
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);  // LED 연결단자
  led_state = LED_OFF;

  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(CDS_PIN, INPUT);
  dht.setup(DHT_PIN, DHTesp::DHTTYPE);

}

void onConnectionEstablished(){

  mqtt_client.subscribe(sub_topic, [](const String & payload) {
    Serial.print(payload);
    
    if(payload.equals("ledon") != -1){
      led_state = LED_ON;
      Serial.println(" :LED turnd on");
    }else if(payload.equals("ledoff") != -1){
      led_state = LED_OFF;
      Serial.println(" :LED turnd off");
    }else if(payload.equals("led") != -1){
      if(led_state == LED_ON) led_state = LED_OFF;
      else led_state = LED_ON;
      Serial.println(" :LED toggled");
    }else if(payload.equals("dht22") != -1){
      
      humidity = dht.getHumidity();
      temperature = dht.getTemperature();
      String mqtt_payload;
      mqtt_payload = String("Temperature is ") + String(temperature) + 
      String(", and Humidity is ") + String(humidity);
      //}else mqtt_payload = String("cannot mesure temperature and humidity...");
      mqtt_client.publish(pub_dht, mqtt_payload);
      Serial.println(" :dht22 value sent");
    }else if(payload.equals("cds") != -1){
      lightValue = analogRead(CDS_PIN);
      String mqtt_payload = String("Light Intensity is ") + String(lightValue);
      mqtt_client.publish(pub_cds, mqtt_payload);
      Serial.println(" :cds value sent");
    }else Serial.println("invalid comment");

    if(led_state == LED_ON) digitalWrite(LED_PIN, LED_ON);
    else digitalWrite(LED_PIN, LED_OFF);

  });

  // Publish a message to "mytopic/test"
  // client.publish("mytopic/test", "This is a message"); // You can activate the retain flag by setting the third parameter to true
  mqtt_client.publish(sub_topic, "22100579 JinjuLee");
  // Execute delayed instructions
  // client.executeDelayed(5 * 1000, []() {
  //   client.publish("mytopic/wildcardtest/test123", "This is a message sent 5 seconds later");
  // });

  
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
  digitalWrite(LED_PIN, led_state);
  digitalWrite(USBLED_PIN, usbled_state);

}

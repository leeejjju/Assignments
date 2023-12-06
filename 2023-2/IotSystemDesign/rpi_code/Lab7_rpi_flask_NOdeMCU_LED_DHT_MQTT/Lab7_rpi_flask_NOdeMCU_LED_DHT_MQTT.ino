 /*Lab7_rpi_flask_NOdeMCU_LED_DHT_MQTT_v2.ino*/
#include "EspMQTTClient.h"
#include "DHTesp.h"


// Sensors and Actuators
#define LED_PIN D0
#define DHT_PIN D3
#define USBLED_PIN D4 
#define CDS_PIN A0

#define DHTTYPE DHT22
#define LED_ON HIGH
#define LED_OFF LOW
#define RELAY_ON LOW // active low
#define RELAY_OFF HIGH
#define USBLED_ON RELAY_ON
#define USBLED_OFF RELAY_OFF
int led_state = LED_OFF, usbled_state = USBLED_OFF;


//iot/[id]/{led, dht22, cds}
const char* mqtt_topic = "iot/22100579";
DHTesp dht;
int lightValue = 0;
float temperature = 0, humidity = 0;
char pub_data[200];

//nonblocking procedure
unsigned long previousMillis_DHT = 0;
const long interval_DHT = 3000; //1sec


// const char *WifiSSID = "NTH413";
// const char *WifiPassword = "cseenth413";
// #define mqtt_broker "203.252.106.154"
#define MQTTUsername "iot"
#define MQTTPassword "csee1414"
#define mqtt_clienname "JJLee"

const char *WifiSSID = "leeejjju";
const char *WifiPassword = "18639158";
// #define mqtt_broker "192.168.137.140"
// #define mqtt_clienname "JJLee"

#define mqtt_broker "sweetdream.iptime.org"

EspMQTTClient mqtt_client(
  WifiSSID, //wifi information 
  WifiPassword,
  mqtt_broker,  // MQTT Broker server ip
  MQTTUsername,   // Can be omitted if not needed
  MQTTPassword,   // Can be omitted if not needed
  mqtt_clienname,     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);


void setup(){
  Serial.begin(115200);
  Serial.println("Serial port band rate: 115200");

  pinMode(LED_PIN, OUTPUT);  // LED 연결단자
  digitalWrite(LED_PIN, LED_OFF); //init LED
  led_state = LED_OFF; 

  pinMode(USBLED_PIN, OUTPUT);
  pinMode(CDS_PIN, INPUT);
  dht.setup(DHT_PIN, DHTesp::DHT22); 

}

const char *sub_topic = "iot/22100579";
const char *pub_dht = "iot/22100579/dht22";
const char *pub_cds = "iot/22100579/cds";

void onConnectionEstablished(){

  mqtt_client.subscribe(sub_topic, [](const String & payload) {
    Serial.print(payload);
    
    if(payload =="ledon"){
      led_state = LED_ON;
      Serial.println(" :LED turnd on");

    }else if(payload == "ledoff"){
      led_state = LED_OFF;
      Serial.println(" :LED turnd off");

    }else if(payload == "usbledon"){
      usbled_state = USBLED_OFF;
      Serial.println(" :USBLED turnd off");

    }else if(payload == "usbledoff"){
      usbled_state = USBLED_OFF;
      Serial.println(" :USBLED turnd off");

    }else if(payload =="led"){
      if(led_state == LED_ON) led_state = LED_OFF;
      else led_state = LED_ON;
      Serial.println(" :LED toggled");

    }else if(payload =="dht22"){
      
      sprintf(pub_data, "Temperature is %3.2f, and Humidity is %3.2f", temperature, humidity); //json등 추천 
      mqtt_client.publish(pub_dht, pub_data);
      Serial.println(" :dht22 value sent");

    }else if(payload =="cds"){
      lightValue = analogRead(CDS_PIN);
      sprintf(pub_data, "Light Intensity is %3.2f", lightValue); //json등 추천 
      mqtt_client.publish(pub_cds, pub_data);
      Serial.println(" :cds value sent");

    }else Serial.println("  :invalid comment");

  });

  mqtt_client.publish(sub_topic, "This is msg from nodeMCU : JJLee");

}

void loop(){

  mqtt_client.loop();
  unsigned long currentMillis_DHT = millis();
  //Sensing temp and hum every second
  if((currentMillis_DHT - previousMillis_DHT) > interval_DHT){
    previousMillis_DHT = currentMillis_DHT;

    //read tmp and hum
    humidity = dht.getHumidity();
    temperature = dht.getTemperature();

    Serial.print("Temp: ");
    Serial.print(temperature);
    Serial.print(" | Hum: ");
    Serial.println(humidity);
    
  }

  digitalWrite(LED_PIN, led_state);
  digitalWrite(USBLED_PIN, usbled_state);

}



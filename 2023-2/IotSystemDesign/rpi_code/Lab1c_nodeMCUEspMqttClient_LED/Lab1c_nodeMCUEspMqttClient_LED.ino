 /*Lab1c_nodeMCUEspMqttClient_LED.ino*/
#include "EspMQTTClient.h"
#define D0 16  // LED(5파이)
#define LED_PIN D0 
#define LED_ON HIGH //active HIGH
#define LED_OFF LOW
int LED_state;

// const char *WifiSSID = "NTH413";
// const char *WifiPassword = "cseenth413";
// #define mqtt_broker "203.252.106.154"
// #define MQTTUsername "iot"
// #define MQTTPassword "csee1414"

const char *WifiSSID = "leeejjju";
const char *WifiPassword = "18639158";
#define mqtt_broker "192.168.137.140"
#define mqtt_clienname "JJLee"

EspMQTTClient mqtt_client(
  WifiSSID, //wifi information 
  WifiPassword,
  mqtt_broker,  // MQTT Broker server ip
  // MQTTUsername,   // Can be omitted if not needed
  // MQTTPassword,   // Can be omitted if not needed
  mqtt_clienname,     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);

void setup(){
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);  // LED 연결단자
  LED_state = LED_OFF;

  // Optional functionalities of EspMQTTClient
  // mqtt_client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  // mqtt_client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overridded with enableHTTPWebUpdater("user", "password").
  // mqtt_client.enableOTA(); // Enable OTA (Over The Air) updates. Password defaults to MQTTPassword. Port is the default OTA port. Can be overridden with enableOTA("password", port).
  // mqtt_client.enableLastWillMessage("TestClient/lastwill", "Good bye~");  // You can activate the retain flag by setting the third parameter to true
}

void onConnectionEstablished(){

  mqtt_client.subscribe("iot/22100579", [](const String & payload) {
    Serial.print(payload);
    
    // if(payload.indexOf("ledon") != -1){
    //   LED_state = LED_ON;
    //   Serial.println(" :LED turnd on");
    // }else if(payload.indexOf("ledoff") != -1){
    //   LED_state = LED_OFF;
    //   Serial.println(" :LED turnd off");
    // }else 
    
    if(payload.indexOf("led") != -1){
      if(LED_state == LED_ON) LED_state = LED_OFF;
      else LED_state = LED_ON;
      Serial.println(" :LED toggled");
    }else{
      Serial.println(" :invalid command");
    }

    if(LED_state == LED_ON) digitalWrite(LED_PIN, LED_ON);
    else digitalWrite(LED_PIN, LED_OFF);

  });
}

void loop(){
  mqtt_client.loop();

}

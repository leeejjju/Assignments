/*lab5e_EspMQTTClientTest.ino*/
#include "EspMQTTClient.h"

// const char *WifiSSID = "NTH413";
// const char *WifiPassword = "cseenth413";
// #define mqtt_broker "203.252.106.154"
// #define MQTTUsername "iot"
// #define MQTTPassword "csee1414"

const char *WifiSSID = "leeejjju";
const char *WifiPassword = "18639158";
#define mqtt_broker "192.168.137.140"
#define mqtt_clienname "JJLee"


// 접속용 기본설정 
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

  // Optional functionalities of EspMQTTClient
  // mqtt_client.enableDebuggingMessages(); // Enable debugging messages sent to serial output
  // mqtt_client.enableHTTPWebUpdater(); // Enable the web updater. User and password default to values of MQTTUsername and MQTTPassword. These can be overridded with enableHTTPWebUpdater("user", "password").
  // mqtt_client.enableOTA(); // Enable OTA (Over The Air) updates. Password defaults to MQTTPassword. Port is the default OTA port. Can be overridden with enableOTA("password", port).
  // mqtt_client.enableLastWillMessage("TestClient/lastwill", "Good bye~");  // You can activate the retain flag by setting the third parameter to true
}


//sub과 pub을 둘 다 해보겠스빈다 
void onConnectionEstablished(){
  // Subscribe to "mytopic/test" and display received message to Serial
  mqtt_client.subscribe("iot/22100579", [](const String & payload) {
    Serial.println(payload);
  });

  //Publish a message to "iot/22100579"
  mqtt_client.publish("iot/22100579", "This is nodeMCU"); // You can activate the retain flag by setting the third parameter to true

}

void loop(){
  mqtt_client.loop();

}

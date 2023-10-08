// Lab5e_EspMQTTClientTest.ino

#include "EspMQTTClient.h"

// const char *WifiSSID = "NTH413";
// const char *WifiPassword = "cseenth413";
const char *WifiSSID = "leeejjju";
const char *WifiPassword = "18639158";

// #define mqtt_broker "203.252.106.154"
#define mqtt_broker "192.168.137.140"
#define mqtt_clientname "JJLee"

// #define MQTTUsername "iot"
// #define MQTTPassword "csee1414"

EspMQTTClient mqtt_client(
  WifiSSID,
  WifiPassword,
  mqtt_broker,  // MQTT Broker server ip
  // MQTTUsername,   // Can be omitted if not needed
  // MQTTPassword,   // Can be omitted if not needed
  mqtt_clientname,     // Client name that uniquely identify your device
  1883              // The MQTT port, default to 1883. this line can be omitted
);

void setup()
{
  Serial.begin(115200);


}

// This function is called once everything is connected (Wifi and MQTT)
// WARNING : YOU MUST IMPLEMENT IT IF YOU USE EspMQTTClient
void onConnectionEstablished()
{
  // Subscribe to "mytopic/test" and display received message to Serial
  mqtt_client.subscribe("mytopic/test", [](const String & payload) {
    Serial.println(payload);
  });

  // Publish a message to "mytopic/test"
  mqtt_client.publish("mytopic/test", "22100579 JJLee, new"); // You can activate the retain flag by setting the third parameter to true

}

void loop()
{
  mqtt_client.loop();
}

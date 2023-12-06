 /*designHomeWork_rpi_nodeMCU_MQTT.ino*/
#include "EspMQTTClient.h"
#include "DHTesp.h"

#define LED_PIN D0
#define USBLED_PIN D4
#define DHT_PIN D3
#define CDS_PIN A0
#define DHTTYPE DHTesp::DHT22
#define LED_ON HIGH
#define LED_OFF LOW
#define USBLED_ON LOW
#define USBLED_OFF HIGH

// state
#define EVENT_ON 0
#define BUTTON_ON 1
#define TOGGLE_ON 2
#define STATE_OFF 3
int led_state = STATE_OFF, usbled_state = STATE_OFF;

DHTesp dht;
float temperature = 0, humidity = 0;
int lightValue = 0, prevLightValue = 0;

String mqtt_payload;
long long timer_event_led = 0;
long long timer_event_usbled = 0;
long long timer_cds = 0;
long long timer_dht22 = 0;
#define SEC1 1000
#define SEC10 10000

const char *WifiSSID = "JinJuice";
const char *WifiPassword = "1863,,,,,9158";

#define mqtt_broker "sweetdream.iptime.org"
#define MQTTUsername "iot"
#define MQTTPassword "csee1414"
#define mqtt_clienname "JJLee"

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
  Serial.println("... setup ...");

  pinMode(LED_PIN, OUTPUT);  // LED 
  pinMode(USBLED_PIN, OUTPUT);  // USBLED 
  pinMode(CDS_PIN, INPUT);
  dht.setup(DHT_PIN, DHTTYPE);

  digitalWrite(LED_PIN, LED_OFF);
  digitalWrite(USBLED_PIN, USBLED_OFF);

}


void onConnectionEstablished(){
  Serial.println("... onConnectEstablished ...");

  // about LED and USBLED control... 
  mqtt_client.subscribe(sub_topic, [](const String & payload) {
    Serial.print("onConnection: ");
    Serial.println(payload);
    
    //LED: set state via previous state...
    switch (led_state){
      case EVENT_ON :
      if(payload == "led"); //nothing
      if(payload == "ledon") led_state = BUTTON_ON ;
      if(payload == "ledoff") led_state = STATE_OFF ;
      break;

      case BUTTON_ON :
      if(payload == "led") led_state = STATE_OFF ;
      if(payload == "ledon"); //nothing
      if(payload == "ledoff") led_state = STATE_OFF ;
      break;

      case TOGGLE_ON :
      if(payload == "led") led_state = STATE_OFF ;
      if(payload == "ledon") led_state = BUTTON_ON ;
      if(payload == "ledoff") led_state = STATE_OFF ;
      break;

      case STATE_OFF :
      if(payload == "led") led_state = TOGGLE_ON ;
      if(payload == "ledon") led_state = BUTTON_ON ;
      if(payload == "ledoff"); //nothing
      break;
    }

    //USBLED: set state via previous state...
    switch (usbled_state){
      case EVENT_ON :
      if(payload == "usbled"); //nothing
      if(payload == "usbledon") usbled_state = BUTTON_ON ;
      if(payload == "usbledoff") usbled_state = STATE_OFF ;
      break;

      case BUTTON_ON :
      if(payload == "usbled") usbled_state = STATE_OFF ;
      if(payload == "usbledon"); //nothing
      if(payload == "usbledoff") usbled_state = STATE_OFF ;
      break;

      case TOGGLE_ON :
      if(payload == "usbled") usbled_state = STATE_OFF ;
      if(payload == "usbledon") usbled_state = BUTTON_ON ;
      if(payload == "usbledoff") usbled_state = STATE_OFF ;
      break;

      case STATE_OFF :
      if(payload == "usbled") usbled_state = TOGGLE_ON ;
      if(payload == "usbledon") usbled_state = BUTTON_ON ;
      if(payload == "usbledoff"); //nothing
      break;
    }

    Serial.print("onConnection: led state: ");
    Serial.println(led_state);
    Serial.print("onConnection: usbled state: ");
    Serial.println(usbled_state);


  });

  mqtt_client.publish(sub_topic, "Hello from nodeMCU"); //send it once
  
}


void loop(){

  if(check_wifi == 1 && mqtt_client.isWifiConnected()) {
  Serial.println("Wifi connected!");
  check_wifi = 0;
  }
  if(check_mqtt == 1 && mqtt_client.isMqttConnected()) {
  Serial.println("MQTT connected");
  check_mqtt = 0;
  }


  mqtt_client.loop(); //on

  //sensing cds and handling event
  if(timer_cds < millis()){
    lightValue = analogRead(CDS_PIN);
   
    if(prevLightValue > 500 && lightValue < 450){
      Serial.println("event occured!");
      switch (led_state){
        case EVENT_ON :
        //nothing
        break;
        case BUTTON_ON :
        //nothing
        break;
        case TOGGLE_ON :
        case STATE_OFF:
        led_state = EVENT_ON;
        timer_event_led = millis() + SEC10 ;
        break;
      }

      switch (usbled_state){
        case EVENT_ON :
        //nothing
        break;
        case BUTTON_ON :
        //nothing
        break;
        case TOGGLE_ON :
        case STATE_OFF :
        usbled_state = EVENT_ON;
        timer_event_usbled = millis() + SEC10 ;
        break;
      }

      Serial.print("onConnection: led state: ");
      Serial.println(led_state);
      Serial.print("onConnection: usbled state: ");
      Serial.println(usbled_state);

    }

    timer_cds = millis() + SEC1 ; 
    prevLightValue = lightValue;

  }


  //sensing dht22 and pub dht22, cds
  if(timer_dht22 < millis()){

    humidity = dht.getHumidity();
    temperature = dht.getTemperature();
    if(isnan(humidity) || isnan(temperature)) Serial.println("loop: cannot read from DHT22");

    mqtt_payload = String("{\"Temp\" : ") + String(temperature) + String(", \"Humi\" : ") + String(humidity) + String("}");
    // Serial.println("loop:" + mqtt_payload);
    mqtt_client.publish(pub_dht, mqtt_payload); 
    mqtt_payload = String("{\"Light\" : ") + String(lightValue) + String("}");
    // Serial.println("loop:" + mqtt_payload);
    mqtt_client.publish(pub_cds, mqtt_payload); 

    timer_dht22 = millis() + SEC10;
  }

  //checking event
  if(led_state == EVENT_ON && timer_event_led < millis()) {
    led_state = STATE_OFF;
    Serial.println("led event terminated");
  }
  if(usbled_state == EVENT_ON && timer_event_usbled < millis()) {
    usbled_state = STATE_OFF;
    Serial.println("usbled event terminated");
  }
  
  if(led_state == STATE_OFF) digitalWrite(LED_PIN, LED_OFF);
  else digitalWrite(LED_PIN, LED_ON);
  if(usbled_state == STATE_OFF) digitalWrite(USBLED_PIN, USBLED_OFF);
  else digitalWrite(USBLED_PIN, USBLED_ON);


}

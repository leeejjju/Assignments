#include <Adafruit_SSD1306.h>
#include "DHTesp.h" 
#define D3 0
#define D0 16
#define D4 2
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define LED_PIN D0
#define RELAY1_PIN D4 //active low!! 
#define RELAY_OFF HIGH
#define RELAY_ON LOW


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHTesp sensor;
int relay_state = RELAY_OFF;
int is_bright = 0, is_on = 0;

unsigned long previousMillis = 0, startMillis = 0;
const long interval = 1000;
const long light_interval = 10000;

void setup() {
  Serial.begin(9600);
  sensor.setup(D3, DHTesp::DHT22); // Connect DHT sensor to GPIO 17
  pinMode(LED_PIN, OUTPUT); //set LED output
  digitalWrite(LED_PIN, LOW); //init LED
  pinMode(A0, INPUT); //set light seneor 
  pinMode(RELAY1_PIN, OUTPUT); //set relay signal

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

}

void loop() {
  
  float hum = sensor.getHumidity();
  float temp = sensor.getTemperature();
  int light_val = analogRead(A0);

  unsigned long currentMillis = millis();
  display.clearDisplay();


  if( is_on && (currentMillis - startMillis >= light_interval)){

    relay_state = RELAY_OFF;
    Serial.println(F("USBLED turned off."));
    is_on = 0;

  }

  
  if(currentMillis - previousMillis >= interval){

    previousMillis = currentMillis;
    if(light_val < 500) {
      if(is_bright){
        relay_state = RELAY_ON;
        is_on = 1;
        Serial.println(F("USBLED turned on."));
        startMillis = millis();
      } 
      is_bright = 0;
    }else if(light_val > 600) {
      // relay_state = RELAY_OFF;
      is_bright = 1;
    }

    if( !isnan(hum) && !isnan(temp)){
        display.setCursor(10, 5);
        display.print(F("T: "));
        display.print(temp);
        display.print(char(248)) ;
        display.println("C");
        display.display();
        display.setCursor(10, 15);
        display.print(F("H: "));
        display.print(hum);
        display.println("%");
      }else  Serial.println(F("Cannot read information from sensor."));
      display.display();
      
  }

  digitalWrite(RELAY1_PIN, relay_state);
  digitalWrite(LED_PIN, !relay_state);

}



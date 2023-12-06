#include <Adafruit_SSD1306.h>
#include "DHTesp.h" 
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
#define D3 0

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
DHTesp sensor;

unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  Serial.begin(9600);
  sensor.setup(D3, DHTesp::DHT22); // Connect DHT sensor to GPIO 17

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
  display.clearDisplay();
  float hum = sensor.getHumidity();
  float temp = sensor.getTemperature();

  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
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
      }else{
        Serial.println(F("Cannot read information from sensor."));
      }
      display.display();      // Show initial text

  }
}


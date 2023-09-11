#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  display.display();
  delay(1000); // Pause for 2 seconds


}

void loop() {

  // Clear the buffer
  display.clearDisplay();
  delay(500);

  showMyName();    // Draw scrolling text

  delay(1000);


}

void showMyName(void) {
  display.clearDisplay();
  delay(100);

  display.setTextSize(1.5); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 5);
  display.println(F("Lee Jinju"));
  display.display();      // Show initial text
  display.setCursor(10, 15);
  display.println(F("Lee Jinju"));
  display.display();      // Show initial text
  delay(3000);

  
}


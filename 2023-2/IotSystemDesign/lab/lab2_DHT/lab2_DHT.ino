#define D0 16
#define D2 4
#define DHPIN D2
#define DHTTYPE DHTesp::DHT22
#include "DHTesp.h"
//week 1-2
//temperature sensing

DHTesp sensor;

void setup() {
  // put your setup code here, to run once:cddp
  Serial.begin(115200);
  Serial.println("\n\nStart to mesure temperature and humidity...");
  sensor.setup(DHPIN, DHTTYPE); // Connect DHT sensor to GPIO 17

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(sensor.getMinimumSamplingPeriod());

  float hum = sensor.getHumidity();
  float temp = sensor.getTemperature();
  
  if( !isnan(hum) && !isnan(temp)){
    Serial.print("temperature: ");
    Serial.print(temp);
    Serial.print("\thumidity: ");
    Serial.println(hum);
  }else{
    Serial.println("Cannot read information from sensor");
  }

  // Serial.print(sensor.getStatusString());
  // Serial.print("\t");
  // Serial.print(hum, 1);
  // Serial.print("\t\t");
  // Serial.print(temp, 1);
  // Serial.print("\t\t");
  // Serial.print(sensor.toFahrenheit(temp), 1);
  // Serial.print("\t\t");
  // Serial.print(sensor.computeHeatIndex(temp, hum, false), 1);
  // Serial.print("\t\t");
  // Serial.println(sensor.computeHeatIndex(sensor.toFahrenheit(temp), hum, true), 1);



  delay(1000);

}

#define D0 16
#define D4 2
#define LIGHT_PIN A0
#define LED_PIN D0
#define RELAY1_PIN D4 //active low!! 
#define RELAY_OFF HIGH
#define RELAY_ON LOW

int relay_state = RELAY_OFF;
int light_val;

void setup() {
  
  Serial.begin(115200);
  delay(10);
  pinMode(LED_PIN, OUTPUT); //LED output
  digitalWrite(LED_PIN, LOW); //LED off
  pinMode(LIGHT_PIN, INPUT); //light seneor 
  pinMode(RELAY1_PIN, OUTPUT); // relay signal

}

void loop() {
  light_val = analogRead(LIGHT_PIN);
  Serial.print("Light intensity = ");
  Serial.println(light_val);

  if(light_val < 700) relay_state = RELAY_ON;
  else if(light_val > 800) relay_state = RELAY_OFF;

  digitalWrite(RELAY1_PIN, relay_state);
  digitalWrite(LED_PIN, !relay_state);
  delay(500);
}


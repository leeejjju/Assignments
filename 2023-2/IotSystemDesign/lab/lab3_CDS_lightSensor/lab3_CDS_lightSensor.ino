//lab week2-1 
#define LIGHT_PIN A0
#define D0 16
int light_val;

void setup() {
  pinMode(LIGHT_PIN, INPUT);
  Serial.begin(115200);
  pinMode(D0, OUTPUT);

}

void loop() {
  light_val = analogRead(LIGHT_PIN);
  Serial.print("Light intensity = ");
  Serial.println(light_val);
  if(light_val > 800) digitalWrite(D0, LOW);
  else digitalWrite(D0, HIGH);
  delay(1000);
}

#define IR A5
bool IRstate = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(IR, INPUT);
  Serial.println("Detect IR Sensor");
  delay(1000);
}
void loop() {
  IRstate = digitalRead(IR);

  if (IRstate == LOW) {
    Serial.println("Detected");
  } 
  else if (IRstate == HIGH) {
    Serial.println("Not Detected");
  }

}

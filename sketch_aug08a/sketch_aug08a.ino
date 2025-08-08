
int motorPin = 9;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  digitalWrite(motorPin, HIGH); // Turn motor ON
  delay(1000);                  // Wait 1 second
  digitalWrite(motorPin, LOW);  // Turn motor OFF
  delay(1000);                  // Wait 1 second
}

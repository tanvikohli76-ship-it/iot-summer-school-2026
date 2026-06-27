int led = 13;
int count = 0;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
  count++;
  Serial.print("Blink count: ");
  Serial.println(count);
}

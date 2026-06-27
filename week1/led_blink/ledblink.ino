/*
  Author: Tanvi Kohli
  Date: 2026-06-27
  Description: LED blink with adjustable speed using potentiometer and serial blink counter
*/

int led = 13;
int pot = A0;
int count = 0;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int value = analogRead(pot);
  int delayTime = map(value, 0, 1023, 50, 2000);
  digitalWrite(led, HIGH);
  delay(delayTime);
  digitalWrite(led, LOW);
  delay(delayTime);
  count++;
  Serial.print("Blink count: ");
  Serial.println(count);
}

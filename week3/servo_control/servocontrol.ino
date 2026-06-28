/*
  Author: Tanvi Kohli
  Date: 2026-06-27
  Description: servo motor control
*/
#include <Servo.h>

Servo servo;

int potPin = A0;
int buttonPin = 2;

bool sweepMode = false;

void setup() {
  Serial.begin(9600);
  servo.attach(9);
  pinMode(buttonPin, INPUT);
}

void loop() {

  // Check button
  if (digitalRead(buttonPin) == HIGH) {
    sweepMode = true;
  }

  if (sweepMode) {

    // Sweep forward
    for (int angle = 0; angle <= 180; angle++) {
      servo.write(angle);
      Serial.print("Sweep Angle: ");
      Serial.println(angle);
      delay(10);
    }

    // Sweep backward
    for (int angle = 180; angle >= 0; angle--) {
      servo.write(angle);
      Serial.print("Sweep Angle: ");
      Serial.println(angle);
      delay(10);
    }

    sweepMode = false; // run only once
  }

  else {
    // Pot control
    int potValue = analogRead(potPin);
    int angle = map(potValue, 0, 1023, 0, 180);

    servo.write(angle);

    Serial.print("Angle: ");
    Serial.println(angle);

    delay(200);
  }
}

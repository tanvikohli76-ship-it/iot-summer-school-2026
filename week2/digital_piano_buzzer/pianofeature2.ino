/*
  Author: Tanvi Kohli
  Date: 2026-06-27
  Description: digital piano buzzer with feature 2
*/
int buzzer = 8;

int b1 = 2;
int b2 = 3;
int b3 = 4;
int b4 = 5;

void setup() {
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(b3, INPUT_PULLUP);
  pinMode(b4, INPUT_PULLUP);
}

void loop() {

  if (!digitalRead(b1)) {
    tone(buzzer, 262);
  }
  else if (!digitalRead(b2)) {
    tone(buzzer, 294);
  }
  else if (!digitalRead(b3)) {
    tone(buzzer, 330);
  }
  else if (!digitalRead(b4)) {
    tone(buzzer, 349);
  }
  else {
    noTone(buzzer); // ✅ fix added
  }

}

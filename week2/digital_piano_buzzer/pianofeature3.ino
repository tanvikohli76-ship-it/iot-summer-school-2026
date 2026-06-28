/*
  Author: Tanvi Kohli
  Date: 2026-06-27
  Description: digital piano buzzer with feature 3
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

  bool btn1 = !digitalRead(b1);
  bool btn2 = !digitalRead(b2);
  bool btn3 = !digitalRead(b3);
  bool btn4 = !digitalRead(b4);

  int count = btn1 + btn2 + btn3 + btn4;

  if (count >= 2) {
    tone(buzzer, 392); // ✅ Sol
  }
  else if (btn1) {
    tone(buzzer, 262);
  }
  else if (btn2) {
    tone(buzzer, 294);
  }
  else if (btn3) {
    tone(buzzer, 330);
  }
  else if (btn4) {
    tone(buzzer, 349);
  }
  else {
    noTone(buzzer);
  }

}

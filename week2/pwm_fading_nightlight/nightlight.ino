/*
  Author: Tanvi Kohli
  Date: 2026-06-27
  Description: pwm fading night light using ldr
*/
int led = 9;
int button = 2;

int mode = 0; // 0 = slow, 1 = fast, 2 = SOS

bool lastState = HIGH;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Mode 1: Slow Breathing");
}

void loop() {

  // MODE SWITCH
  bool current = digitalRead(button);

  if (lastState == HIGH && current == LOW) {
    mode = (mode + 1) % 3;

    if (mode == 0) Serial.println("Mode 1: Slow Breathing");
    else if (mode == 1) Serial.println("Mode 2: Fast Pulse");
    else Serial.println("Mode 3: SOS");

    delay(200); // debounce
  }

  lastState = current;

  //  MODES
  if (mode == 0) {
    slowBreathing();
  }
  else if (mode == 1) {
    fastPulse();
  }
  else {
    sosPattern();
  }
}

////////////////////////////////////////////////////

//  MODE 1: SLOW BREATHING (~3 sec cycle)
void slowBreathing() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(led, i);
    delay(6); // smooth fade
    if (checkButton()) return;
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(led, i);
    delay(6);
    if (checkButton()) return;
  }
}

////////////////////////////////////////////////////

//  MODE 2: FAST PULSE (~0.5 sec)
void fastPulse() {
  analogWrite(led, 255);
  delay(250);
  if (checkButton()) return;

  analogWrite(led, 0);
  delay(250);
  if (checkButton()) return;
}

////////////////////////////////////////////////////

//  MODE 3: SOS (... --- ...)
void sosPattern() {

  for (int i = 0; i < 3; i++) { // ...
    blinkShort();
    if (checkButton()) return;
  }

  for (int i = 0; i < 3; i++) { // ---
    blinkLong();
    if (checkButton()) return;
  }

  for (int i = 0; i < 3; i++) { // ...
    blinkShort();
    if (checkButton()) return;
  }

  delay(1000);
}

////////////////////////////////////////////////////

// Helper functions

void blinkShort() {
  analogWrite(led, 255);
  delay(200);
  analogWrite(led, 0);
  delay(200);
}

void blinkLong() {
  analogWrite(led, 255);
  delay(600);
  analogWrite(led, 0);
  delay(200);
}

//  Check button during patterns
bool checkButton() {
  bool current = digitalRead(button);

  if (lastState == HIGH && current == LOW) {
    mode = (mode + 1) % 3;

    if (mode == 0) Serial.println("Mode 1: Slow Breathing");
    else if (mode == 1) Serial.println("Mode 2: Fast Pulse");
    else Serial.println("Mode 3: SOS");

    delay(200);
    lastState = current;
    return true;
  }

  lastState = current;
  return false;
}

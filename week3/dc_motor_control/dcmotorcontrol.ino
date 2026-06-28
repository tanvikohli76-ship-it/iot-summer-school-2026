/*
  Author: Tanvi Kohli
  Date: 2026-06-27
  Description: dc motor control
*/
int potPin = A0;

int enA = 9;
int in1 = 8;
int in2 = 7;

int dirButton = 2;
int startButton = 3;

bool direction = true;
bool running = false;

int lastDirState = LOW;
int lastStartState = LOW;

void setup() {
  Serial.begin(9600);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(dirButton, INPUT);
  pinMode(startButton, INPUT);
}

void loop() {

  int dirState = digitalRead(dirButton);
  int startState = digitalRead(startButton);

  // Direction toggle
  if (dirState == HIGH && lastDirState == LOW) {
    direction = !direction;
    delay(200);
  }

  // Start/Stop toggle
  if (startState == HIGH && lastStartState == LOW) {
    running = !running;
    delay(200);
  }

  lastDirState = dirState;
  lastStartState = startState;

  int potValue = analogRead(potPin);
  int speedPWM = map(potValue, 0, 1023, 0, 255);
  int speedPercent = map(speedPWM, 0, 255, 0, 100);

  if (running) {
    analogWrite(enA, speedPWM);

    if (direction) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    } else {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    }
  } else {
    analogWrite(enA, 0);
  }

  Serial.print("State: ");
  Serial.print(running ? "ON" : "OFF");

  Serial.print(" | Direction: ");
  Serial.print(direction ? "Forward" : "Reverse");

  Serial.print(" | Speed: ");
  Serial.print(speedPercent);
  Serial.println("%");

  delay(500);
}

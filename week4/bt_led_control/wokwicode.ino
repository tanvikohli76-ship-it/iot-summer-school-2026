/*
  Author: Tanvi Kohli
  Date: 2026-06-28
  Description: Bluetooth led controller
*/
char command;

int redLED = 6;
int greenLED = 7;
int blueLED = 8;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  Serial.begin(9600);
  Serial.println("Ready");
}

void loop() {
  if (Serial.available()) {
    command = Serial.read();

    if (command == 'R') {
      digitalWrite(redLED, HIGH);
    }
    else if (command == 'G') {
      digitalWrite(greenLED, HIGH);
    }
    else if (command == 'B') {
      digitalWrite(blueLED, HIGH);
    }
    else if (command == 'X') {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(blueLED, LOW);
    }
    else if (command == 'F') {
      for (int i = 0; i < 5; i++) {
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, HIGH);
        digitalWrite(blueLED, HIGH);
        delay(300);

        digitalWrite(redLED, LOW);
        digitalWrite(greenLED, LOW);
        digitalWrite(blueLED, LOW);
        delay(300);
      }
    }
  }
}

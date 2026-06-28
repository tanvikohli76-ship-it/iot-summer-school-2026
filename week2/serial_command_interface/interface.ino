String command = "";
int ledPin = 13;

int blinkCount = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ready for commands...");
}

void loop() {

  //  Read serial input
  if (Serial.available()) {
    command = Serial.readStringUntil('\n');
    command.trim(); // remove spaces/newline

    //  LED ON
    if (command == "LED_ON") {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED is ON");
    }

    //  LED OFF
    else if (command == "LED_OFF") {
      digitalWrite(ledPin, LOW);
      Serial.println("LED is OFF");
    }

    
    else if (command.startsWith("BLINK_")) {

      if (command.length() == 7) {
        int x = command.charAt(6) - '0';

        if (x >= 1 && x <= 9) {
          blinkCount = x;

          for (int i = 0; i < x; i++) {
            digitalWrite(ledPin, HIGH);
            delay(300);
            digitalWrite(ledPin, LOW);
            delay(300);
          }

          Serial.print("Blinked ");
          Serial.print(x);
          Serial.println(" times");
        } else {
          Serial.println("ERROR: Invalid number (1-9 only)");
        }

      } else {
        Serial.println("ERROR: Invalid BLINK format");
      }
    }

    else if (command == "STATUS") {
      Serial.print("LED State: ");
      Serial.println(digitalRead(ledPin) ? "ON" : "OFF");

      Serial.print("Last Blink Count: ");
      Serial.println(blinkCount);
    }


    else if (command == "RESET") {
      blinkCount = 0;
      Serial.println("Blink counter reset");
    }


    else {
      Serial.println("ERROR: Unknown command");
    }
  }
}

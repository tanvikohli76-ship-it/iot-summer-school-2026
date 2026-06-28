/*
  Author: Tanvi Kohli
  Date: 2026-06-27
  Description: ultrasonic parking sensor
*/
#define TRIG_PIN 2
#define ECHO_PIN 3

#define RED_LED 8
#define YELLOW_LED 9
#define GREEN_LED 10
#define BUZZER 11

long duration;
float distance;

unsigned long previousMillis = 0;
bool buzzerOn = false;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Trigger ultrasonic pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo
  duration = pulseIn(ECHO_PIN, HIGH);

  // Distance formula
  distance = (duration * 0.034) / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  unsigned long currentMillis = millis();

  // Turn OFF all LEDs initially
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  //  SAFE
  if (distance > 50) {
    Serial.println("SAFE");
    digitalWrite(GREEN_LED, HIGH);
    noTone(BUZZER);
  }

  //  20–50 cm
  else if (distance > 20 && distance <= 50) {
    digitalWrite(YELLOW_LED, HIGH);

    if (currentMillis - previousMillis >= 500) {
      previousMillis = currentMillis;
      buzzerOn = !buzzerOn;

      if (buzzerOn)
        tone(BUZZER, 1000);
      else
        noTone(BUZZER);
    }
  }

  //  10–20 cm
  else if (distance > 10 && distance <= 20) {
    digitalWrite(RED_LED, HIGH);

    if (currentMillis - previousMillis >= 200) {
      previousMillis = currentMillis;
      buzzerOn = !buzzerOn;

      if (buzzerOn)
        tone(BUZZER, 1500);
      else
        noTone(BUZZER);
    }
  }

  //  <10 cm
  else {
    if (currentMillis - previousMillis >= 100) {
      previousMillis = currentMillis;
      buzzerOn = !buzzerOn;

      digitalWrite(RED_LED, buzzerOn);
      digitalWrite(YELLOW_LED, buzzerOn);
      digitalWrite(GREEN_LED, buzzerOn);

      tone(BUZZER, 2000); // continuous sound
    }
  }
}

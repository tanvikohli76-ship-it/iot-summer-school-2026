const int redLED = 10;
const int yellowLED = 9;
const int greenLED = 8;
const int buttonPin = 7;

const unsigned long RED_TIME = 5000;
const unsigned long YELLOW_TIME = 2000;
const unsigned long GREEN_TIME = 4000;
const unsigned long PEDESTRIAN_TIME = 8000;

enum State {RED, YELLOW, GREEN};
State currentState = RED;

unsigned long previousMillis = 0;
bool pedestrianRequest = false;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);

  digitalWrite(redLED, HIGH);
  previousMillis = millis();
  Serial.println("RED");
}

void loop() {
  unsigned long currentMillis = millis();

  if (digitalRead(buttonPin) == LOW) {
    pedestrianRequest = true;
  }

  if (pedestrianRequest) {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);

    Serial.print("Time: ");
    Serial.print(millis());
    Serial.println(" | PEDESTRIAN RED");

    delay(8000);
    pedestrianRequest = false;

    currentState = GREEN;
    previousMillis = millis();
  }

switch (currentState) {

  case RED:
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);

    if (currentMillis - previousMillis >= RED_TIME) {
      currentState = YELLOW;   // FIX: go to YELLOW next
      previousMillis = currentMillis;
    }
    break;

  case YELLOW:
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);

    if (currentMillis - previousMillis >= YELLOW_TIME) {
      currentState = GREEN;   // then GREEN
      previousMillis = currentMillis;
    }
    break;

  case GREEN:
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);

    if (currentMillis - previousMillis >= GREEN_TIME) {
      currentState = RED;   // back to RED
      previousMillis = currentMillis;
    }
    break;
}
}
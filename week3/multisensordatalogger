#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22   
#define LDR_PIN A0
#define TRIG_PIN 2
#define ECHO_PIN 3

DHT dht(DHTPIN, DHTTYPE);

unsigned long previousMillis = 0;
const long interval = 5000;

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    //  Read DHT
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    //  Read LDR
    int ldrRaw = analogRead(LDR_PIN);
    int lightPercent = map(ldrRaw, 0, 1023, 0, 100);

    String lightStatus = (lightPercent > 50) ? "Bright" : "Dark";

    //  Ultrasonic
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = (duration * 0.034) / 2;

    //  OUTPUT FORMAT
    Serial.println("=== SENSOR LOG ===");

    Serial.print("Time      : ");
    Serial.print(currentMillis);
    Serial.println(" ms");

    Serial.print("Temp      : ");
    Serial.print(temp);
    Serial.print(" C | Humidity: ");
    Serial.print(hum);
    Serial.println("%");

    Serial.print("Light     : ");
    Serial.print(lightPercent);
    Serial.print("% (");
    Serial.print(lightStatus);
    Serial.println(")");

    Serial.print("Distance  : ");
    Serial.print(distance);
    Serial.println(" cm");

    Serial.println("==================");
  }
}

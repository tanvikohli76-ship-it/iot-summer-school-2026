#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT22   // <-- CHANGED HERE
DHT dht(DHTPIN, DHTTYPE);
int redLED = 8;
int greenLED = 9;
void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  Serial.println("timestamp,temp_C,temp_F,humidity");
}
void loop() {
  delay(2000);

  float tempC = dht.readTemperature();
  float tempF = dht.readTemperature(true);
  float humidity = dht.readHumidity();
  if (isnan(tempC) || isnan(humidity)) {
    Serial.println("Sensor error");
    return;
  }
  unsigned long time = millis();
  // CSV format
  Serial.print(time);
  Serial.print(",");
  Serial.print(tempC);
  Serial.print(",");
  Serial.print(tempF);
  Serial.print(",");
  Serial.println(humidity);
  // LED logic
  if (tempC > 35 || humidity > 80) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }
}

/*
  Author: Tanvi Kohli
  Date: 2026-06-27
  Description: replay ac device
*/
#include <DHT.h>

// ===== PIN SETUP =====
#define DHTPIN 2
#define DHTTYPE DHT22

#define RELAY_PIN 8
#define BUTTON_PIN 7

// ===== OBJECT =====
DHT dht(DHTPIN, DHTTYPE);

// ===== VARIABLES =====
bool relayState = false;
bool manualOverride = false;
bool lastButtonState = HIGH;

// ===== SETUP =====
void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  dht.begin();

  digitalWrite(RELAY_PIN, LOW); // Relay OFF initially
}

// ===== LOOP =====
void loop() {

  //  Read Temperature
  float temp = dht.readTemperature();

  //  Fix invalid readings (-1.05 issue)
  if (isnan(temp) || temp < 0) {
    Serial.println(" Error reading temperature!");
    delay(1000);
    return;
  }

  //  Button Toggle (Manual Override)
  bool currentButtonState = digitalRead(BUTTON_PIN);

  if (currentButtonState == LOW && lastButtonState == HIGH) {
    manualOverride = !manualOverride;
    relayState = !relayState;

    Serial.println("🔘 Manual Override Toggled");
    delay(200); // debounce
  }

  lastButtonState = currentButtonState;

  //  AUTOMATIC CONTROL (HYSTERESIS)
  if (!manualOverride) {

    if (temp > 32 && relayState == false) {
      relayState = true;
      Serial.println(" AC ON (Temp > 32°C)");
    }

    else if (temp < 28 && relayState == true) {
      relayState = false;
      Serial.println(" AC OFF (Temp < 28°C)");
    }
  }

  //  APPLY RELAY STATE
  digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);

  //  DEBUG OUTPUT (VERY IMPORTANT)
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" °C | Relay: ");
  Serial.print(relayState ? "ON" : "OFF");
  Serial.print(" | Mode: ");
  Serial.print(manualOverride ? "MANUAL" : "AUTO");
  Serial.print(" | Zone: ");

  if (temp > 32) Serial.print("ON Zone");
  else if (temp < 28) Serial.print("OFF Zone");
  else Serial.print("Stable");

  Serial.println();

  delay(1000);
}

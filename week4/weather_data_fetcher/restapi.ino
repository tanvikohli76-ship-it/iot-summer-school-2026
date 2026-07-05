/* Author- Tanvi Kohli
Date- 05-07-2026
Description- Weather data fetcher using ESP32, DHT22 and OpenWeatherAPI */

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
#include "config.h"

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    String url = "http://api.openweathermap.org/data/2.5/weather?q=" 
                 + String(CITY) + "&appid=" + String(API_KEY) + "&units=metric";

    http.begin(url);
    int httpCode = http.GET();

    if (httpCode == 200) {
      String payload = http.getString();

      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);

      String cityName = doc["name"];
      float apiTemp = doc["main"]["temp"];
      int apiHumidity = doc["main"]["humidity"];
      String weatherDesc = doc["weather"][0]["description"];

      float localTemp = dht.readTemperature();
      float localHumidity = dht.readHumidity();

      Serial.println("----- WEATHER DATA -----");
      Serial.println("City: " + cityName);

      Serial.print("API Temp: ");
      Serial.println(apiTemp);

      Serial.print("DHT Temp: ");
      Serial.println(localTemp);

      Serial.print("Temp Difference: ");
      Serial.println(apiTemp - localTemp);

      Serial.print("API Humidity: ");
      Serial.println(apiHumidity);

      Serial.print("DHT Humidity: ");
      Serial.println(localHumidity);

      Serial.print("Humidity Difference: ");
      Serial.println(apiHumidity - localHumidity);

      Serial.print("Weather: ");
      Serial.println(weatherDesc);

      Serial.println("------------------------");
    } 
    else {
      Serial.println("Error fetching data");
    }

    http.end();
  }

  delay(10000);
}

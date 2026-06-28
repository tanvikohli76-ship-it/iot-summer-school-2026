#include <WiFi.h>
#include <PubSubClient.h>
#include <DHTesp.h>

// WiFi Credentials (Wokwi)
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// MQTT Broker
const char* mqtt_server = "broker.hivemq.com";

// Topics (CHANGE NAME IF NEEDED)
const char* temp_topic = "iitjammu/summer26/tanvi/temperature";
const char* hum_topic  = "iitjammu/summer26/tanvi/humidity";
const char* led_topic  = "iitjammu/summer26/tanvi/led_control";

// Pins
#define DHT_PIN 15
#define LED_PIN 2

WiFiClient espClient;
PubSubClient client(espClient);
DHTesp dht;

unsigned long lastMsg = 0;

// 🔹 WiFi Setup (WITH DEBUG)
void setup_wifi() {
  Serial.print("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
}

// 🔹 MQTT Callback (LED Control)
void callback(char* topic, byte* payload, unsigned int length) {
  String msg = "";

  for (int i = 0; i < length; i++) {
    msg += (char)payload[i];
  }

  Serial.print("Message received: ");
  Serial.println(msg);

  if (String(topic) == led_topic) {
    if (msg == "ON") {
      digitalWrite(LED_PIN, HIGH);
      Serial.println("LED ON");
    } else if (msg == "OFF") {
      digitalWrite(LED_PIN, LOW);
      Serial.println("LED OFF");
    }
  }
}

//  MQTT Reconnect (WITH DEBUG)
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");

    if (client.connect("wokwi-client")) {
      Serial.println("connected!");
      client.subscribe(led_topic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying...");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  dht.setup(DHT_PIN, DHTesp::DHT22);

  setup_wifi();

  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  if (millis() - lastMsg > 5000) {
    lastMsg = millis();

    float temp = dht.getTemperature();
    float hum  = dht.getHumidity();

    long ts = millis();

    String tempJson = "{\"value\": " + String(temp) + ", \"unit\": \"C\", \"ts\": " + String(ts) + "}";
    String humJson  = "{\"value\": " + String(hum)  + ", \"unit\": \"%\", \"ts\": " + String(ts) + "}";

    Serial.println("Publishing data...");
    Serial.println(tempJson);
    Serial.println(humJson);

    client.publish(temp_topic, tempJson.c_str());
    client.publish(hum_topic, humJson.c_str());
  }
}

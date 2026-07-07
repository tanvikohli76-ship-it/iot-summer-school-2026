## Smart City IoT Proposal for Jammu

Introduction

Jammu is one of the fastest-growing cities in Jammu and Kashmir. 
With increasing population, traffic, and infrastructure requirements, efficient management of city resources has become important. 
Internet of Things (IoT) technology can help city authorities collect real-time data and improve public services. 
This proposal presents three IoT-based solutions for the Jammu Smart City project: Smart Street Lighting, Smart Parking Availability, and Air Quality Monitoring. 
These systems are designed to improve energy efficiency, reduce traffic congestion, and support environmental monitoring.

---

1. Smart Street Lighting System

Objective

To reduce electricity consumption and improve public safety by automatically controlling streetlights based on ambient light and movement.

Sensors Required

- LDR (Light Dependent Resistor) Sensor
- PIR (Passive Infrared) Motion Sensor

Microcontroller / Connectivity Module

- ESP32 with built-in Wi-Fi

Data Flow

LDR/PIR Sensor → MQTT Protocol → Cloud Server → Smart City Dashboard

Working

The LDR sensor detects the surrounding light level. When it becomes dark, the system activates the streetlights. The PIR sensor detects movement of pedestrians or vehicles. If motion is detected, the streetlight brightness can be increased automatically. This approach helps save electricity while maintaining safety.

Estimated Cost Per Node

Component| Approximate Cost (INR)
ESP32| ₹500
LDR Sensor| ₹50
PIR Sensor| ₹150
Relay Module| ₹100
Miscellaneous Components| ₹200
Total| ₹1000

Code-

// Smart Street Lighting System
// ESP32 + LDR + PIR

#define LDR_PIN 34

#define PIR_PIN 27

#define LIGHT_PIN 2

void setup() {

  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  
  pinMode(LIGHT_PIN, OUTPUT);
}

void loop() {

  int ldrValue = analogRead(LDR_PIN);
  
  int motion = digitalRead(PIR_PIN);

  Serial.print("LDR Value: ");
  
  Serial.println(ldrValue);

  // Low value means darkness
  
  if (ldrValue < 1000) {

    if (motion == HIGH) {
    
      digitalWrite(LIGHT_PIN, HIGH);
      
      Serial.println("Motion Detected - Street Light ON");
    }
    else {
    
      digitalWrite(LIGHT_PIN, LOW);
      
      Serial.println("No Motion - Street Light OFF");
    }

  } else {

    digitalWrite(LIGHT_PIN, LOW);
    
    Serial.println("Day Time - Street Light OFF");

  }

  delay(1000);
}

---

2. Smart Parking Availability System

Objective

To provide real-time information about available parking spaces and reduce traffic caused by vehicles searching for parking.

Sensors Required

- Ultrasonic Sensor (HC-SR04)

Microcontroller / Connectivity Module

- NodeMCU (ESP8266) with Wi-Fi

Data Flow

Ultrasonic Sensor → HTTP/MQTT Protocol → Cloud Database → Parking Dashboard/Mobile Application

Working

The ultrasonic sensor measures the distance between the sensor and a vehicle.
If the distance is below a predefined threshold, the parking slot is marked as occupied. 
The information is uploaded to the cloud and displayed on a dashboard or mobile application, allowing drivers to locate free parking spaces quickly.

Estimated Cost Per Node

Component| Approximate Cost (INR)
NodeMCU (ESP8266)| ₹350
Ultrasonic Sensor| ₹100
Power Supply| ₹150
Miscellaneous Components| ₹100
Total| ₹700

Code- 

// Smart Parking Availability System
// NodeMCU (ESP8266) + HC-SR04

#define TRIG_PIN 5

#define ECHO_PIN 18

void setup() {

  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  
  pinMode(ECHO_PIN, INPUT);
}

void loop() {

  digitalWrite(TRIG_PIN, LOW);
  
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  
  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  
  Serial.print(distance);
  
  Serial.println(" cm");

  if (distance < 10) {
  
    Serial.println("Parking Slot Occupied");
    
  } else {
  
    Serial.println("Parking Slot Available");
  }

  delay(1000);
  
}

---

3. Air Quality Monitoring System

Objective

To monitor pollution levels and environmental conditions in different parts of the city.

Sensors Required

- MQ135 Gas Sensor
- DHT11 Temperature and Humidity Sensor

Microcontroller / Connectivity Module

- ESP32 with Wi-Fi

Data Flow

MQ135 + DHT11 Sensors → MQTT Protocol → Cloud Platform → Air Quality Dashboard

Working

The MQ2 sensor detects harmful gases and pollutants present in the atmosphere, while the DHT22 sensor measures temperature and humidity. 
The collected data is transmitted to the cloud where it can be analyzed and displayed on a dashboard. 
Authorities can use this information to identify pollution hotspots and take corrective measures.

Estimated Cost Per Node

Component| Approximate Cost (INR)
ESP32| ₹500
MQ2 Sensor| ₹250
DHT22 Sensor| ₹100
Power Supply| ₹150
Miscellaneous Components| ₹200
Total| ₹1200

Code-

#include <DHT.h>

// Air Quality Monitoring System
#include <DHT.h>

// MQ2 + DHT11 Air Quality System

#define MQ2_PIN 34
#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  int gasValue = analogRead(MQ2_PIN);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.println("------ Air Quality Data ------");

  Serial.print("Gas Level (MQ2): ");
  Serial.println(gasValue);

  // Simple condition (you can adjust threshold)
  if (gasValue > 1500) {
    Serial.println("⚠️ Poor Air Quality / Gas Detected!");
  } else {
    Serial.println("✅ Air Quality Normal");
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println("------------------------------");

  delay(2000);
}



The proposed IoT-based Smart City solution for Jammu focuses on three important areas: street lighting, parking management, and air quality monitoring. 
The Smart Street Lighting System helps reduce electricity consumption while improving safety. 
The Smart Parking System minimizes traffic congestion and improves parking efficiency. 
The Air Quality Monitoring System provides real-time environmental data to support public health and urban planning.

These systems use affordable sensors, reliable microcontrollers, and cloud-based dashboards to provide continuous monitoring and management. 
The collected data enables city administrators to make informed decisions and improve public services.
In the future, these solutions can be integrated with other smart city applications such as traffic management, waste management, and water distribution systems.
Therefore, the proposed IoT architecture is a practical, scalable, and cost-effective solution for the Jammu Smart City initiative.

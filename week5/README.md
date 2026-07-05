## IoT-Based Indoor Air Quality Monitoring System

📍 Project Overview

This project is designed to monitor indoor air quality in a home environment (e.g., during winter heating using wood). It detects harmful gas/smoke levels and environmental conditions, then alerts residents using visual and audio indicators.

The system works offline (no internet required) and provides real-time monitoring and alerts.

🎯 Objectives

Monitor gas/smoke levels using MQ-2 sensor
Measure temperature and humidity using DHT11
Indicate air quality using RGB LED
Provide buzzer alerts based on severity
Log data in CSV format via Serial Monitor
Operate without internet connectivity

🧰 Components Used

ESP32 / Arduino board
MQ-2 Gas Sensor
DHT11 Temperature & Humidity Sensor
RGB LED (Red, Green, Blue pins)
Buzzer
Resistors (for LED)
Jumper wires

⚙️ System Functionality

1. Gas Detection (MQ-2)
Reads analog values from MQ-2 sensor
Determines air quality levels:
SAFE
MODERATE
DANGER

3. Temperature & Humidity (DHT11)
Measures:
Temperature (°C)
Humidity (%)

5. Alert System
🌈 RGB LED Indicators
Condition	LED Color
SAFE	Green
MODERATE	Yellow
DANGER	Red

🔊 Buzzer Alerts
Condition	Sound Pattern
SAFE	No sound
MODERATE	Slow beep
DANGER	Fast beep
7. Serial Monitor Logging (CSV Format)

Data is logged as:

Timestamp, MQ-2 Value, Temperature (°C), Humidity (%), Status

00:01, 220, 23.4, 49, SAFE

00:02, 420, 23.6, 50, MODERATE

00:03, 710, 23.8, 48, DANGER

🔌 Pin Configuration (Example)

Component	Pin
MQ-2	A0
DHT11	D4
Green LED	D16
Yellow LED	D17
Red LED	D18
Buzzer	D19

🧠 Threshold Logic

MQ-2 Value	Condition

< 300	SAFE

300–600	MODERATE

> 600	DANGER

(Values may vary depending on calibration)

💻 How to Run

Connect all components correctly
Upload the code to ESP32/Arduino
Open Serial Monitor
Observe:
Live sensor values
CSV data output
LED and buzzer alerts

⚠️ Notes
MQ-2 sensor requires calibration for accurate readings
System works without WiFi or Internet
Bluetooth is not supported in simulation (Wokwi)

Wokwi link: https://wokwi.com/projects/468692807982941185

Simulation video link: https://drive.google.com/file/d/1yVYqG_h9uMiJW1YGWexxervO4Mir9EU3/view?usp=drive_link

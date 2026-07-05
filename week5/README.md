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

## Smart Door Lock System with OTP (ESP32 + Keypad + LCD + Servo)

📌 Project Overview

This project is an IoT-based Smart Door Lock System that replaces traditional keys with a secure OTP-based authentication mechanism. It is built using an ESP32 microcontroller and simulates a real-world secure access system using a keypad, LCD display, and servo motor.

The system generates a 6-digit OTP after a 4-digit user ID is entered, displays it via Serial Monitor, and grants access only if the correct OTP is entered within a 30-second time window.

⚙️ Features

🔢 4-digit user ID input via 4x4 keypad
🔐 6-digit OTP generation (randomized)
⏱️ 30-second OTP validity timer (millis-based, non-blocking)
📺 16x2 I2C LCD display for user prompts and masked input
🔄 Servo motor simulation for door locking/unlocking
📊 Serial Monitor logging for all access attempts
🚫 OTP expiry protection
🧠 Secure two-step authentication system
🧰 Components Used
Component	Description

ESP32 Dev Board	Main microcontroller
4x4 Keypad	User input (ID & OTP)
16x2 LCD (I2C)	Display interface
Servo Motor (SG90)	Simulates door lock
Wokwi Simulator	Virtual testing platform
🔌 Pin Configuration

Keypad → ESP32
Keypad	ESP32
R1	13
R2	12
R3	14
R4	27
C1	26
C2	25
C3	33
C4	32
Servo Motor

| Signal | ESP32 GPIO 18 |
| VCC | 5V |
| GND | GND |

LCD (I2C)

| SDA | GPIO 21 |
| SCL | GPIO 22 |
| VCC | 3.3V |
| GND | GND |

🧠 Working Principle

User enters a 4-digit ID using the keypad
System generates a random 6-digit OTP
OTP is displayed in Serial Monitor
User enters OTP using keypad
System validates OTP within 30 seconds
If correct → Servo rotates to unlock door (90°)
If incorrect/timeout → Access denied

🔁 System Flow

START
  ↓
Enter 4-digit ID
  ↓
Generate OTP
  ↓
Display OTP (Serial Monitor)
  ↓
Enter OTP via keypad
  ↓
Check timer (30 sec)
  ↓
Correct OTP?
  ├── YES → Unlock door (Servo 90°)
  └── NO  → Access Denied / Expired
  
💻 How to Run in Wokwi

Open https://wokwi.com
Create a new ESP32 project
Add components:
ESP32 Dev Kit
4x4 Keypad
16x2 LCD (I2C)
Servo Motor
Paste the code into main.ino
Run simulation
Open Serial Monitor

📺 Output Example

System Ready
ID Entered: 1234
OTP GENERATED: 582913
Enter OTP:
ACCESS GRANTED
Door Unlocked

Wokwi Link- https://wokwi.com/projects/468702046367308801

Simulation Video Link- https://drive.google.com/file/d/1HDwC1G7ZCqKF-udJhk6ggLTsmMhKaEQs/view?usp=drive_link

## PIR-Based Smart Security Alert System (ESP32)

📌 Overview

This project is a Smart Security Alert System built using the ESP32 microcontroller and a PIR motion sensor. It detects motion and triggers a multi-level alert system using LEDs and a buzzer.

The system is designed to simulate a real-world intrusion detection setup with time-based activation and alert escalation.

🎯 Features
✅ Motion detection using PIR sensor
✅ Multi-stage alert system (Green → Yellow → Red)
✅ Buzzer with increasing intensity (PWM-based sound)
✅ Time-window based activation
✅ Serial monitor logging for debugging and demo
✅ Cooldown mechanism to prevent repeated triggering

🧰 Components Used
ESP32
PIR Motion Sensor
Buzzer (active/passive)
3 LEDs (Green, Yellow, Red)
Resistors (for LEDs)
Jumper wires

🔌 Pin Configuration
Component	ESP32 Pin
PIR Sensor	27
Buzzer	25
Green LED	18
Yellow LED	19
Red LED	21

⚙️ Working Principle
The PIR sensor continuously monitors motion.
When motion is detected:
System checks if it is within the active time window.
If valid, it triggers the alert system.
Alert system behavior:
🟢 Green LED + short beep
🟡 Yellow LED + medium beep
🔴 Red LED + long beep
A cooldown of 3 seconds prevents repeated triggering.
All events are logged in the Serial Monitor.

⏰ Time Window Feature

You can restrict system activity using Serial Monitor commands:

SET_HOURS start end
Example:
SET_HOURS 22 6

➡ System will only activate between 10 PM and 6 AM

If not set, the system runs 24/7 by default.

🔊 Buzzer Implementation
Uses ESP32 PWM (LEDC) for sound generation
Different frequencies simulate alert escalation
Ensures proper sound even in simulation (Wokwi)

🖥️ How to Run
▶️ On Wokwi
Create ESP32 project
Add components (PIR, LEDs, buzzer)
Connect pins as per table
Paste the code
Run simulation

▶️ On Hardware
Connect components properly
Upload code via Arduino IDE
Open Serial Monitor (115200 baud)
Test by moving in front of PIR sensor
📊 Serial Output Example
PIR Security System Ready

Motion Event Logged
MOTION DETECTED
Alert Completed

Wokwi link- https://wokwi.com/projects/468703883110848513

Simulation Video Link- https://drive.google.com/file/d/1WcLLKi0jyxia1ZWjbGTljJVKJk1fD_ms/view?usp=sharing

## Smart Greenhouse Controller (ESP32 + MQTT + LCD)

📌 Overview

This project is an IoT-based Smart Greenhouse Controller designed for floriculture applications (e.g., tulips and roses in Kashmir). It monitors and maintains optimal environmental conditions using sensors and automated control.

The system ensures:

🌡 Temperature: 18–22°C
💧 Humidity: 60–70%
☀️ Light: 12 hours/day

It provides:

📟 Local display (LCD + Serial Monitor)
🌐 Remote monitoring via MQTT cloud

🎯 Features
✅ DHT11 for temperature & humidity monitoring
✅ LDR with running average (10 samples) for light detection
✅ 3 outputs (Heater, Fan, Grow Light) using LEDs
✅ Bang-bang control with hysteresis (PID-like)
✅ 16x2 I2C LCD (auto cycles every 3 sec)
✅ Serial Monitor output (clean formatted data)
✅ MQTT publishing to cloud dashboard
✅ Stable, non-spamming data transmission

🧰 Components Used
ESP32
DHT11 Sensor
LDR + Resistor
16x2 I2C LCD
3 LEDs (simulate relays)
Jumper wires

🔌 Pin Configuration
Component	ESP32 Pin
DHT11 DATA	4
LDR	34
Heater (LED)	25
Fan (LED)	26
Grow Light	27
LCD SDA	21
LCD SCL	22
LCD VCC	5V (VIN)
LCD GND	GND

⚙️ Working Principle
1. Sensor Monitoring
DHT11 reads temperature & humidity
LDR calculates average light intensity
2. Control Logic (Bang-Bang + Hysteresis)
If temperature < 18°C → Heater ON
If temperature > 22°C → Fan ON
If humidity high → Fan ON
If light low → Grow light ON
3. Display System
LCD cycles every 3 seconds:
Temp & Humidity
Light level
System status
5. Data Output
📟 Serial Monitor → Detailed logs
🌐 MQTT → Cloud data publishing

📊 Serial Monitor Output Example
------ GREENHOUSE DATA ------
Temperature: 21.0 °C
Humidity: 65.0 %
Light Avg: 1320
Heater: 0
Fan: 0
Light: 1


🌐 MQTT Cloud Setup
👉 Open:

HiveMQ Web Client

📡 Subscribe to Topics:
greenhouse/temp
greenhouse/humidity
greenhouse/light
greenhouse/heater
greenhouse/fan
greenhouse/lightStatus

➡ You will see live real-time data from ESP32

🖥️ How to Run
▶️ On Wokwi
Create ESP32 project
Add DHT11, LCD, LDR, LEDs
Connect as per pin table
Paste code
Run simulation

▶️ On Hardware
Assemble circuit
Upload code via Arduino IDE
Open Serial Monitor (115200 baud)
Monitor system + MQTT

Wokwi Link- https://wokwi.com/projects/468706499967752193

Simulation video link- https://drive.google.com/file/d/1rTSCtjCIsd-X5yWxSpfohC_7GsdqQ2qX/view?usp=sharing

## River Water Level Alert System (Flood Detection)

An IoT-based Flood Early Warning System using ESP32 and HC-SR04 ultrasonic sensor to monitor water level in real time and trigger alerts.

📌 Project Overview

This project simulates a river flood monitoring system using a water tank. The system continuously measures the distance between the sensor and water surface.

As water level rises → distance decreases
Alerts are triggered based on predefined thresholds
Data is sent to cloud (ThingSpeak) for live visualization

🚨 Alert Levels
Level	Distance (cm)	Indication
🟢 NORMAL	> 30 cm	Green LED
🟡 WARNING	15 – 30 cm	Yellow LED + Beep
🔴 CRITICAL	< 15 cm	Red LED + Continuous Alarm

⚙️ Components Used
ESP32 Microcontroller
HC-SR04 Ultrasonic Sensor
Buzzer
LEDs (Green, Yellow, Red)
Resistors
Breadboard & Jumper Wires

🔌 Circuit Connections
Component	ESP32 Pin
TRIG	GPIO 5
ECHO	GPIO 18
BUZZER	GPIO 4
GREEN LED	GPIO 12
YELLOW LED	GPIO 13
RED LED	GPIO 14

🧠 Working Principle
Ultrasonic sensor measures distance using echo time
Rolling average smooths noisy readings
System classifies water level:
Raw values → fast alert detection
Average → stable data logging
Alerts are triggered using LEDs and buzzer
Data is sent to cloud using HTTP protocol

☁️ Cloud Integration (ThingSpeak)

This project uses ThingSpeak to display real-time graphs.

👉 Setup steps:

Create a channel on
ThingSpeak
Add fields:
Field 1 → Distance
Field 2 → Alert Level (0,1,2)
Copy Write API Key
Replace in code:
String apiKey = "YOUR_API_KEY";

📊 Output
Real-time distance vs time graph
Flood level visualization
Serial monitor debug output

🖥️ Sample Serial Output
Raw: 14 cm | Avg: 16 cm
Level: CRITICAL
HTTP Response: 200

⚠️ Important Notes
ThingSpeak requires 15-second delay between updates
Only numeric data is accepted in fields
Do NOT upload API key in public repositories

🔐 Security Note

API keys should be stored securely and not hardcoded in public repositories. Use a separate secrets.h file and add it to .gitignore.

Wokwi link- https://wokwi.com/projects/468709511884120065

Simulation link- https://drive.google.com/file/d/1RZYX3bD2VQ40-_wSMDrmnGJZRcuvguOa/view?usp=sharing

## Heart Rate & SpO₂ Monitor (Simulation)

📌 Overview

This project is a simulation-based health monitoring system built using an ESP32 and an LDR (Light Dependent Resistor) as a proxy sensor.

It simulates:

Heart Rate (bpm)
Blood Oxygen Saturation (SpO₂ %)

⚠️ Note: This is a learning prototype and not a medical device.

🎯 Features

📟 Real-time monitoring (updates every 2 seconds)
📊 Simulated Heart Rate & SpO₂ values
🔄 5-sample rolling average for noise reduction
🚨 Alert system using Red LED
🧾 Serial output in CSV format for logging
🧪 Fully testable in Wokwi simulator

⚙️ Components Used
ESP32
LDR (Photoresistor)
10kΩ Resistor (voltage divider)
Red LED
220Ω Resistor
Breadboard & jumper wires

🔌 Circuit Connections
LDR (Analog Input)
One side → 3.3V
Other side → GPIO 34
From GPIO 34 → 10kΩ → GND
LED (Alert)
GPIO 14 → 220Ω → LED → GND

🧠 Working Principle
The LDR simulates sensor input based on light intensity
Analog values are smoothed using a 5-reading rolling average
Values are mapped to:
Heart Rate (40–140 bpm)
SpO₂ (88–100%)
The system continuously checks for abnormal conditions

🚨 Alert Logic

The Red LED turns ON when:

Heart Rate < 50 bpm
Heart Rate > 120 bpm
SpO₂ < 94%

Otherwise, the LED remains OFF.

📊 Sample Output (Serial Monitor)
Time,HeartRate,SpO2
2,78,98
4,110,96
6,130,92
🗂️ Data Logging

A sample log file is included:

/data/health_log.csv

Example:

Time,HeartRate,SpO2
2,78,98
4,110,96
6,130,92

🌐 Wokwi Simulation

Run the project online:

👉 Open in Wokwi

Steps:
Create new ESP32 project
Add LDR, resistors, LED
Paste code
Start simulation
Adjust LDR slider to test behavior

🧪 Testing Behavior
Condition	Result
Medium light	✅ Normal (LED OFF)
Very dark	🔴 Low HR / SpO₂ → LED ON
Very bright	🔴 High HR → LED ON

Wokwi Link- https://wokwi.com/projects/468721482543270913

Simulation link- https://drive.google.com/file/d/1HM-F_W0__rR2cmNdSYuVL1755BZcqfTi/view?usp=sharing

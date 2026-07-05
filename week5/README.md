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

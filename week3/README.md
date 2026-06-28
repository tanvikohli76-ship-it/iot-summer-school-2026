## Environmental Monitoring Station (DHT Sensor)

**1. Project Title**

Environmental Monitoring Station using DHT22

**2. Library Used**
**DHT Sensor Library by Adafruit
Version: 1.4.4
Used for reading temperature and humidity data from the DHT sensor*

Note: DHT22 was used in simulation (Wokwi) as a substitute for DHT11. The functionality remains the same.

**3. Hardware Required**
Arduino Uno
DHT22 Temperature & Humidity Sensor
1 × Red LED
1 × Green LED
2 × 220Ω Resistors
Breadboard
Jumper Wires

**4. Circuit Diagram Description**
The DHT22 sensor is connected as follows:
VCC → 5V
GND → GND
DATA → Digital Pin 2
The Red LED is connected to Digital Pin 8 through a 220Ω resistor (for alert condition).
The Green LED is connected to Digital Pin 9 through a 220Ω resistor (for normal condition).
All components share a common ground connection.

**5. Expected Output**
The system reads temperature and humidity every 2 seconds.

Data is displayed on the Serial Monitor in CSV format:

timestamp,temp_C,temp_F,humidity
2000,30.0,86.0,60
4000,32.0,89.6,65
If:
Temperature > 35°C OR Humidity > 80%
→ Red LED turns ON (alert condition)
Otherwise:
→ Green LED turns ON (normal condition)
The system continuously monitors environmental conditions in real time.

Wokwi link: https://wokwi.com/projects/468005215355393025

## Ultrasonic Parking Sensor System (HC-SR04)

**1. Project Title**

Ultrasonic Parking Distance Alert System

**2. Hardware Required**
Arduino Uno
HC-SR04 Ultrasonic Sensor
1 × Red LED
1 × Yellow LED
1 × Green LED (optional for safe indication)
3 × 220Ω Resistors
Buzzer
Breadboard
Jumper Wires

**3. Circuit Diagram Description**
HC-SR04 Connections:
VCC → 5V
GND → GND
TRIG → Pin 2
ECHO → Pin 3
LEDs:
Red LED → Pin 8 (via resistor)
Yellow LED → Pin 9 (via resistor)
Green LED → Pin 10 (via resistor)
Buzzer:
Positive → Pin 11
Negative → GND

**4. Expected Output**
Distance Range	Output
> 50 cm	SAFE message, Green LED ON
20–50 cm	Yellow LED ON, buzzer beeps every 500ms
10–20 cm	Red LED ON, buzzer beeps every 200ms
< 10 cm	All LEDs flash rapidly, buzzer continuous

**- Bonus (Why millis is used?)**
millis() allows non-blocking timing
Unlike delay(), it lets the sensor keep reading continuously
Required for smooth buzzer + LED behavior

Wokwi link: https://wokwi.com/projects/468006979706302465

## Smart Street Light (LDR + PIR)

**1. Project Title**

Smart Street Light Controller using LDR and PIR Sensor

**2.  Hardware Required**
Arduino Uno
LDR (Photoresistor)
PIR Motion Sensor
LED
220Ω Resistor (for LED)
10kΩ Resistor (for LDR voltage divider)
Breadboard
Jumper Wires

**3. Circuit Diagram Description**
The LDR is connected in a voltage divider configuration:
One end → 5V
Other end → A0 and connected to GND via a 10kΩ resistor
The PIR sensor is connected as follows:
VCC → 5V
GND → GND
OUT → Digital Pin 2
The LED is connected to PWM Pin 9 through a 220Ω resistor:
Anode → Pin 9
Cathode → Resistor → GND
All components share a common ground connection

**4. Expected Output**
 Daytime (LDR above threshold)
LED remains OFF

Serial Monitor logs:

[HH:MM:SS] EVENT: Daytime - Light OFF
 Night Mode (LDR below threshold)
System activates motion detection
 Motion Detected at Night
LED turns ON at full brightness (PWM = 255)
Stays ON for 30 seconds

Serial log:

[HH:MM:SS] EVENT: Motion detected - Full brightness
 No Motion After 30 Seconds
LED dims to 20% brightness (PWM ≈ 51)

Serial log:

[HH:MM:SS] EVENT: No motion - Dim light

Tinkercad link:  https://www.tinkercad.com/things/4AxusZpvulW-smart-street-light/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall%3Fpage%3D1%26q%3DSMART

## Multi-Sensor Data Logger (Wokwi)

**1. Project Title**

Multi-Sensor Data Logger using Arduino (DHT11 + LDR + HC-SR04)

**2. Components Required (Wokwi)**
Arduino Uno
DHT11 Temperature & Humidity Sensor
LDR (Light Dependent Resistor)
10kΩ Resistor (for LDR voltage divider)
HC-SR04 Ultrasonic Sensor
Jumper Wires

**3. Circuit Connections**
1. DHT11 Sensor
VCC → 5V
GND → GND
DATA → Digital Pin 2
2. LDR (Light Sensor)
One leg → 5V
Other leg → A0 and 10kΩ resistor
Other end of resistor → GND

Forms a voltage divider

3. HC-SR04 Ultrasonic Sensor
VCC → 5V
GND → GND
TRIG → Pin 9
ECHO → Pin 10

**4. How to Run in Wokwi**
Go to Wokwi Arduino Simulator
Click New Project
Add components:
Arduino Uno
DHT11
LDR
HC-SR04
Make connections as described above
Paste the Arduino code
Click Start Simulation
Open Serial Monitor

**5. Expected Output (Every 5 Seconds)**
=== SENSOR LOG ===
Time      : 12345 ms
Temp      : 28.5 C | Humidity: 65%
Light     : 73% (Bright)
Distance  : 42 cm

Wokwi link: https://wokwi.com/projects/468010989361771521

## Project Title 

## Servo Motor Control with Potentiometer and Button (Tinkercad Simulation)

**1. Hardware Required***
Arduino UNO
SG90 Servo Motor
Potentiometer (10kΩ)
Push Button
10kΩ Resistor (for pull-down)
Breadboard
Jumper Wires

**2. Circuit Diagram Description (Text-Based)**
 Potentiometer
Left pin → 5V
Right pin → GND
Middle pin → A0 (Analog input)
 Servo Motor
Red wire → 5V
Brown wire → GND
Orange wire → Digital Pin 9
 Push Button
One terminal → 5V
Other terminal → Digital Pin 2
10kΩ resistor connected between Pin 2 and GND (pull-down resistor)

**3. Working Principle**
The potentiometer controls the servo angle from 0° to 180°
The button triggers a one-time sweep motion:
Servo moves from 0° → 180° → 0°
After the sweep, control returns to the potentiometer
The current angle is displayed on the Serial Monitor

**4.Expected Output**
Normal Mode:
Rotating the potentiometer changes servo angle smoothly

Serial Monitor displays:

Angle: 45
Angle: 120
Button Press:

Servo performs:

0 → 180 → 0

Serial Monitor displays:

Sweep Angle: 0
Sweep Angle: 90
Sweep Angle: 180

Tinkercad link: https://www.tinkercad.com/things/ieWLaiAgblp-servo-motor-sweep/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall%3Fpage%3D1%26q%3DSERVO

## Project Title

## DC Motor Speed & Direction Control using L298N Driver (Tinkercad)

**1. Hardware Required**
Arduino UNO
L298N Motor Driver
DC Motor
Potentiometer (10kΩ)
2 Push Buttons
10kΩ Resistors (×2 for pull-down)
External Power Supply (Battery 9V or similar for motor)
Breadboard
Jumper Wires

**2. Circuit Diagram Description (Text-Based)** 
L298N Connections
IN1→ Pin 8
IN2 → Pin 7
ENA → Pin 9 (PWM)
Motor → OUT1 & OUT2
12V → External Battery (+)
GND → Battery (-) + Arduino GND (COMMON GND)
Potentiometer
Left → 5V
Right → GND
Middle → A0
 Buttons
Direction Button
One side → 5V
Other side → Pin 2
10kΩ resistor → GND
Start/Stop Button
One side → 5V
Other side → Pin 3
10kΩ resistor → GND

**3.Working Principle**
 Potentiometer controls motor speed (0–100%)
 Button 1 (Pin 2) toggles direction:
Forward ↔ Reverse
 Button 2 (Pin 3) toggles:
Start ↔ Stop
 L298N driver controls motor safely using PWM

 Serial Monitor shows:

State: ON | Direction: Forward | Speed: 65%

**4. Expected Output**
State: ON | Direction: Forward | Speed: 20%
State: ON | Direction: Reverse | Speed: 75%
State: OFF | Direction: Reverse | Speed: 0%

Tinkercad link: https://www.tinkercad.com/things/aJ2SVMqcxfo-dc-motor-control/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall%3Fpage%3D1

## Relay-Controlled AC Device Simulation (DHT11 + Arduino)

 **1. Project Overview**

This project simulates an automatic AC (Air Conditioner) control system using an Arduino, a DHT11 temperature sensor, and a relay module.

The system turns ON the AC when temperature rises above 32°C
It turns OFF when temperature drops below 28°C
A manual override button allows user control
An LED is used to simulate the AC device

**2. Components Used**
Arduino UNO
DHT11 Temperature Sensor
Relay Module
LED (AC simulation)
220Ω Resistor
Push Button
Jumper Wires

**3.Circuit Connections**
 DHT11 Sensor
VCC → 5V
GND → GND
DATA → Pin 2
 Relay Module
VCC → 5V
GND → GND
IN → Pin 8
 LED (Simulated AC via Relay)
Relay COM → 5V
Relay NO → LED (+)
LED (–) → Resistor → GND
 Push Button (Manual Override)
One side → Pin 7
Other side → GND
Uses INPUT_PULLUP
 Working Principle
 Automatic Mode (Default)
If temperature > 32°C → Relay ON (AC ON)
If temperature < 28°C → Relay OFF (AC OFF)

 This gap creates hysteresis, preventing rapid ON/OFF switching.

 Manual Override
Pressing the button toggles:
Manual mode ON/OFF
Relay state manually

**4. Serial Monitor Output**

The system continuously logs:

Current Temperature
Relay State (ON/OFF)
Mode (AUTO/MANUAL)
Temperature Zone
Example:
Temp: 30 °C | Relay: OFF | Mode: AUTO | Zone: Stable
 AC ON (Temp > 32°C)
Temp: 33 °C | Relay: ON | Mode: AUTO | Zone: ON Zone
 AC OFF (Temp < 28°C)
Temp: 27 °C | Relay: OFF | Mode: AUTO | Zone: OFF Zone

Wokwi link: https://wokwi.com/projects/468017814971363329

## Password Protected Access System using Keypad & LCD

**1. Project Title**

Password-Based Access Control System using 4x4 Keypad and 16x2 LCD (Arduino)

**2. Hardware Required**
Arduino Uno
16x2 LCD (Parallel Interface)
10k Potentiometer (for contrast control)
4x4 Membrane Keypad
Green LED
Red LED
Buzzer
Resistors (220Ω for LEDs)
Breadboard
Jumper Wires

**3. Circuit Diagram Description (Text-Based)**
 LCD Connections
VSS → GND
VDD → 5V
VO → Middle pin of potentiometer
RS → Digital Pin 7
RW → GND
E → Digital Pin 6
D4 → Pin 5
D5 → Pin 4
D6 → Pin 3
D7 → Pin 2
A (LED+) → 5V
K (LED−) → GND
 Potentiometer
Left → GND
Right → 5V
Middle → VO (LCD)
 Keypad Connections
Rows → Pins 8, 9, 10, 11
Columns → Pins 12, 13, A0, A1
 LEDs &  Buzzer
Green LED → A2 (via resistor to GND)
Red LED → A3 (via resistor to GND)
Buzzer → A4 (GND to negative)

**4. Expected Output**
LCD displays: "ENTER PIN:"
User enters a 4-digit PIN using keypad
 If correct:
LCD shows "ACCESS GRANTED"
Green LED turns ON
 If incorrect:
LCD shows "ACCESS DENIED"
Red LED turns ON
Buzzer sounds
 After 3 incorrect attempts:
System locks for 10 seconds
LCD shows "LOCKED!"

Wokwi link: https://wokwi.com/projects/468056486921972737

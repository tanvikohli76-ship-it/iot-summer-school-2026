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

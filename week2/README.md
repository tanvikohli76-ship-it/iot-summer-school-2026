## Traffic Light Controller with Pedestrian Override (Arduino)

**1. Project Title**

Traffic Light Controller using Arduino UNO with Pedestrian Button

**2. Hardware Required**
Arduino UNO
Breadboard
3 LEDs (Red, Yellow, Green)
3 Resistors (220Ω)
1 Push Button
Jumper Wires
USB Cable

**4. Circuit Diagram Description (Text-Based)**
Red LED → Connected to Pin 10 through a resistor → GND
Yellow LED → Connected to Pin 9 through a resistor → GND
Green LED → Connected to Pin 8 through a resistor → GND
Push Button → One side to Pin 7, other side to GND
Arduino GND connected to breadboard ground rail
The button uses INPUT_PULLUP, so it reads LOW when pressed

**4. How to Upload Code (Step-by-Step)**
-Connect Arduino UNO to your computer using USB cable
-Open Arduino IDE
-Copy and paste the provided code into a new sketch
-Go to Tools → Board → Arduino UNO
-Go to Tools → Port → Select correct COM port
-Click Verify (✔) to compile the code
-Click Upload (→) to upload the code to Arduino
-Open Serial Monitor (9600 baud rate)

**5. Expected Output**
LEDs follow sequence:
 RED → 5 seconds
 YELLOW → 2 seconds
 GREEN → 4 seconds
Cycle repeats continuously
When button is pressed:
-Immediate switch to RED
-RED stays ON for 8 seconds
-Serial Monitor displays:
-Current light state
-Timestamp using millis()

**6. Troubleshooting Tips**
-LED not glowing?
Check polarity (long leg = positive)
Ensure resistor is connected properly
-Button not working?
Make sure one side is connected to GND
Confirm INPUT_PULLUP is used in code
-Wrong LED sequence?
Verify pin connections (10, 9, 8)
Check code logic for correct order
-Upload error?
Select correct COM port in Arduino IDE
Ensure USB cable is properly connected
-No Serial output?
Check baud rate is set to 9600
Ensure Serial.begin(9600); is present

##  Digital Piano using Buzzer

1. Project Title

Digital Piano with Mode Toggle

2. Hardware Required
Arduino Uno
5 Push Buttons
Passive Buzzer
5 × 220Ω Resistors
Breadboard
Jumper Wires

3. Circuit Diagram Description
Connect 4 push buttons to digital pins (e.g., 2, 3, 4, 5) for notes
Connect 5th button to pin 6 for mode toggle
Connect buzzer to pin 9
Use pull-down resistors for all buttons
Connect all GND and VCC properly

4. Expected Output
Each button plays a musical note (Do, Re, Mi, Fa)
Pressing two buttons together plays Sol (392Hz)
5th button toggles between Major and Minor scale
Sound stops when button is released

Tinkercad link: https://www.tinkercad.com/things/dNnNi8S4l3y-digital-piano-using-buzzer/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall

## Serial Command Interface

1. Project Title

Serial-Controlled LED System

2. Hardware Required
Arduino Uno
Built-in LED (Pin 13)

4. Circuit Diagram Description
No external components required
Uses Arduino’s built-in LED

5. Expected Output
Commands via Serial Monitor control LED behavior:
LED_ON → LED turns ON
LED_OFF → LED turns OFF
BLINK_X → LED blinks X times (1–9)
STATUS → Displays LED state
RESET → Resets blink counter
Invalid commands show: ERROR: Unknown command

Tinkercad link: https://www.tinkercad.com/things/kR8BUDoefqH-serial-command-interface/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall

## PWM Fading Night Light

1. Project Title

Automatic Breathing LED Night Light

2. Hardware Required
Arduino Uno
LED
220Ω Resistor
Push Button
Breadboard
Jumper Wires

3. Circuit Diagram Description
Connect LED to PWM pin (e.g., pin 9)
Connect button to pin 2
Use pull-down resistor for button
Common GND connection

4. Expected Output
LED performs fading (breathing effect)
Button switches between modes:
Slow breathing (~3 seconds cycle)
Fast pulse (~0.5 seconds cycle)
SOS pattern (... --- ...)
Current mode displayed on Serial Monitor

Tinkercad link: https://www.tinkercad.com/things/3LWQc4TijyV-pwm-fading-night-light/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall

## Vending Machine State Machine

1. Project Title

Arduino-Based Vending Machine Simulator

2. Hardware Required
Arduino Uno
3 Push Buttons (Coin, Select, Cancel)
3 LEDs (Red, Yellow, Green)
3 × 220Ω Resistors
Breadboard
Jumper Wires

3. Circuit Diagram Description
Buttons connected to pins (e.g., 2, 3, 4)
LEDs connected to pins (e.g., 8, 9, 10)
Use pull-down resistors for buttons
Each LED represents a state:
Red → IDLE
Yellow → COIN_INSERTED / ITEM_SELECTED
Green → DISPENSING

4. Expected Output
System operates in 4 states:
IDLE
COIN_INSERTED
ITEM_SELECTED
DISPENSING
Button actions control transitions:
Insert Coin → moves to COIN_INSERTED
Select Item → moves to ITEM_SELECTED
Automatic → DISPENSING → IDLE
Cancel → returns to IDLE from any state
Serial Monitor prints all state transitions

Tinkercad link: https://www.tinkercad.com/things/inx1LZhW8bB-state-machine-implementation/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall

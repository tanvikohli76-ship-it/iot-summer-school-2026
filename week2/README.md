Traffic Light Controller with Pedestrian Override (Arduino)
1. Project Title

Traffic Light Controller using Arduino UNO with Pedestrian Button

2. Hardware Required
Arduino UNO
Breadboard
3 LEDs (Red, Yellow, Green)
3 Resistors (220Ω)
1 Push Button
Jumper Wires
USB Cable
3. Circuit Diagram Description (Text-Based)
Red LED → Connected to Pin 10 through a resistor → GND
Yellow LED → Connected to Pin 9 through a resistor → GND
Green LED → Connected to Pin 8 through a resistor → GND
Push Button → One side to Pin 7, other side to GND
Arduino GND connected to breadboard ground rail

 The button uses INPUT_PULLUP, so it reads LOW when pressed

4. How to Upload Code (Step-by-Step)
-Connect Arduino UNO to your computer using USB cable
-Open Arduino IDE
-Copy and paste the provided code into a new sketch
-Go to Tools → Board → Arduino UNO
-Go to Tools → Port → Select correct COM port
-Click Verify (✔) to compile the code
-Click Upload (→) to upload the code to Arduino
-Open Serial Monitor (9600 baud rate)
5. Expected Output
LEDs follow sequence:
🔴 RED → 5 seconds
🟡 YELLOW → 2 seconds
🟢 GREEN → 4 seconds
Cycle repeats continuously
When button is pressed:
-Immediate switch to 🔴 RED
-RED stays ON for 8 seconds
-Serial Monitor displays:
-Current light state
-Timestamp using millis()
6. Troubleshooting Tips
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

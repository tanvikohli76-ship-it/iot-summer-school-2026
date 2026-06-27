## Environmental Monitoring Station (DHT Sensor)

**1. Project Title**

Environmental Monitoring Station using DHT22

**2. Library Used**
DHT Sensor Library by Adafruit
Version: 1.4.4
Used for reading temperature and humidity data from the DHT sensor

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
→ 🟢 Green LED turns ON (normal condition)
The system continuously monitors environmental conditions in real time.

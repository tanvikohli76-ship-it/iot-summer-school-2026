## Bluetooth LED Controller

**HC-05 Working Principle** 

The HC-05 Bluetooth module communicates with Arduino using UART (Serial Communication).

- It receives data wirelessly from a paired device (phone)
- Sends that data to Arduino via TX pin
- Arduino reads it using Serial.read()

Thus, Bluetooth input behaves exactly like Serial input.

**PAIRING INSTRUCTONS**

1. Power the HC-05 module
2. Enable Bluetooth on phone
3. Search for "HC-05"
4. Enter PIN: 1234 or 0000
5. Open Bluetooth Terminal App
6. Connect and send commands: R, G, B, X, F

**Real Hardware Setup (Not Simulated)**

- HC-05 VCC → 5V
- GND → GND
- TX → Arduino RX
- RX → Arduino TX (via voltage divider)

Default PIN: 1234 / 0000

This project is designed for hardware implementation using the HC-05 Bluetooth module.
Due to the lack of physical hardware, the code has not been tested with an actual HC-05 module. However, the logic is based on UART serial communication, which has been verified through Arduino Serial communication.
The HC-05 module works as a wireless serial interface, meaning the same code will function correctly when deployed on real hardware.

When implemented on hardware:

1. The HC-05 pairs with a smartphone via Bluetooth
2. Commands sent from a Bluetooth terminal app are transmitted wirelessly
3. HC-05 receives data and forwards it to Arduino via TX pin
4. Arduino reads the data using Serial.read()
5. LEDs respond based on received commands

## ESP32 BLE Sensor Dashboard (DHT22)

**Project Description**

This project uses an ESP32 microcontroller to read temperature and humidity data from a DHT22 sensor and broadcast it over Bluetooth Low Energy (BLE). The data is updated every 3 seconds and can be viewed using BLE scanner apps such as nRF Connect or LightBlue.

**BLE Configuration**

 Service UUID- 
12345678-1234-1234-1234-1234567890ab
 Characteristics- 
 
 Temperature Characteristic-
UUID: 12345678-1234-1234-1234-1234567890ac 
Properties: Read, Notify 
Description: Sends temperature in °C 
 Humidity Characteristic-
UUID: 12345678-1234-1234-1234-1234567890ad 
Properties: Read, Notify 
Description: Sends humidity in % 
 Timestamp Characteristic- 
UUID: 12345678-1234-1234-1234-1234567890ae 
Properties: Read, Notify 
Description: Time in seconds since device start

* BLE Descriptors
Each characteristic includes a BLE2902 descriptor, which enables notifications so that data updates automatically on the client device.


**1. Hardware Required**
ESP32 DevKit V1
DHT22 Temperature & Humidity Sensor
Jumper Wires
Breadboard

**2. Working Principle**
The DHT22 sensor reads temperature and humidity.
ESP32 processes the data.
BLE service is created with characteristics.
Data is updated and sent every 3 seconds.
A mobile app scans and displays the values in real-time.

**3. How to Test**
Upload the code to ESP32
Turn on Bluetooth on your phone
Open:
nRF Connect OR
LightBlue

Scan for device:

ESP32_DHT22
Connect and observe:
Temperature
Humidity
Timestamp

**4. Expected Output**
Data updates every 3 seconds
Values visible inside BLE app
Real-time sensor monitoring

## Wi-Fi Temperature Monitor (ESP32)

**1. Project Description**

This project uses an ESP32 microcontroller to create a simple web server that displays temperature and humidity data from a DHT11 sensor. The web page is hosted on the ESP32’s local IP address and automatically refreshes every 10 seconds. It also includes a button to toggle an onboard LED and displays system uptime.

**2. Hardware Required**
ESP32 Dev Module
DHT11 Temperature & Humidity Sensor
LED
220Ω Resistor
Jumper Wires
Breadboard

**3. Features Implemented**
 Displays Temperature (°C)
 Displays Humidity (%)
 Auto-refresh every 10 seconds
 LED Toggle Button via Web Page
 Displays Uptime (seconds since start)

**4 Working Principle**
ESP32 connects to a Wi-Fi network
A web server is started on port 80
DHT11 sensor reads temperature and humidity
Data is embedded into an HTML page
Web page is served at ESP32’s local IP
User accesses page via browser
Button sends request to toggle LED
Uptime is calculated using millis()

**5. How to Run (Hardware Setup)**
Upload the code to ESP32
Open Serial Monitor (115200 baud)
Connect to Wi-Fi
Note the IP address displayed

Open browser and enter:

http://<ESP32_IP>
View live data and control LED

**6. Expected Output**
Web page showing:
Temperature
Humidity
Uptime
Toggle LED button
Page refreshes every 10 seconds
LED toggles when button is pressed

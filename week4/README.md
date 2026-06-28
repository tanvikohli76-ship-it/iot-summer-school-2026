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




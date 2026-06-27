## LED Blink Project (Week 1)

## Project Title
LED Blink with Adjustable Speed and Serial Monitoring

##  Hardware Required
- Arduino Uno 
- LED
- 220Ω Resistor
- Potentiometer
- Breadboard
- Jumper Wires
- USB Cable

##  Circuit Diagram Description

<img width="1920" height="1080" alt="Screenshot (200)" src="https://github.com/user-attachments/assets/cf6c7dd8-9b07-475d-aa40-dacbf2a4aafb" />

- Connect the LED anode (+) to digital pin 13 through a 220Ω resistor  
- Connect the LED cathode (-) to GND 
- Connect the middle pin of the potentiometer to A0 (analog pin)
- Connect the other two pins of the potentiometer to 5V and GND 

## How to Upload Code (Step-by-Step)

1. Connect Arduino to your computer using USB cable  
2. Open Arduino IDE  
3. Copy and paste the code into a new sketch  
4. Select the correct board:
   - Tools → Board → Arduino Uno  
5. Select the correct port:
   - Tools → Port → (choose your COM port)  
6. Click on "Upload button (→)"  
7. Wait for "Upload Complete" message  

##  Expected Output

- LED will blink continuously  
- Blink speed changes when you rotate the potentiometer  
- Serial Monitor displays:
Blink count: X
- As you turn the potentiometer:
- Faster blinking (low delay)
- Slower blinking (high delay)

##  Troubleshooting Tips

1. **LED not blinking**
 - Check wiring of LED (polarity matters)
 - Ensure correct pin (pin 13) is used  

2. **Potentiometer not affecting speed**
 - Verify connections to A0, 5V, and GND  
 - Ensure correct mapping in code  

3. **Upload error**
 - Check correct COM port selected  
 - Ensure no other application is using the port  

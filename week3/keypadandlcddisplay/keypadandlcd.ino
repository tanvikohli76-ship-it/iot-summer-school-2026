/*
  Author: Tanvi Kohli
  Date: 2026-06-27
  Description: keypad and lcd display password system
*/
#include <LiquidCrystal.h>
#include <Keypad.h>

// LCD (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

// Keypad
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {8,9,10,11};
byte colPins[COLS] = {12,13,A0,A1};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Outputs
int greenLED = A2;
int redLED = A3;
int buzzer = A4;

// Password
String correctPIN = "1234";
String enteredPIN = "";

int attempts = 0;
bool locked = false;

void setup() {
  lcd.begin(16,2);
  delay(100);
  lcd.clear();

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.setCursor(0,0);
  lcd.print("ENTER PIN:");

  lcd.setCursor(0,1);
  lcd.print("                ");
}

void loop() {

  if (locked) {
    lcd.clear();
    lcd.print("LOCKED!");
    delay(10000);

    locked = false;
    attempts = 0;

    lcd.clear();
    lcd.print("ENTER PIN:");
    return;
  }

  char key = keypad.getKey();

  if (key) {
    enteredPIN += key;

    lcd.setCursor(0,1);
    lcd.print("                ");
    lcd.setCursor(0,1);
    lcd.print(enteredPIN);

    if (enteredPIN.length() == 4) {

      if (enteredPIN == correctPIN) {
        lcd.clear();
        lcd.print("ACCESS GRANTED");

        digitalWrite(greenLED, HIGH);
        delay(3000);
        digitalWrite(greenLED, LOW);

      } else {
        lcd.clear();
        lcd.print("ACCESS DENIED");

        digitalWrite(redLED, HIGH);
        tone(buzzer, 1000);
        delay(2000);
        noTone(buzzer);
        digitalWrite(redLED, LOW);

        attempts++;
        if (attempts >= 3) locked = true;
      }

      enteredPIN = "";
      delay(2000);

      lcd.clear();
      lcd.print("ENTER PIN:");
    }
  }
}

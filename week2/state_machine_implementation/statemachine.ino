//////////////////////////////////////////////////////////
// STATE MACHINE: VENDING MACHINE
//
// STATES:
// IDLE → waiting for coin
// COIN_INSERTED → coin accepted
// ITEM_SELECTED → item chosen
// DISPENSING → item is dispensed
//
// TRANSITIONS:
// IDLE --(coin)--> COIN_INSERTED
// COIN_INSERTED --(select)--> ITEM_SELECTED
// ITEM_SELECTED --> DISPENSING --> IDLE
// ANY STATE --(cancel)--> IDLE
//////////////////////////////////////////////////////////
/*
  Author: Tanvi Kohli
  Date: 2026-06-27
*/

enum State {
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

const int coinBtn = 2;
const int selectBtn = 3;
const int cancelBtn = 4;

const int ledIdle = 8;
const int ledCoin = 9;
const int ledSelect = 10;
const int ledDispense = 11;

void setup() {
  Serial.begin(9600);

  pinMode(coinBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(cancelBtn, INPUT_PULLUP);

  pinMode(ledIdle, OUTPUT);
  pinMode(ledCoin, OUTPUT);
  pinMode(ledSelect, OUTPUT);
  pinMode(ledDispense, OUTPUT);

  updateLEDs();
}

void loop() {

  bool coin = digitalRead(coinBtn) == LOW;
  bool select = digitalRead(selectBtn) == LOW;
  bool cancel = digitalRead(cancelBtn) == LOW;

  // CANCEL anytime
  if (cancel) {
    currentState = IDLE;
    updateLEDs();
    delay(300);
    return;
  }

  switch (currentState) {

    case IDLE:
      if (coin) {
        Serial.println("IDLE → COIN_INSERTED");
        currentState = COIN_INSERTED;
        updateLEDs();
        delay(300);

        // WAIT until button released
        while (digitalRead(coinBtn) == LOW);
      }
      break;

    case COIN_INSERTED:
      if (select) {
        Serial.println("COIN_INSERTED → ITEM_SELECTED");
        currentState = ITEM_SELECTED;
        updateLEDs();
        delay(500);

        // WAIT until button released
        while (digitalRead(selectBtn) == LOW);
      }
      break;

    case ITEM_SELECTED:
      // STAY here for a moment so you can SEE it
      Serial.println("ITEM_SELECTED (WAITING...)");
      delay(1000);

      Serial.println("→ DISPENSING");
      currentState = DISPENSING;
      updateLEDs();
      break;

    case DISPENSING:
      Serial.println("DISPENSING...");
      delay(2000);

      Serial.println("→ IDLE");
      currentState = IDLE;
      updateLEDs();
      break;
  }
}

void updateLEDs() {
  digitalWrite(ledIdle, LOW);
  digitalWrite(ledCoin, LOW);
  digitalWrite(ledSelect, LOW);
  digitalWrite(ledDispense, LOW);

  switch (currentState) {
    case IDLE: digitalWrite(ledIdle, HIGH); break;
    case COIN_INSERTED: digitalWrite(ledCoin, HIGH); break;
    case ITEM_SELECTED: digitalWrite(ledSelect, HIGH); break;
    case DISPENSING: digitalWrite(ledDispense, HIGH); break;
  }
}

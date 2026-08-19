#include <Arduino.h>

const int segPins[7] = {2, 3, 4, 5, 6, 7, 8}; // a,b,c,d,e,f,g
const int buttonPin = 9;

byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

int count = 0;
bool lastButtonState = LOW;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 200; // ms - minimum gap between counted presses

void showDigit(int num);

void setup() {
  for (int i = 0; i < 7; i++) pinMode(segPins[i], OUTPUT);
  pinMode(buttonPin, INPUT);
  showDigit(count);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH && lastButtonState == LOW) {
    if (millis() - lastDebounceTime > debounceDelay) {
      count++;
      if (count > 9) count = 0;
      showDigit(count);
      lastDebounceTime = millis();
    }
  }
  lastButtonState = buttonState;
}

void showDigit(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], digits[num][i]);
  }
}
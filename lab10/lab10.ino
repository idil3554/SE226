#include <LiquidCrystal.h>

const int aPin = 22;
const int bPin = 23;
const int cPin = 24;
const int dPin = 25;
const int ePin = 26;
const int fPin = 27;
const int gPin = 28;
const int dP   = 29;

const int GND1 = 33;
const int GND2 = 34;
const int GND3 = 35;
const int GND4 = 36;

const int SEG_ON  = HIGH;
const int SEG_OFF = LOW;
const int DIGIT_ON  = HIGH;
const int DIGIT_OFF = LOW;

LiquidCrystal lcd(36, 37, 26, 27, 28, 29);

int dig1 = 0;
int dig2 = 0;
int dig3 = 0;
int dig4 = 0;

unsigned long lastIncrement = 0;

const byte digitMap[10][7] = {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

void setup() {
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(dP,   OUTPUT);

  pinMode(GND1, OUTPUT);
  pinMode(GND2, OUTPUT);
  pinMode(GND3, OUTPUT);
  pinMode(GND4, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("Counter:");
}

void displayDigit(int num) {
  digitalWrite(aPin, digitMap[num][0] ? SEG_ON : SEG_OFF);
  digitalWrite(bPin, digitMap[num][1] ? SEG_ON : SEG_OFF);
  digitalWrite(cPin, digitMap[num][2] ? SEG_ON : SEG_OFF);
  digitalWrite(dPin, digitMap[num][3] ? SEG_ON : SEG_OFF);
  digitalWrite(ePin, digitMap[num][4] ? SEG_ON : SEG_OFF);
  digitalWrite(fPin, digitMap[num][5] ? SEG_ON : SEG_OFF);
  digitalWrite(gPin, digitMap[num][6] ? SEG_ON : SEG_OFF);
  digitalWrite(dP, SEG_OFF);
}

void showDigit(int gndPin, int value) {
  digitalWrite(GND1, DIGIT_OFF);
  digitalWrite(GND2, DIGIT_OFF);
  digitalWrite(GND3, DIGIT_OFF);
  digitalWrite(GND4, DIGIT_OFF);

  displayDigit(value);
  digitalWrite(gndPin, DIGIT_ON);
  delay(4);
}

void showNumber() {
  showDigit(GND1, dig1);
  showDigit(GND2, dig2);
  showDigit(GND3, dig3);
  showDigit(GND4, dig4);
}

void incrementCounter() {
  dig1++;
  if (dig1 >= 10) {
    dig1 = 0;
    dig2++;
    if (dig2 >= 10) {
      dig2 = 0;
      dig3++;
      if (dig3 >= 10) {
        dig3 = 0;
        dig4++;
        if (dig4 >= 10) {
          dig4 = 0;
        }
      }
    }
  }
}

void updateLCD() {
  digitalWrite(GND1, DIGIT_OFF);
  digitalWrite(GND2, DIGIT_OFF);
  digitalWrite(GND3, DIGIT_OFF);
  digitalWrite(GND4, DIGIT_OFF);
  lcd.setCursor(0, 0);
  lcd.print("Counter: ");
  lcd.print(dig4);
  lcd.print(dig3);
  lcd.print(dig2);
  lcd.print(dig1);
  lcd.print("    ");
}

void loop() {
  showNumber();

  if (millis() - lastIncrement >= 1000) {
    lastIncrement = millis();
    incrementCounter();
    updateLCD();
  }
}
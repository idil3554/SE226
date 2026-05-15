int LED1pin = 43;
int LED2pin = 44;
int LED3pin = 45;
int LED4pin = 46;
int button1pin = 38;
int button2pin = 39;

int lastButton1State = LOW;
int lastButton2State = LOW;
int systemOn = LOW;
int mode = 1;

unsigned long previousMillis = 0;
const long interval = 1000;
int sequenceIndex = 0;
int blinkState = LOW;

void setup() {
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
  pinMode(LED3pin, OUTPUT);
  pinMode(LED4pin, OUTPUT);
  pinMode(button1pin, INPUT);
  pinMode(button2pin, INPUT);
}

void allLedsOff() {
  digitalWrite(LED1pin, LOW);
  digitalWrite(LED2pin, LOW);
  digitalWrite(LED3pin, LOW);
  digitalWrite(LED4pin, LOW);
}

void loop() {
  int button1State = digitalRead(button1pin);
  int button2State = digitalRead(button2pin);

  if (button1State != lastButton1State) {
    lastButton1State = button1State;
    if (button1State == HIGH) {
      systemOn = (systemOn == HIGH) ? LOW : HIGH;
      allLedsOff();
      sequenceIndex = 0;
      blinkState = LOW;
      previousMillis = millis();
    }
  }

  if (button2State != lastButton2State) {
    lastButton2State = button2State;
    if (button2State == HIGH) {
      mode = mode + 1;
      if (mode > 3) mode = 1;
      allLedsOff();
      sequenceIndex = 0;
      blinkState = LOW;
      previousMillis = millis();
    }
  }

  if (systemOn == LOW) {
    allLedsOff();
    return;
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (mode == 1) {
      blinkState = (blinkState == HIGH) ? LOW : HIGH;
      digitalWrite(LED1pin, blinkState);
      digitalWrite(LED2pin, blinkState);
      digitalWrite(LED3pin, blinkState);
      digitalWrite(LED4pin, blinkState);
    }
    else if (mode == 2) {
      allLedsOff();
      if (sequenceIndex == 0)      digitalWrite(LED1pin, HIGH);
      else if (sequenceIndex == 1) digitalWrite(LED2pin, HIGH);
      else if (sequenceIndex == 2) digitalWrite(LED3pin, HIGH);
      else if (sequenceIndex == 3) digitalWrite(LED4pin, HIGH);
      sequenceIndex = (sequenceIndex + 1) % 4;
    }
    else if (mode == 3) {
      allLedsOff();
      if (sequenceIndex == 0)      digitalWrite(LED4pin, HIGH);
      else if (sequenceIndex == 1) digitalWrite(LED3pin, HIGH);
      else if (sequenceIndex == 2) digitalWrite(LED2pin, HIGH);
      else if (sequenceIndex == 3) digitalWrite(LED1pin, HIGH);
      sequenceIndex = (sequenceIndex + 1) % 4;
    }
  }
}

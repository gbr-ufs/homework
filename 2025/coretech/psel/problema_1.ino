const int buttonPin = 2;
const int ledPins[5] = {9, 10, 11, 12, 13};
int buttonState = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPins[0], HIGH);

    for (int i = 1; i < 5; i++) {
      delay(1000);
      digitalWrite(ledPins[i], HIGH);
    }

    delay(3000);
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  } else {
    digitalWrite(ledPins[0], LOW);
  }
}

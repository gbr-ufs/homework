/*
  Obrigado galera do Arduino. Veja:
  <https://docs.arduino.cc/learn/starting-guide/getting-started-arduino/#example-sketch>
 */

int sensorPin = A1; // Mude o pin para o pin no microcontrolador.
int ledPin = 2;    // ↑
int sensorValue; // Guardar leitura.

void setup() {
  Serial.begin(9600); // O número indica a taxa baud (velocidade de comunicação).
  pinMode(ledPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);

  Serial.print("Sensor value is: ");
  Serial.println(sensorValue);

  // 200 o que?
  if (sensorValue < 200) {
    digitalWrite(ledPin, HIGH); // "HIGH" é 1, "LOW" é 0.
  } else {
    digitalWrite(ledPin, LOW);
  }
}

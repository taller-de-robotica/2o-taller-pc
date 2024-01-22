/* Práctica 1
Author: Cesar Arzate
(versión: Mega 2560)
ARDUINO L293D(Puente H)
2 10
3 15
11 7
12 2
5V 1, 9, 16
GND 4, 5, 12, 13
El motor 1 se conecta a los pines 3 y 6 del Puente H
El motor 2 se conecta a los pines 11 y 14 del Puente H
La fuente de alimentacion de los Motores se conecta a tierra y
el positivo al pin 8 del puennte H.
*/

int izqA = 2;
int izqB = 3;
int derA = 11;
int derB = 12;
int vel = 255; // Velocidad de los motores (0-255)

void setup() {
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
}

void loop() {
  digitalWrite(derA, HIGH);
  digitalWrite(izqA, HIGH);
  digitalWrite(derB, LOW);
  digitalWrite(izqB, LOW);
  delay (1);
  digitalWrite(derA, LOW);
  digitalWrite(izqA, LOW);
  digitalWrite(derB, LOW);
  digitalWrite(izqB, LOW);
  delay (1);
}

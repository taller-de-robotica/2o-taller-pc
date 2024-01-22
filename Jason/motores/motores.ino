/* Práctica 1
Author: Cesar Arzate
(versión: Mega 2560)
ARDUINO L293D(Puente H)
 5  10
 6  15
 9   7
10   2
5V   1, 9, 16
GND  4, 5, 12, 13
El motor 1 se conecta a los pines 3 y 6 del Puente H
El motor 2 se conecta a los pines 11 y 14 del Puente H
La fuente de alimentacion de los Motores se conecta a tierra y
el positivo al pin 8 del puennte H.
*/

int izqA = 5;  // Pines a entradas <1:4>A
int izqB = 6;
int derA = 9;
int derB = 10;
int vel = 255; // Velocidad de los motores (0-255)


/* Se ejecuta una sola vez, al inicio. */
void setup() {
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
}

/* Ejecución repetida */
void loop() {
  digitalWrite(derA, HIGH);
  digitalWrite(izqA, HIGH);
  digitalWrite(derB, LOW);
  digitalWrite(izqB, LOW);
  delay (1000);              // Esperar 1s
  digitalWrite(derA, LOW);
  digitalWrite(izqA, LOW);
  digitalWrite(derB, LOW);
  digitalWrite(izqB, LOW);
  delay (1000);
}

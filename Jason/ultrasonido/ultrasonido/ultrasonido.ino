int TRIGGER = 2;
int ECHO = 3;
int tiempo = 0;
int distancia = 0;

void setup() {
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  Serial.begin(9600);
}

void loop() {
  // Enviar señal y recibir echo
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER, LOW);

  // Calcular el tiempo
  tiempo = pulseIn(ECHO, HIGH, 300000);
  distancia = tiempo / 58;

  Serial.print("Obstáculo a " + distancia );
  Serial.println(" cm");

  delay(1000);
}

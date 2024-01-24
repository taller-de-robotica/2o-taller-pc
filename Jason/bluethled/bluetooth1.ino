int green_led = 13;
int estado = 'c'; // inicia detenido
int tiempo = 0;
int distancia = 0;

void setup() {
Serial.begin(9600); // inicia el puerto serial para comunicacion con el Bluetooth
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);

pinMode(3, INPUT);
pinMode(2, OUTPUT);

}
void loop() {
  if(Serial.available()>0){ // lee el bluetooth y almacena en estado
  estado = Serial.read();
  }
  if(estado=='a'){ // enfrente
  digitalWrite(5, HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10,LOW);
  }
  if(estado=='b'){ // reversa

  digitalWrite(9,LOW);
  digitalWrite(10, HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6, HIGH);

  }
  if(estado=='c'){ // frenar
  digitalWrite(5, LOW);
  digitalWrite(6,LOW);
  digitalWrite(9, LOW);
  digitalWrite(10,LOW);
  }
  if(estado=='d'){ // vuelta
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  }
  if(estado=='e') { //vuelta al otro lado
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
  }

}

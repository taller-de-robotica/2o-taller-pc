/*
 * Referencias:
 * https://programarfacil.com/blog/arduino-blog/comunicacion-i2c-con-arduino/
 */
// La librería Wire permite usar I2C
#include <Wire.h>

//const int LED_PIN = 13;
const int SLAVE_ADDRESS = 0x8; // Hexadecimal entre 8 y 127
char buf[100];

void setup() {
  // Depurado usando un puerto serial
  Serial.begin(9600);

  // Se sube al camión I2C como esclavo con la dirección indicada
  Wire.begin(SLAVE_ADDRESS);

  // Call receiveEvent when data received                
  Wire.onReceive(receiveEvent);

  // Llama requestEvent cuando se soliciten datos
  Wire.onRequest(requestEvent);

  // Setup pin 13 as output and turn LED off
  //pinMode(LED_PIN, OUTPUT);
  //digitalWrite(LED_PIN, LOW);
}

// Función que se ejecuta cuando el maestro va a enviar información.
void receiveEvent(int howMany) {
  sprintf(buf, "Received %d number:\n", howMany);
  Serial.print(buf);
  int ava;
  while (ava = Wire.available()) {
    char c = Wire.read(); // receive byte as a character
    sprintf(buf, "Wire read %d: %d=%c\n", ava, c, c);
    Serial.print(buf);
    //digitalWrite(LED_PIN, c);
  }
}

// Función que se ejecuta cuando el maestro solicita información.
void requestEvent() {

}

void loop() {
  delay(100);
}

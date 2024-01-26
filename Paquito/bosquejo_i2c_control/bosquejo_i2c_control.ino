/*  ___   ___  ___  _   _  ___   ___   ____ ___  ____  
 * / _ \ /___)/ _ \| | | |/ _ \ / _ \ / ___) _ \|    \ 
 *| |_| |___ | |_| | |_| | |_| | |_| ( (__| |_| | | | |
 * \___/(___/ \___/ \__  |\___/ \___(_)____)___/|_|_|_|
 *                  (____/ 
 * Arduino Mecanum Omni Direction Wheel Robot Car Lesson5 Wifi Control
 * CopyRight www.osoyoo.com
 * ___________________________________________________________________
 *
 * Control del robot desde una Raspberry utilizando I2C.
 * Adaptación para Taller de Robótica Proyecto PAPIME PE104223
 * @author blackzafiro
 *
 */
#include <Wire.h>
const int SLAVE_ADDRESS = 0x8; // Hexadecimal entre 8 y 127

#define speedPinR 3            // Front Wheel PWM pin connect Model-Y M_B ENA 
#define RightMotorDirPin1 48   // Front Right Motor direction pin 1 to Model-Y M_B IN1 (K1)
#define RightMotorDirPin2 49   // Front Right Motor direction pin 2 to Model-Y M_B IN2 (K1)
#define LeftMotorDirPin1  46   // Front Left Motor direction pin 1 to Model-Y M_B IN3  (K3)
#define LeftMotorDirPin2  47   // Front Left Motor direction pin 2 to Model-Y M_B IN4  (K3)
#define speedPinL 5            // Front Wheel PWM pin connect Model-Y M_B ENB

#define speedPinRB 6           // Rear Wheel PWM pin connect Left Model-Y M_A ENA 
#define RightMotorDirPin1B 52  // Rear Right Motor direction pin 1 to Model-Y M_A IN1 (K1)
#define RightMotorDirPin2B 53  // Rear Right Motor direction pin 2 to Model-Y M_A IN2 (K1) 
#define LeftMotorDirPin1B  50  // Rear Left Motor direction pin 1 to Model-Y M_A IN3  (K3)
#define LeftMotorDirPin2B  51  // Rear Left Motor direction pin 2 to Model-Y M_A IN4  (K3)
#define speedPinLB 7           // Rear Wheel PWM pin connect Model-Y M_A ENB


#include <Car.h>

const Wheel WHEELS[] = {
  Wheel(speedPinL,  LeftMotorDirPin1,   LeftMotorDirPin2),
  Wheel(speedPinR,  RightMotorDirPin1,  RightMotorDirPin2),
  Wheel(speedPinLB, LeftMotorDirPin1B,  LeftMotorDirPin2B),
  Wheel(speedPinRB, RightMotorDirPin1B, RightMotorDirPin2B)
};

Car paquito(WHEELS);

enum Movement {
  STOP = 0b00000001,
  FORWARD = 0b00001111,
  BACKWARD = 0b11110000,
};

void setup() {
  // Depurado usando un puerto serial
  Serial.begin(9600);
  Serial.println(".´`. paquito init .´`.");

  // Se sube al camión I2C como esclavo con la dirección indicada
  Wire.begin(SLAVE_ADDRESS);

  // Inicializa los pins del carrito
  paquito.begin();

  //paquito.testWheels();
  //paquito.moveForward(100);
  //delay(1000);
  //paquito.stop();

  // Se ejecuta al recibir datos
  Wire.onReceive(receiveEvent);

  // Llama requestEvent cuando se soliciten datos
  Wire.onRequest(requestEvent);
}

// Función que se ejecuta cuando el maestro va a enviar información.
void receiveEvent(int howMany) {
  char buf[200];
  sprintf(buf, "\nReceived %d:\n", howMany);
  Serial.print(buf);

  char ini = Wire.read();
  sprintf(buf, "First byte: %d\n", ini);
  Serial.print(buf);

  if (howMany < 2) return;
  unsigned char commandByte = Wire.read();
  sprintf(buf, "Command: %d\n", commandByte);
  Serial.print(buf);

  Serial.println("Arguments:");
  unsigned char args[howMany - 2];
  int ind = 0;
  int ava;
  while (ava = Wire.available()) {
    unsigned char c = Wire.read(); // receive byte as a character
    sprintf(buf, "Wire read %d: %d=%c\n", ava, c, c);
    Serial.print(buf);

    args[ind++] = c;
    //digitalWrite(LED_PIN, c);
  }

  switch(commandByte) {
    case STOP:
      Serial.println("--> Detente");
      paquito.stop();
      break;
    case FORWARD:
      Serial.println("--> Avanza " + args[0]);
      paquito.moveForward(args[0]);
      break;
    case BACKWARD:
      Serial.println("--> Retrocede " + args[0]);
      paquito.moveBackward(args[0]);
      break;
    default:
      Serial.println("--> Comando desconocido");
  }
}

// Función que se ejecuta cuando el maestro solicita información.
void requestEvent() {

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100); // 0.1mm
}

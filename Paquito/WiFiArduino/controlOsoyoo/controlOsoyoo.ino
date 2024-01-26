/*  ___   ___  ___  _   _  ___   ___   ____ ___  ____  
 * / _ \ /___)/ _ \| | | |/ _ \ / _ \ / ___) _ \|    \ 
 *| |_| |___ | |_| | |_| | |_| | |_| ( (__| |_| | | | |
 * \___/(___/ \___/ \__  |\___/ \___(_)____)___/|_|_|_|
 *                  (____/ 
 * Arduino Mecanum Omni Direction Wheel Robot Car Lesson5 Wifi Control
 * Tutorial URL http://osoyoo.com/?p=49235
 * CopyRight www.osoyoo.com
 * 
 * In this project we will connect Robot Car to Wifi and Use an APP to control the car through Internet. 
 * 
 * ___________________________________________________________________
 * Adaptación para Taller de Robótica Proyecto PAPIME PE104223
 * @author blackzafiro
 *
 */
#define SPEED 70    
#define TURN_SPEED 140  

#define speedPinR 9            // Front Wheel PWM pin connect Model-Y M_B ENA 
#define RightMotorDirPin1 22   // Front Right Motor direction pin 1 to Model-Y M_B IN1  (K1)
#define RightMotorDirPin2 24   // Front Right Motor direction pin 2 to Model-Y M_B IN2   (K1)                                 
#define LeftMotorDirPin1  26   // Front Left Motor direction pin 1 to Model-Y M_B IN3 (K3)
#define LeftMotorDirPin2  28   // Front Left Motor direction pin 2 to Model-Y M_B IN4 (K3)
#define speedPinL 10           // Front Wheel PWM pin connect Model-Y M_B ENB

#define speedPinRB 11          // Rear Wheel PWM pin connect Left Model-Y M_A ENA 
#define RightMotorDirPin1B 5   // Rear Right Motor direction pin 1 to Model-Y M_A IN1 ( K1)
#define RightMotorDirPin2B 6   // Rear Right Motor direction pin 2 to Model-Y M_A IN2 ( K1) 
#define LeftMotorDirPin1B  7   // Rear Left Motor direction pin 1 to Model-Y M_A IN3  (K3)
#define LeftMotorDirPin2B  8   // Rear Left Motor direction pin 2 to Model-Y M_A IN4 (K3)
#define speedPinLB 12          // Rear Wheel PWM pin connect Model-Y M_A ENB

//#define HOTSPOT

///
/// Control de motores
///

//
// Movimiento llanta por llanta
//

/* 
 * front-right wheel forward turn
 */
void FR_fwd(int speed) {
  digitalWrite(RightMotorDirPin1, LOW);
  digitalWrite(RightMotorDirPin2, HIGH); 
  analogWrite(speedPinR, speed);
}

/* 
 * front-right wheel backward turn
 */
void FR_bck(int speed) {
  digitalWrite(RightMotorDirPin1, HIGH);
  digitalWrite(RightMotorDirPin2, LOW); 
  analogWrite(speedPinR, speed);
}

/*
 * front-left wheel forward turn
 */
void FL_fwd(int speed) {
  digitalWrite(LeftMotorDirPin1, LOW);
  digitalWrite(LeftMotorDirPin2, HIGH);
  analogWrite(speedPinL, speed);
}

/*
 * front-left wheel backward turn
 */
void FL_bck(int speed) {
  digitalWrite(LeftMotorDirPin1, HIGH);
  digitalWrite(LeftMotorDirPin2, LOW);
  analogWrite(speedPinL, speed);
}

/*
 * rear-right wheel forward turn
 */
void RR_fwd(int speed) {
  digitalWrite(RightMotorDirPin1B, LOW);
  digitalWrite(RightMotorDirPin2B,HIGH); 
  analogWrite(speedPinRB,speed);
}

/*
 * rear-right wheel backward turn
 */
void RR_bck(int speed) {
  digitalWrite(RightMotorDirPin1B, HIGH);
  digitalWrite(RightMotorDirPin2B,LOW); 
  analogWrite(speedPinRB,speed);
}

/*
 * rear-left wheel forward turn
 */
void RL_fwd(int speed) {
  digitalWrite(LeftMotorDirPin1B,LOW);
  digitalWrite(LeftMotorDirPin2B,HIGH);
  analogWrite(speedPinLB,speed);
}

/*
 * rear-left wheel backward turn
 */
void RL_bck(int speed) {
  digitalWrite(LeftMotorDirPin1B,HIGH);
  digitalWrite(LeftMotorDirPin2B,LOW);
  analogWrite(speedPinLB,speed);
}

/*
 * Frena llanta frontal izquierda
 */
void frena_frente_izq() {
  analogWrite(speedPinL,0);  
}

/*
 * Frena llanta frontal derecha
 */
void frena_frente_der() {
  analogWrite(speedPinR,0);
}

/*
 * Frena llanta trasera izquierda
 */
void frena_tras_izq() {
  analogWrite(speedPinLB,0);
}

/*
 * Frena llanta trasera derecha
 */
void frena_tras_der() {
  analogWrite(speedPinRB,0);
}

///
/// Control del auto omnidireccional
///

/*
 * Desplazamiento horizontal a la derecha
 */
void right_shift(int speed_fl_fwd, int speed_rl_bck, int speed_rr_fwd, int speed_fr_bck) {
  FL_fwd(speed_fl_fwd); 
  RL_bck(speed_rl_bck); 
  FR_bck(speed_fr_bck);
  RR_fwd(speed_rr_fwd);
}

/*
 * Desplazamiento horizontal a la izquierda
 */
void left_shift(int speed_fl_bck, int speed_rl_fwd, int speed_rr_bck, int speed_fr_fwd) {
  FL_bck(speed_fl_bck);
  RL_fwd(speed_rl_fwd);
  FR_fwd(speed_fr_fwd);
  RR_bck(speed_rr_bck);
}

/*
 * Avanza
 */
void go_advance(int speed) {
   RL_fwd(speed);
   RR_fwd(speed);
   FR_fwd(speed);
   FL_fwd(speed); 
}

/*
 * Retrocede
 */
void go_back(int speed) {
   RL_bck(speed);
   RR_bck(speed);
   FR_bck(speed);
   FL_bck(speed); 
}

/*
 * Gira a la izquierda
 */
void left_turn(int speed) { 
   RL_fwd(0);
   RR_fwd(speed);
   FR_fwd(speed);
   FL_fwd(0); 
}

/*
 * Gira a la derecha
 */
void right_turn(int speed) {
   RL_fwd(speed);
   RR_bck(0);
   FR_bck(0);
   FL_fwd(speed); 
}

/*
 * Retrocede girando a la izquierda
 */
void left_back(int speed) {
   RL_fwd(0);
   RR_bck(speed);
   FR_bck(speed);
   FL_fwd(0); 
}

/*
 * Retrocede girando a la derecha
 */
void right_back(int speed) {
   RL_bck(speed);
   RR_fwd(0);
   FR_fwd(0);
   FL_bck(speed); 
}

/*
 * Gira sobre su eje en la dirección de las manecillas del reloj
 */
void clockwise(int speed) {
   RL_fwd(speed);
   RR_bck(speed);
   FR_bck(speed);
   FL_fwd(speed); 
}

/*
 * Gira sobre su eje en dirección contraria a las manecillas del reloj
 */
void countclockwise(int speed) {
   RL_bck(speed);
   RR_fwd(speed);
   FR_fwd(speed);
   FL_bck(speed); 
}

/*
 * Stop
 */
void stop_Stop() {
  analogWrite(speedPinLB, 0);
  analogWrite(speedPinRB, 0);
  analogWrite(speedPinL, 0);
  analogWrite(speedPinR, 0);
}

/*
 * Pins initialization
 */
void init_GPIO() {
  // Frente
  pinMode(RightMotorDirPin1, OUTPUT); 
  pinMode(RightMotorDirPin2, OUTPUT); 
  pinMode(speedPinL, OUTPUT);  
 
  pinMode(LeftMotorDirPin1, OUTPUT);
  pinMode(LeftMotorDirPin2, OUTPUT); 
  pinMode(speedPinR, OUTPUT);
  
  // Tras
  pinMode(RightMotorDirPin1B, OUTPUT); 
  pinMode(RightMotorDirPin2B, OUTPUT); 
  pinMode(speedPinLB, OUTPUT);  
 
  pinMode(LeftMotorDirPin1B, OUTPUT);
  pinMode(LeftMotorDirPin2B, OUTPUT); 
  pinMode(speedPinRB, OUTPUT);
   
  stop_Stop();
}



///
/// Comunicación por WiFi
///

#include "WiFiEsp.h"
#include "WiFiEspUdp.h"


#ifndef HOTSPOT
char ssid[] = "*********"; // replace ****** with your network SSID (name)
char pass[] = "*********"; // replace ****** with your network password
#else
/// Si el robot será el hotspot
char ssid[] = "osoyoo_robot"; 
#endif


int status = WL_IDLE_STATUS;
// use a ring buffer to increase speed and reduce memory allocation
char packetBuffer[5]; 
WiFiEspUDP Udp;
unsigned int localPort = 8888;  // local port to listen on

/*
 * Inicializa conexión WiFi
 */
void init_WiFi() {
  Serial1.begin(115200);
  Serial1.write("AT+UART_DEF=9600,8,1,0,0\r\n");
  delay(200);
  Serial1.write("AT+RST\r\n");
  delay(200);
  Serial1.begin(9600);    // initialize serial for ESP module
  WiFi.init(&Serial1);    // initialize ESP module

  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue
    while (true);
  }

  // attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    
#ifndef HOTSPOT
    // Connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);
#else
    //AP mode
    status = WiFi.beginAP(ssid, 10, "", 0);
#endif
  }

  Serial.println("You're connected to the network");
  printWifiStatus();
  Udp.begin(localPort);
  
  Serial.print("Listening on port ");
  Serial.println(localPort);
}

void setup() {
  Serial.begin(9600);    // initialize serial for debugging
  init_GPIO();           // inicializa pines que conectan con los drivers
  init_WiFi();           // inicializa WiFi
}


void loop() {
  int packetSize = Udp.parsePacket();
  if (packetSize) {                               
    Serial.print("Received packet of size ");
    Serial.print(packetSize);
    int len = Udp.read(packetBuffer, 255);
    if (len > 0) {
      packetBuffer[len] = 0;
    }
    char c = packetBuffer[0];
    Serial.print(" char: ");
    Serial.println(c);
    switch (c)    //serial control instructions
    {  
      // Avanza llanta por llanta
      case '1':FL_fwd(SPEED);break;
      case '2':FR_fwd(SPEED);break;
      case '3':RL_fwd(SPEED);break;
      case '4':RR_fwd(SPEED);break;
      // Frena llanta por llanta
      case '5':frena_frente_izq();break;
      case '6':frena_frente_der();break;
      case '7':frena_tras_izq();break;
      case '8':frena_tras_der();break;
      // Mueve el carrito
      // ...
      default:break;
    }
  }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
}
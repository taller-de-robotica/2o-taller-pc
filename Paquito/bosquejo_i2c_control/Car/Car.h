/*
  Car.h - Library for controling the wheels of an omnidirectional car.
  Created by Verónica E. Arriola, September 4, 2023.
*/
#ifndef Car_h
#define Car_h

#include "Arduino.h"

class Wheel {
public:
  Wheel(int sp, int fp, int bp);

  void begin();

  void moveForward(int speed);

  void moveBackward(int speed);

  void stop();

  // Auxiliar para depurar pines.
  void printStatus(String name);
private:
  const int SPEED_PIN;
  const int FORWARD_PIN;
  const int BACKWARD_PIN;
};

enum WheelId
{
  FL = 0,
  FR,
  BL,
  BR
};

class Encoder
{
public:
  Encoder(int s1, int s2);

  void begin();
  void read(int readings[2]);
  double count();
private:
  const int S1_PIN;
  const int S2_PIN;
  unsigned long _lastTime;
  int _counter;
  int _s1State;
  int _s2State;
  int _s1LastState;
};

class Car
{
public:
  static const int NUM_WHEELS = 4;

  Car(const Wheel wheels[NUM_WHEELS], const Encoder encoders[NUM_WHEELS]);

  Car(const Wheel wheels[NUM_WHEELS]);

  void begin();

  // Mueve cada llanta una vez hacia adelante y hacia atrás.
  void testWheels();

  void moveForward(int speed);
  void moveBackward(int speed);
  void moveForward(WheelId id, int speed);

  void stop();
  void stop(WheelId id);
private:
  const Wheel *_wheels;
  const Encoder *_encoders;
};

#endif

#include "Arduino.h"
#include "Car.h"


// Wheel

Wheel::Wheel(int sp, int fp, int bp) : SPEED_PIN(sp), FORWARD_PIN(fp), BACKWARD_PIN(bp) {}

void Wheel::begin()
{
    pinMode(FORWARD_PIN, OUTPUT);
    pinMode(BACKWARD_PIN, OUTPUT);
    pinMode(SPEED_PIN, OUTPUT);

    stop();
}

void Wheel::moveForward(int speed)
{
    //printStatus("mF ");

    digitalWrite(FORWARD_PIN, HIGH);
    digitalWrite(BACKWARD_PIN, LOW);
    analogWrite(SPEED_PIN, speed);
}

void Wheel::moveBackward(int speed)
{
    //printStatus("mB");

    digitalWrite(FORWARD_PIN, LOW);
    digitalWrite(BACKWARD_PIN, HIGH);
    analogWrite(SPEED_PIN, speed);
}

void Wheel::stop()
{
    //printStatus("S");
    analogWrite(SPEED_PIN, 0);
}

void Wheel::printStatus(String name)
{
    Serial.print(name);
    Serial.print(" ");
    Serial.print(FORWARD_PIN);
    Serial.print(" ");
    Serial.print(BACKWARD_PIN);
    Serial.print(" ");
    Serial.println(SPEED_PIN);
}

// Encoder
Encoder::Encoder(int s1, int s2) : S1_PIN(s1), S2_PIN(s2), _counter(0) {}

void Encoder::begin()
{
    pinMode (S1_PIN, INPUT);
    pinMode (S2_PIN, INPUT);

    _counter = 0;
    _lastTime = millis();
    _s1LastState = digitalRead(S1_PIN);  // Estado incial del pin S1
}

void Encoder::read(int readings[2])
{
    readings[0] = digitalRead(S1_PIN);
    readings[1] = digitalRead(S2_PIN);
    return readings;
}

double Encoder::count()
{
    _s1State = digitalRead(S1_PIN);
    unsigned long time = millis();
    int delta = time - _lastTime;
    _lastTime = time;
    if(_s1State != _s1LastState)
    {
        _s2State = digitalRead(S2_PIN);
        // If S2 state is different to the S1 state, that means the encoder is rotating clockwise
        if (_s2State != _s1State)
        {
            _counter++;
        }
        else
        {
            _counter--;
        }
        _s1LastState = _s1State;  // Updates the previous S1 state with the current state
    }
    //return double(_counter)/double(time);
    return _counter;
}


// Car
Car::Car(const Wheel wheels[NUM_WHEELS], const Encoder encoders[NUM_WHEELS])
    : _wheels(wheels), _encoders(encoders){}

Car::Car(const Wheel wheels[NUM_WHEELS])
    : _wheels(wheels), _encoders(NULL){}

void Car::begin()
{
    for(int i = 0; i < NUM_WHEELS; i++)
    {
      // Inicializa llanta
      _wheels[i].begin();

      if(_encoders != NULL) {
        // Inicializa odómetro
        _encoders[i].begin();
      }
    }
 }

  // Mueve cada llanta una vez hacia adelante y hacia atrás.
void Car::testWheels()
{
    int delTime = 1000;
    int speed = 70;
    for(int i = 0; i < NUM_WHEELS; i++)
    {
        _wheels[i].moveForward(speed);
        delay(delTime);
        _wheels[i].stop();
        delay(delTime);
        _wheels[i].moveBackward(speed);
        delay(delTime);
        _wheels[i].stop();
        delay(delTime);
    }
}

void Car::moveForward(int speed)
{
    for(int i = 0; i < NUM_WHEELS; i++)
    {
        _wheels[i].moveForward(speed);
    }
}

void Car::moveBackward(int speed)
{
    for(int i = 0; i < NUM_WHEELS; i++)
    {
        _wheels[i].moveBackward(speed);
    }
}

void Car::moveForward(WheelId id, int speed)
{
    _wheels[id].moveForward(speed);
}

void Car::stop()
{
    for(int i = 0; i < NUM_WHEELS; i++)
    {
      _wheels[i].stop();
    }
}

void Car::stop(WheelId id)
{
    _wheels[id].stop();
}


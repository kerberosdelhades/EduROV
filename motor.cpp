#include "motor.h"
#include <Arduino.h>

/*

    Usando el constructor

 */


Motor::Motor(int8_t pinA, int8_t pinB, int8_t pinPWM) : //no lleva tipo
    pinA(pinA),
    pinB(pinB),
    pinPWM(pinPWM)
{
    this->parar();
    pinMode(this->pinA, OUTPUT);
    pinMode(this->pinB, OUTPUT);
    if (this->pinPWM >= 0) {
        pinMode(this->pinPWM, OUTPUT);
    }
}

void Motor::avanzar() {
    digitalWrite(this->pinA, HIGH);
    digitalWrite(this->pinB, LOW);
    if (this->pinPWM >= 0) {
        // digitalWrite(this->pinPWM, HIGH);
        analogWrite(this->pinPWM, 255);
    }
}

void Motor::retroceder() {
    digitalWrite(this->pinA, LOW);
    digitalWrite(this->pinB, HIGH);
    if (this->pinPWM >= 0) {
      // digitalWrite(this->pinPWM, HIGH);
      analogWrite(this->pinPWM, 255);
    }
}

void Motor::parar() {
    digitalWrite(this->pinA, LOW);
    digitalWrite(this->pinB, LOW);
    if (this->pinPWM >= 0) {
        digitalWrite(this->pinPWM, LOW);
    }
}

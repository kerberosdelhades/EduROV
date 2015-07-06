#include "motor.h"
#include <Arduino.h>

/*

    Usando el constructor

 */


Motor::Motor(int pinA, int pinB, int pinPWM) { //no lleva tipo
    this->pinA = pinA;
    this->pinB = pinB;
    this->pinPWM = pinPWM;
    this->parar();
    pinMode(this->pinA, OUTPUT);
    pinMode(this->pinB, OUTPUT);
    pinMode(this->pinPWM, OUTPUT);
}

void Motor::avanzar() {
    digitalWrite(this->pinA, HIGH);
    digitalWrite(this->pinB, LOW);
    digitalWrite(this->pinPWM, 255);
}

void Motor::retroceder() {
    digitalWrite(this->pinA, LOW);
    digitalWrite(this->pinB, HIGH);
    digitalWrite(this->pinPWM, 255);
}

void Motor::parar() {
    digitalWrite(this->pinA, LOW);
    digitalWrite(this->pinB, LOW);
    digitalWrite(this->pinPWM, 0);
}

Motor motorDerecho(pinA_1, pinB_1, pinPWM_1);
// class Motor motorDerecho(pinA_1, pinB_1, pinPWM_1);
// no es necesario poner el class
Motor motorIzquierdo(pinA_2, pinB_2, pinPWM_2);
//class Motor motorIzquierdo(pinA_2, pinB_2, pinPWM_2);
Motor motorVertical(pinA_3, pinB_3, pinPWM_3);
//class Motor motorIzquierdo(pinA_2, pinB_2, pinPWM_2);
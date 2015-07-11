#include <stdint.h>

#ifndef  __MOTOR_H__
#define  __MOTOR_H__


class Motor {
    private:
        int8_t pinA;
        int8_t pinB;
        int8_t pinPWM;
        uint8_t velocidad;
    public:
        void avanzar();
        void retroceder();
        void parar();
        Motor(int8_t pinA, int8_t pinB, int8_t pinPWM = -1);
};

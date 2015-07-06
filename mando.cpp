
/*

    Implementación de la clase Mando

  */

#include "mando.h"
#include <Arduino.h>

Mando::Mando(uint8_t pinX, uint8_t pinY, int8_t pinP1) :
    config(0),
    pinX(pinX),
    pinY(pinY),
    pinP1(pinP1)
{
}

void Mando::init(uint8_t config) {
    this->config = config;
    if (this->pinP1 != -1) {  // si no esta a -1, es que queremos usar boton
        pinMode(this->pinP1, INPUT_PULLUP); // y por tanto lo configuramos
    }
}

accion_mando_t Mando::getAccion() {
    uint16_t analogX = analogRead(this->pinX); // tomamos la lectura fisica
    uint16_t analogY = analogRead(this->pinY); // que luego pasamos a 0/1
    int8_t x = 0;
    int8_t y = 0;

    if (analogX >= LIMITE_MANDO_ALTO) {
        x = 1;
    }
    else if (analogX < LIMITE_MANDO_BAJO) {
        x = -1;
    }

    if (analogY >= LIMITE_MANDO_ALTO) {
        y = 1;
    }
    else if (analogY < LIMITE_MANDO_BAJO) {
        y = -1;
    }

    if (this->config & CONF_MANDO_INV_X) {
        x = -x;
    }

    if (this->config & CONF_MANDO_INV_Y) {
        y = -y;
    }

    if (x > 0) {
        if (y > 0) {
            return ACCION_MANDO_RETROCEDER_DERECHA;
        }
        else if (y < 0) {
            return ACCION_MANDO_AVANZAR_DERECHA;
        }
        return ACCION_MANDO_DERECHA;
    }
    else if (x < 0) {
        if (y > 0) {
            return ACCION_MANDO_RETROCEDER_IZQUIERDA;
        }
        else if (y < 0) {
            return ACCION_MANDO_AVANZAR_IZQUIERDA;
        }
        return ACCION_MANDO_IZQUIERDA;
    }
    if (y > 0) {
        return ACCION_MANDO_RETROCEDER;
    }
    else if (y < 0) {
        return ACCION_MANDO_AVANZAR;
    }
    return ACCION_MANDO_PARAR;
}

bool Mando::getPulsador1() {
    if (this->pinP1 == -1) {
        return (this->config & CONF_MANDO_INV_P1);
    }
    return (digitalRead(this->pinP1) ? (this->config & CONF_MANDO_INV_P1) : ( ! (this->config & CONF_MANDO_INV_P1) ));
}

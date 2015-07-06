-
/*

    Control del mando

  */

#include <stdint.h>

#ifndef  __MANDO_H__
#define  __MANDO_H__

enum accion_mando_t {
    ACCION_MANDO_PARAR,
    ACCION_MANDO_AVANZAR,
    ACCION_MANDO_AVANZAR_DERECHA,
    ACCION_MANDO_DERECHA,
    ACCION_MANDO_RETROCEDER_DERECHA,
    ACCION_MANDO_RETROCEDER,
    ACCION_MANDO_RETROCEDER_IZQUIERDA,
    ACCION_MANDO_IZQUIERDA,
    ACCION_MANDO_AVANZAR_IZQUIERDA
};

// añadido Ivan
// enum accion_mando_vertical_t {
//     ACCION_MANDO_PARAR,
//     ACCION_MANDO_AVANZAR,
//     ACCION_MANDO_RETROCEDER,
// };
// añadido Ivan
#define CONF_MANDO_POR_DEFECTO  0x00
#define CONF_MANDO_INV_X        0x01
#define CONF_MANDO_INV_Y        0x02
#define CONF_MANDO_INV_P1       0x04

#define LIMITE_MANDO_ALTO       ((1024 / 2) + (1024 / 3))
#define LIMITE_MANDO_BAJO       ((1024 / 2) - (1024 / 3))

class Mando {
    public:
        Mando(uint8_t pinX, uint8_t pinY, int8_t pinP1);
        void init(uint8_t config = CONF_MANDO_POR_DEFECTO);
        accion_mando_t getAccion();
        bool getPulsador1();
    private:
        uint8_t config;
        uint8_t pinX;
        uint8_t pinY;
        int8_t pinP1;
};

#endif  // __MANDO_H__

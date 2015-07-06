
/*

    Test del control del mando

  */

#include "mando.h"

#define MANDO_DERECHO_PIN_X     A0  // VRx del mando a pin analogico A0 del arduino
#define MANDO_DERECHO_PIN_Y     A1  // VRy del mando a pin analogico A1 del Arduino
#define MANDO_DERECHO_PIN_P1    8   // SW  del mando a pin digital 8 del Arduino
#define MANDO_DERECHO_CONF      CONF_MANDO_POR_DEFECTO

// Configuración alternativa
// (probar a combinar diferentes CONF_MANDO_XXXX) definidos en mando.h
// #define MANDO_DERECHO_CONF      CONF_MANDO_INV_X | CONF_MANDO_INV_Y | CONF_MANDO_INV_P1

Mando mandoDerecho(MANDO_DERECHO_PIN_X, MANDO_DERECHO_PIN_Y, MANDO_DERECHO_PIN_P1);

void setup() {
    Serial.begin(9600);
    while ( ! Serial ) {
        ; // wait for serial port to connect. Needed for Leonardo only
    }
    mandoDerecho.init(MANDO_DERECHO_CONF);
    Serial.println("Juega con el palo de juego ;)");
}

accion_mando_t accionMando = ACCION_MANDO_PARAR;
accion_mando_t accionMandoAnterior = accionMando;

bool pulsadorMando = false;
bool pulsadorMandoAnterior = pulsadorMando;

void loop() {
    accionMando = mandoDerecho.getAccion();
    pulsadorMando = mandoDerecho.getPulsador1();
    if ((accionMandoAnterior != accionMando) || (pulsadorMandoAnterior != pulsadorMando)) {
        accionMandoAnterior = accionMando;
        pulsadorMandoAnterior = pulsadorMando;
        switch (accionMando) {
            case ACCION_MANDO_PARAR:  //vertical
                Serial.print("Parar");
                break;
            case ACCION_MANDO_AVANZAR: // vertical
                Serial.print("Avanzar");
                break;
            case ACCION_MANDO_AVANZAR_DERECHA:
                Serial.print("Avanzar derecha");
                break;
            case ACCION_MANDO_DERECHA:
                Serial.print("Derecha");
                break;
            case ACCION_MANDO_RETROCEDER_DERECHA:
                Serial.print("Retroceder derecha");
                break;
            case ACCION_MANDO_RETROCEDER: //vertical
                Serial.print("Retroceder");
                break;
            case ACCION_MANDO_RETROCEDER_IZQUIERDA:
                Serial.print("Retroceder izquierda");
                break;
            case ACCION_MANDO_IZQUIERDA:
                Serial.print("Izquierda");
                break;
            case ACCION_MANDO_AVANZAR_IZQUIERDA:
                Serial.print("Avanzar izquierda");
                break;
        }
        if (pulsadorMando) {
                Serial.println(" [Activo]");
        }
        else {
            Serial.println();
        }
    }
}

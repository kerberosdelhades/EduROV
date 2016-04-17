

/*

    Usando el constructor

 */

#include "mando.h"
#include "motor.h"

#define PIN_SIN_DEFINIR -1

// Motor Derecho
#define pinA_1      3      // Pin ENA1 del puente en H 
#define pinB_1      4      // Pin ENA2 del puente en H
#define pinPWM_1    PIN_SIN_DEFINIR       // Pin ENA del L293D (ENABLE1)


//Motor Izquierdo
#define pinA_2      5      // Pin ENA3 del puente en H
#define pinB_2      6      // Pin ENA4 del puente en H
#define pinPWM_2    PIN_SIN_DEFINIR       // Pin ENA del L293D (ENABLE2)

//Motor Vertical
#define pinA_3      7      // Pin ENA1 del puente en H 
#define pinB_3      8      // Pin ENA2 del puente en H
#define pinPWM_3    PIN_SIN_DEFINIR       // Pin ENA del L293D (ENABLE3)

Motor motorDerecho(pinA_1, pinB_1, pinPWM_1);
// class Motor motorDerecho(pinA_1, pinB_1, pinPWM_1);
// no es necesario poner el class
Motor motorIzquierdo(pinA_2, pinB_2, pinPWM_2);
//class Motor motorIzquierdo(pinA_2, pinB_2, pinPWM_2);
Motor motorVertical(pinA_3, pinB_3, pinPWM_3);
//class Motor motorIzquierdo(pinA_2, pinB_2, pinPWM_ 2);

#define MANDO_PROFUNDIDAD_PIN_X     A0  // VRx del mando a pin analogico A0 del arduino
#define MANDO_PROFUNDIDAD_PIN_Y     A1  // VRy del mando a pin analogico A1 del Arduino
#define MANDO_PROFUNDIDAD_PIN_P1    PIN_SIN_DEFINIR   // SW  del mando a pin digital 8 del Arduino
#define MANDO_PROFUNDIDAD_CONF      CONF_MANDO_POR_DEFECTO  // por si queremos invertir el mando

#define MANDO_AVANCE_PIN_X     A2  // VRx del mando a pin analogico A2 del arduino
#define MANDO_AVANCE_PIN_Y     A3  // VRy del mando a pin analogico A3 del Arduino
#define MANDO_AVANCE_PIN_P1    PIN_SIN_DEFINIR   // SW  del mando a pin digital 9 del Arduino
#define MANDO_AVANCE_CONF      CONF_MANDO_POR_DEFECTO       // por si queremos invertir el mando

// Configuración alternativa
// (probar a combinar diferentes CONF_MANDO_XXXX) definidos en mando.h
// #define MANDO_DERECHO_CONF      CONF_MANDO_INV_X | CONF_MANDO_INV_Y | CONF_MANDO_INV_P1

//Mando mandoDerecho(MANDO_DERECHO_PIN_X, MANDO_DERECHO_PIN_Y, MANDO_DERECHO_PIN_P1);



Mando mandoProfundidad(MANDO_PROFUNDIDAD_PIN_X, MANDO_PROFUNDIDAD_PIN_Y, MANDO_PROFUNDIDAD_PIN_P1);
Mando mandoAvance(MANDO_AVANCE_PIN_X, MANDO_AVANCE_PIN_Y, MANDO_AVANCE_PIN_P1);

accion_mando_t estadoMandoProfundidad = ACCION_MANDO_PARAR;
accion_mando_t estadoMandoAvance = ACCION_MANDO_PARAR;

void controlMandoProfundidad() {
    accion_mando_t estadoActualDelMando = mandoProfundidad.getAccion();
    if (estadoMandoProfundidad != estadoActualDelMando) { // comprobamos si ha cambiado de estado
        estadoMandoProfundidad = estadoActualDelMando;
        switch (mandoProfundidad.getAccion()) {
            case ACCION_MANDO_AVANZAR :
                motorVertical.avanzar();
                break;
            case ACCION_MANDO_RETROCEDER :
                motorVertical.retroceder();
                break;
            case ACCION_MANDO_PARAR :
            case ACCION_MANDO_AVANZAR_DERECHA :
            case ACCION_MANDO_DERECHA :
            case ACCION_MANDO_RETROCEDER_DERECHA :
            case ACCION_MANDO_RETROCEDER_IZQUIERDA :
            case ACCION_MANDO_IZQUIERDA :
            case ACCION_MANDO_AVANZAR_IZQUIERDA :
                motorVertical.parar();
                break;
        }
    }
}

void controlMandoAvance() {
    accion_mando_t estadoActualDelMando = mandoAvance.getAccion();
    if (estadoMandoAvance != estadoActualDelMando) { // comprobamos si ha cambiado de estado
        estadoMandoAvance = estadoActualDelMando;
        switch (estadoMandoAvance) {
            case ACCION_MANDO_PARAR :
                motorIzquierdo.parar();
                motorDerecho.parar();
                break;
            case ACCION_MANDO_AVANZAR :
                motorIzquierdo.avanzar();
                motorDerecho.avanzar();
                break;
            case ACCION_MANDO_RETROCEDER :
                motorIzquierdo.retroceder();
                motorDerecho.retroceder();
                break;
            case ACCION_MANDO_AVANZAR_DERECHA :
            case ACCION_MANDO_DERECHA :
            case ACCION_MANDO_RETROCEDER_IZQUIERDA :
                motorIzquierdo.avanzar();
                motorDerecho.retroceder();
                break;
            case ACCION_MANDO_RETROCEDER_DERECHA :
            case ACCION_MANDO_IZQUIERDA :
            case ACCION_MANDO_AVANZAR_IZQUIERDA :
                motorIzquierdo.retroceder();
                motorDerecho.avanzar();
                break;
        }
    }
}

void setup() {
    mandoProfundidad.init(MANDO_PROFUNDIDAD_CONF);
    mandoAvance.init(MANDO_AVANCE_CONF);
}


void loop() {
     controlMandoProfundidad();
     controlMandoAvance();
}

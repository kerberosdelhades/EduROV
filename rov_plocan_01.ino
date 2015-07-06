

/*

    Usando el constructor

 */

#define pinA_1      3      // Pin 2 del L293D (IN1)
#define pinB_1      4      // Pin 9 del L293D (IN2)
// #define pinPWM_1    POR_DEFINIR       // Pin 1 del L293D (ENABLE1)

#define pinA_2      5      // Pin 12 del L293D (IN3)
#define pinB_2      6      // Pin 19 del L293D (IN4)
// #define pinPWM_2    POR_DEFINIR       // Pin 11 del L293D (ENABLE2)

#define pinA_3      7      // Pin 12 del L293D (IN3)
#define pinB_2      8      // Pin 19 del L293D (IN4)

class Motor {
    private:
        int pinA;
        int pinB;
        int pinPWM;
    public:
        void avanzar();
        void parar();
        Motor(int pinA, int pinB, int pinPWM);
};

void Motor::avanzar() {
    digitalWrite(this->pinA, HIGH);
    digitalWrite(this->pinB, LOW);
    digitalWrite(this->pinPWM, 255);
}

void Motor::parar() {
    digitalWrite(this->pinA, LOW);
    digitalWrite(this->pinB, LOW);
    digitalWrite(this->pinPWM, 0);
}

Motor::Motor(int pinA, int pinB, int pinPWM) { //no lleva tipo
    this->pinA = pinA;
    this->pinB = pinB;
    this->pinPWM = pinPWM;
    this->parar();
    pinMode(this->pinA, OUTPUT);
    pinMode(this->pinB, OUTPUT);
    pinMode(this->pinPWM, OUTPUT);
}

Motor motorDerecho(pinA_1, pinB_1, pinPWM_1);
// class Motor motorDerecho(pinA_1, pinB_1, pinPWM_1);
// no es necesario poner el class
Motor motorIzquierdo(pinA_2, pinB_2, pinPWM_2);
//class Motor motorIzquierdo(pinA_2, pinB_2, pinPWM_2);

void setup() {


}

void loop() {
    motorDerecho.avanzar();
    delay(1000);

    motorDerecho.parar();
    delay(1000);

    motorIzquierdo.avanzar();
    delay(1000);

    motorIzquierdo.parar();
    delay(1000);

    motorDerecho.avanzar();
    motorIzquierdo.avanzar();
    delay(1000);

    motorDerecho.parar();
    motorIzquierdo.parar();
    delay(500000);
}

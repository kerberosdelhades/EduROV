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

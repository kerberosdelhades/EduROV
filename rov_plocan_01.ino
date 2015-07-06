

/*

    Usando el constructor

 */


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

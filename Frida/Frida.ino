#include <NewPing.h>

#define TRIG_F 12
#define ECHO_F 2

#define TRIG_I 11
#define ECHO_I 8

#define TRIG_D 10
#define ECHO_D 13

// Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
#define MAX_DISTANCE 400

// Ultrasonicos
NewPing ULTRA_FRENTE(TRIG_F, ECHO_F, MAX_DISTANCE);
NewPing ULTRA_IZQUIERDA(TRIG_I, ECHO_I, MAX_DISTANCE);
NewPing ULTRA_DERECHA(TRIG_D, ECHO_D, MAX_DISTANCE);

// Motores
const int VEL_MOTOR = 120;

//********************************************
//----------------- MOTORES ------------------
#define Pin1_DERECHA 6
#define Pin2_DERECHA 9

#define Pin1_IZQUIERDA 5
#define Pin2_IZQUIERDA 3

void avanzar(int vel) {
    digitalWrite(Pin1_DERECHA, 0);
    digitalWrite(Pin1_IZQUIERDA, 0);

    digitalWrite(Pin2_DERECHA, vel);
    digitalWrite(Pin2_IZQUIERDA, vel);
}

void reversa(int vel) {
    digitalWrite(Pin1_DERECHA, vel);
    digitalWrite(Pin1_IZQUIERDA, vel);

    digitalWrite(Pin2_DERECHA, 0);
    digitalWrite(Pin2_IZQUIERDA, 0);
}

void giraDerecha(int vel) {
    digitalWrite(Pin1_DERECHA, vel);
    digitalWrite(Pin1_IZQUIERDA, 0);

    digitalWrite(Pin2_DERECHA, 0);
    digitalWrite(Pin2_IZQUIERDA, vel);
}

void giraIzquierda(int vel) {
    digitalWrite(Pin1_DERECHA, 0);
    digitalWrite(Pin1_IZQUIERDA, vel);

    digitalWrite(Pin2_DERECHA, vel);
    digitalWrite(Pin2_IZQUIERDA, 0);
}


// ULTRASONICOS
int getUltrasonico(char cSentido) {
    switch(cSentido) {
        case 'F':
            return ULTRA_FRENTE.ping_cm();

        case 'I':
            return ULTRA_IZQUIERDA.ping_cm();

        case 'D':
            return ULTRA_DERECHA.ping_cm();
    }
}

void setup() {
  Serial.begin(9600);

}

void loop() {
  giraIzquierda(255);
}

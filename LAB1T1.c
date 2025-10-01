#include <xc.h>

#include <p32xxxx.h>

#include <stdint.h>


//Uma.S and Manha.N - Section 1 - BME538 - Lab#1

void msDelay(int msec)
 {

    int i, j;

    for (i = 0; i < msec; i++) {

        for (j = 0; j < 50; j++) {

        }

    }

}

void ledsOn(void)
 {

    LATAbits.LATA0 = 1;

    LATAbits.LATA1 = 1;

    LATAbits.LATA4 = 1;

    LATAbits.LATA5 = 1;

}

void ledsOff(void)
 {

    LATAbits.LATA0 = 0;

    LATAbits.LATA1 = 0;

    LATAbits.LATA4 = 0;

    LATAbits.LATA5 = 0;

}

void flashL(void) {

    ledsOn();
    msDelay(1000);

    ledsOff();
    msDelay(500);

}

void flashS(void) {

    ledsOn();
    msDelay(500);

    ledsOff();
    msDelay(500);

}

void pause(void) {

    msDelay(3000);

}

int main(void) {



    DDPCONbits.JTAGEN = 0;




    TRISA = 0x0000;

    LATA = 0x0000;


    ledsOff();


    while (1) {

        // Long + Short

        flashL();

        flashS();

        pause();


        // Long + Short + Short + Short

        flashL();

        flashS();

        flashS();

        flashS();

        pause();


        // Long + Short + Long + Short

        flashL();

        flashS();

        flashL();

        flashS();

        pause();

    }

}


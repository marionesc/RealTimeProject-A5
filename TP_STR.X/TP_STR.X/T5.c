#include "T5.h"

void tache5(void)
{
    unsigned int a;
    //char message[] = "tache5_en_cours";

    while(1)
    {
        //P(SEM_RXTX);
        //while(RXTX_libre==0);
        //RXTX_libre=0;
        /*
        for (int i = 0; i < sizeof(message) - 1; i++) {
            while (PIR1bits.TX1IF == 0);
            TXREG1 = message[i];
            while (TXSTA1bits.TRMT == 0);
        }

        //RXTX_libre=1;
        //V(SEM_RXTX);
        */
        for (a = 0; a < 65000; a++)
            ;
    }
}
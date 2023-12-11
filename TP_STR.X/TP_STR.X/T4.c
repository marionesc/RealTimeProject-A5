#include "T4.h"

void tache4(void)
{
    unsigned int a;
    char message= "Test";

    while(1)
    {
        //P(SEM_RXTX);
        //while(RXTX_libre==0);
        //RXTX_libre=0;

        afficheur_texte(message);

        //RXTX_libre=1;
        //V(SEM_RXTX);

        for (a = 0; a < 65000; a++)
            ;
    }
}

#include "T6.h"

void tache6(void)
{
    unsigned char n;
    while(1)
    {
        n = lecture_normale(badge);
        if (n > 0)
        {
            if (n == 4)
            {
                n_octet_badge = n;
                // goto_lico(12,0);
                // draw_hex8(n);
                Personne = 2;
            }
            else if (n == 8) // 
            {
                n_octet_badge = n;
                Personne = 1;
            }
            else
            {
                n_octet_badge = 0;
                // goto_lico(12,0);
                // draw_string("dze");
            }
        }
        else
        {
            n_octet_badge = 0;
            Personne = 0;
        }
    }
}

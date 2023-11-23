#include "T3.h"

void tache3(void)
{
    while(1)
    {
        if (TP_appui==1)
        {
            if ((TP_x>=203)&&(TP_x<209))
            {
                if ((TP_y>=113)&&(TP_y<121))
                {
                    LED_R=1;
                }
                if ((TP_y>=121)&&(TP_y<127))
                {
                    LED_R=0;
                }
            }
        }
        
        
        
        if (TP_appui==1)
        {
            if ((TP_x>=215)&&(TP_x<221))
            {
                if ((TP_y>=113)&&(TP_y<121))
                {
                    LED_G=1;
                }
                if ((TP_y>=121)&&(TP_y<127))
                {
                    LED_G=0;
                }
            }
        }
        if (TP_appui==1)
        {
            if ((TP_x>=227)&&(TP_x<233))
            {
                if ((TP_y>=113)&&(TP_y<121))
                {
                    LED_B=1;
                }
                if ((TP_y>=121)&&(TP_y<127))
                {
                    LED_B=0;
                }
            }
        }
       
        //draw_square(180,20,230,60);
        //draw_square(120,20,170,60);       
        if (TP_appui==1)
        {
            if((TP_x>=180)&&(TP_x<230))
            {
                if ((TP_y>=20)&&(TP_y<60))
                {
                    LED_R=0;LED_G=1;LED_B=1; //RED
                    TEST = 1;
                }
            } else{
        }   
        }
        if (TP_appui==1)
        {
            if((TP_x>=120)&&(TP_x<170))
            {
                if ((TP_y>=20)&&(TP_y<60))
                {
                    LED_R=0;LED_G=0;LED_B=0;
                    TEST = 0;
                }
            } else{
                
        
           // clear_text();
           //clear_line(14); // Efface la première ligne
           //goto_lico(14,0);
           //  draw_string("TOM LE ....");

            }           

        }
    }
}
#include "T1.h"

void tache1(void)
{
    unsigned char i;

    di();
    initialisation_afficheur();
    clear_text();
    clear_graphics();
    init_rxtx();
    Init(SEM_RXTX);
    RXTX_libre=1;
    TXREG1='R';
    ei();

    LED_R=0;LED_G=0;LED_B=0;

    vitesse=0;
    batterie=15;
    n_octet_badge=0;

    goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
    goto_lico(14,34);draw_char('0');draw_char(' ');draw_char('0');draw_char(' ');draw_char('0');
    goto_lico(15,34);draw_char('1');draw_char(' ');draw_char('1');draw_char(' ');draw_char('1');

    TP_appui=0;
      draw_square(180,20,230,60);
        draw_square(120,20,170,60);
        //draw_filled_square(90,30,190,90);
        draw_string(2);
        TEST=0;
    while(1)
    {

        goto_lico(0,0);
        draw_string("Marche:");
        if (MARCHE_AVANT==0)
            draw_string("AV");
        else
            if (MARCHE_ARRIERE==0)
                draw_string("AR");
            else
                draw_string("N ");

        goto_lico(1,0);
        draw_string("Siege:");
        if (SIEGE==0)
        {draw_char('1');}
        else
        {draw_char('0');}

        goto_lico(2,0);
        draw_string("Temp. Eau:");
        draw_hex8(lecture_8bit_analogique(TEMPERATURE_EAU));

        goto_lico(3,0);
        draw_string("Temp. Huile:");
        draw_hex8(lecture_8bit_analogique(TEMPERATURE_HUILE));

        goto_lico(4,0);
        draw_string("Choc:");
        if (CHOC==0)
            draw_char('1');
        else
            draw_char('0');

        goto_lico(5,0);
        draw_string("Vitesse:");
        
        if(TEST==1){
        if (VITESSE_PLUS==0 && vitesse < 15)
            vitesse++;
        if (VITESSE_MOINS == 0 && vitesse > 0) {
            vitesse--;
        }
        } else{
        if (VITESSE_PLUS==0 && vitesse < 25)
            vitesse++;
        if (VITESSE_MOINS == 0 && vitesse > 0) {
            vitesse--;
        }
        }  
        
        
        
        draw_hex8(vitesse);
        
        goto_lico(6,0);
        draw_string("Batterie:");
        if (BATTERIE_PLUS==0 && batterie < 100)
            batterie++;
        if (BATTERIE_MOINS==0 && batterie > 0)
            batterie--;
        draw_hex8(batterie);

        goto_lico(7,0);
        if (FREIN_A_MAIN==0)
            draw_string("((!))");
        else
            draw_string("     ");

        goto_lico(8,0);
        draw_string("Badge:");
        if (n_octet_badge==0)
            draw_string(" AUCUN              ");
        else
        {
            for (i=0;i<n_octet_badge;i++)
            {
                draw_hex8(badge[i]);
            }
        }

        goto_lico(9,0);
        draw_string("X-Joystick:");
        draw_hex8(lecture_8bit_analogique(JOYSTICK_X));

        goto_lico(10,0);
        draw_string("Y-Joystick:");
        draw_hex8(lecture_8bit_analogique(JOYSTICK_Y));

        goto_lico(13,0);
        draw_string("BIG MUM");
        goto_lico(5,22);
        draw_string("VIDE");
        goto_lico(5,31);
        draw_string("CHARGER");
        //draw_square(90,30,190,90);
        //draw_filled_square(90,30,190,90);

        
        
        
        
        if (TP_appui==1)
        {
            goto_lico(0,20);
            draw_string("x=");
            draw_hex8(TP_x);
            draw_string(" y=");
            draw_hex8(TP_y);
            plot1(TP_x,TP_y);
        }
        else
        {
            Nop();
        }
        if (TEST==1){
            charger();
        }
        if(TEST==0){
            clear_line(14);
            vide();
            TEST=3;
        }
        
    }
}
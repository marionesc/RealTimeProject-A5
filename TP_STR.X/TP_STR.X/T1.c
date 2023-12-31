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
    //batterie=eeprom_read(0x74);
    n_octet_badge=0;
    TEST=0;
    Personne=0;
    
    goto_lico(13,34);draw_char('R');draw_char(' ');draw_char('V');draw_char(' ');draw_char('B');
    goto_lico(14,34);draw_char('0');draw_char(' ');draw_char('0');draw_char(' ');draw_char('0');
    goto_lico(15,34);draw_char('1');draw_char(' ');draw_char('1');draw_char(' ');draw_char('1');

    TP_appui=0;

   // int y2=100;
    x1=160;
    x2=190;
    y1=100;
    
    goto_lico(12, 19);
    draw_string("0----0-");
    goto_lico(11, 20);
    draw_string("|_o");
    goto_lico(10, 19);
    draw_string("/^^^-");
    draw_square(180,20,230,60);
    draw_square(120,20,170,60);
    draw_square(160,80,160,100);
    draw_square(x1,y1,x2,y1); 

    //draw_filled_square(90,30,190,90);
    draw_string(2);

while(1)
{

    goto_lico(0, 0);
    draw_string("Marche:");
    goto_lico(7, 0);
    if (FREIN_A_MAIN == 0)
    {
        draw_string("((!))");
        __delay_ms(5);
        vitesse = Diminution(vitesse);
    }
    else
    {
        draw_string("     ");
    }

    goto_lico(1, 0);
    draw_string("Siege:");
    if (SIEGE == 0)
    {
        {draw_char('1');}
        marche();
    }
    else
    {
        {draw_char('0');}
        __delay_ms(50);
        vitesse = Diminution(vitesse);
    }

    goto_lico(2, 0);
    draw_string("Temp. Eau:");
    draw_dec8(Conversion(lecture_8bit_analogique(TEMPERATURE_EAU)));

    goto_lico(3, 0);
    draw_string("Temp. Huile:");
    draw_dec8(Conversion(lecture_8bit_analogique(TEMPERATURE_HUILE)));

    goto_lico(4, 0);
    draw_string("Choc:");
    if (CHOC == 0)
    {
        draw_char('1');
    }
    else
    {
        draw_char('0');
    }

    if (Personne == 2)
    {
        vitesseAdmin(Personne);
    }
    else if (Personne == 1)
    {
        vitesseAdmin(Personne);
    }
    else
    {
    }

    goto_lico(5, 0);
    draw_string("Vitesse:");
    draw_dec8(vitesse);

    goto_lico(6, 0);
    draw_string("Batterie:");
    if (BATTERIE_PLUS == 0 && batterie < 100)
    {
        batterie++;
    }
    if (BATTERIE_MOINS == 0 && batterie > 0)
    {
        batterie--;
    }
    draw_dec8(batterie);

    goto_lico(8, 0);
    draw_string("Badge:");
    if (n_octet_badge == 0)
    {
        draw_string(" AUCUN              ");
    }
    else
    {/*
        for (i = 0; i < n_octet_badge; i++)
        {
            draw_hex8(badge[i]);
            
        }
       */        
        if (Personne == 2)
        {
            draw_string("Operator");
        }
        else if (Personne == 1)
        {
            draw_string(" ADMIN");
        } 
        else if (Personne == 0)
        {
            draw_string("AUCUN");
        }
    }

    //goto_lico(12,0);
    // draw_dec8(Valeur);

    goto_lico(9, 0);
    draw_string("X-Joystick:");
    draw_hex8(lecture_8bit_analogique(JOYSTICK_X));

    goto_lico(10, 0);
    draw_string("Y-Joystick:");
    draw_hex8(lecture_8bit_analogique(JOYSTICK_Y));

    goto_lico(5, 22);
    draw_string("VIDE");
    goto_lico(5, 31);
    draw_string("CHARGE");
    //draw_square(90, 30, 190, 90);
    //draw_filled_square(90, 30, 190, 90);
    if(lecture_8bit_analogique(JOYSTICK_Y)>180){
        

        //x1=x1--;
        //x2=x2--;
        if(y1>80){        
        clear_square(x1,y1,x2+1,y1);
        y1=y1--;
        
        draw_square(x1,y1,x2,y1);
        }
        //draw_square(160,150,190,150);
            goto_lico(9, 31);
            draw_string("up  ");
    }else {
    }
    
    if(lecture_8bit_analogique(JOYSTICK_Y)<100){
        
        
        //x1=x1--;
        //x2=x2--;
        if(y1<100){
        clear_square(x1,y1,x2+1,y1);
        y1=y1++;
        draw_square(x1,y1,x2,y1);
        }
            goto_lico(9, 31);
            draw_string("down");
    }else{
    }
    
    if (TP_appui == 1)
    {
        goto_lico(0, 20);
        draw_string("x=");
        draw_hex8(TP_x);
        draw_string(" y=");
        draw_hex8(TP_y);
        plot1(TP_x, TP_y);
    }
    else
    {
        Nop();
    }
    if (TEST == 1)
    {
        charger();
        //clear_square(160,80,160,100);
    }
    if (TEST == 0)
    {
        clear_line(14);
        vide();
        TEST = 3;
    }
}
}
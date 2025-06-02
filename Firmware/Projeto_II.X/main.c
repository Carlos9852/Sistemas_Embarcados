/*==============================================================================
    Sistemas Embarcados e Microcontroladores
    Relógio completo: Projeto II
    
    Author: Carlos Daniel de Souza Nunes
    Date: 01/06/2025
==============================================================================*/
 
  
//==============================================================================
//  --- libraries ---
#include "config.h"         //Inclue as configurações de inicializalção do pic 


//==============================================================================
//  --- Main ---
void main(void) {
    unsigned char display[10] = { //Vetor com o byte correspondente a cada número
      0b11111100,           //Escreve o caracter 0 no display de 7 segmentos
      0b01100000,           //Escreve o caracter 1 no display de 7 segmentos
      0b11011010,           //Escreve o caracter 2 no display de 7 segmentos
      0b11110010,           //Escreve o caracter 3 no display de 7 segmentos
      0b01100110,           //Escreve o caracter 4 no display de 7 segmentos
      0b10110110,           //Escreve o caracter 5 no display de 7 segmentos
      0b10111110,           //Escreve o caracter 6 no display de 7 segmentos
      0b11100000,           //Escreve o caracter 7 no display de 7 segmentos
      0b11111110,           //Escreve o caracter 8 no display de 7 segmentos
      0b11110110            //Escreve o caracter 9 no display de 7 segmentos
    };
    
    char disp1  = 00,       //Contador do display 1
         disp2  = 00,       //Contador do display 2
         disp3  = 00,       //Contador do display 3
         disp4  = 00,       //Contador do display 4
         disp5  = 00,       //Contador do display 5
         disp6  = 00,       //Contador do display 6
         hour   = 11,       //Váriável que armazena as horas
         minute = 59,       //Váriável que armazena os minutos
         second = 50,       //Váriável que armazena os segundos
         mode   = 01;       //Váriavel que define o modo 24/12 horas(1 = 12h / 0 = 24h)
    
    TRISB = 0;              //Configura todos os pinos do PORTB como saída
    TRISD = 0;              //Configura todos os pinos do PORTD como saída
    LATD = 0;               //Inicializa PORTD com nível lógico baixo
    LATB = 0;               //Inicializa PORTB com nível lógico baixo
    
    
//==============================================================================
//  --- Loop ---
    while(1){
        disp1 = second % 10;        //Armazena a unidade de second no disp1
        disp2 = second / 10;        //Armazena a dezena de second no disp2
        disp3 = minute % 10;        //Armazena a unidade de minute no disp3
        disp4 = minute / 10;        //Armazena a dezena de minute no disp4
        disp5 = hour % 10;          //Armazena a unidade de hour no disp5
        disp6 = hour / 10;          //Armazena a dezena de hour no disp6
        
        int cont;                   //Auxiliar para contador no laço for
        for(cont = 0; cont < 200; cont++){
            LATD = 0b10000000;      //Ativa o display 1
            LATB = display[disp1];  //Escreve o valor no display 1
            __delay_us(850);        //Aguarda 850 microssegundos
            LATD = 0b01000000;      //Ativa o display 2
            LATB = display[disp2];  //Escreve o valor no display 2
            __delay_us(850);        //Aguarda 850 microssegundos
            LATD = 0b00100000;      //Ativa o display 3
            LATB = display[disp3];  //Escreve o valor no display 3
            __delay_us(850);        //Aguarda 850 microssegundos
            LATD = 0b00010000;      //Ativa o display 4
            LATB = display[disp4];  //Escreve o valor no display 4
            __delay_us(850);        //Aguarda 850 microssegundos
            LATD = 0b00001000;      //Ativa o display 5
            LATB = display[disp5];  //Escreve o valor no display 5
            __delay_us(800);        //Aguarda 500 microssegundos
            LATD = 0b00000100;      //Ativa o display 6
            LATB = display[disp6];  //Escreve o valor no display 6
            __delay_us(800);        //Aguarda 500 microssegundos
        }//end for
        
        second++;                   //Incrementa o valor do display 1 em um
        
        if(second == 60){           //second é igual a 60?
            second = 0;             //Se sim, zera second
            minute++;               //Incrementa minute em um
        }//end if
        if(minute == 60){          //minute é igual a 60?
            minute = 0;            //Se sim, zera minute
            hour++;                //Incrementa hour em um
        }//end if
        if(mode){                  //mode é igual verdadeiro?
            if(hour == 12)hour = 0;//Se sim, zera hour quando for igual a 12
        }//end if
        else{                      //Senão
            if(hour == 24)hour = 0;//Zera hour quando for igual a 24
        }//end else
    }//end Loop
}//end Main


/* ============================================================================  
                                                              
                                       _                      
                                      / \                     
                                     |oo >                   
                                     _\=/_                    
                    ___         #   /  _  \   #              
                   /<> \         \\//|/.\|\\//               
                 _|_____|_        \/  \_/  \/                
                | | === | |          |\ /|                   
                |_|  0  |_|          \_ _/                   
                 ||  0  ||           | | |                   
                 ||__*__||           | | |                   
                |* \___/ *|          []|[]                   
                /=\ /=\ /=\          | | |                   
________________[_]_[_]_[_]_________/_]_[_\_______________________________                                                  
============================================================================ */
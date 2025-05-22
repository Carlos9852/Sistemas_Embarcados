/*==============================================================================
    Sistemas Embarcados e Microcontroladores
    Display de 7 segmentos com cátodo comum
    
    Author: Carlos Daniel de Souza Nunes
    Date: 21/05/2025
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
    TRISB = 0;              //Configura todos os pinos do PORTB como saída
    LATB = 0;               //Inicializa PORTB com nível lógico baixo
    
    
//==============================================================================
//  --- Loop ---
    while(1){
        int i;
        for(i=0; i<10; i++){
            LATB = display[i];
            __delay_ms(1000);
        }//end for
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
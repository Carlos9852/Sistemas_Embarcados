/*==============================================================================
    Sistemas Embarcados e Microcontroladores
    Display de 7 segmentos multiplexado
    
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
    int disp1 = 0,          //Contador do display 1
        disp2 = 0;          //Contador do display 2
    TRISB = 0;              //Configura todos os pinos do PORTB como saída
    TRISD = 0;              //Configura todos os pinos do PORTD como saída
    LATD = 0;               //Inicializa PORTD com nível lógico baixo
    LATB = 0;               //Inicializa PORTB com nível lógico baixo
    
    
//==============================================================================
//  --- Loop ---
    while(1){
        int cont = 0;       //Inicializa Contador do while como 0;
        
        while(cont < 100){
            LATD = 0b00000100;      //Ativa o display 1
            LATB = display[disp1];  //Escreve o valor no display 1
            __delay_ms(5);          //Aguarda 5 milissegundos
            LATD = 0b00001000;      //Ativa o display 2
            LATB = display[disp2];  //Escreve o valor no display 2
            __delay_ms(5);          //Aguarda 5 milissegundos
            cont++;                 //Incrementa o contador em um
        }//end while
        disp1++;                    //Incrementa o valor do display 1 em um
        if(disp1 > 9){              //O valor do display 1 é maior que 9?
            disp1 = 0;              //Zera o valor do display 1
            disp2++;                //Incrementa o valor do display 2 em um
        }//end if
        if(disp2 == 6) disp2 = 0; //Se display 2 for maior que 6, sera o mesmo
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
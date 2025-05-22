/*==============================================================================
    Sistemas Embarcados e Microcontroladores
    Projeto I
    
    Author: Carlos Daniel de Souza Nunes
    Date: 10/05/2025
==============================================================================*/
 
  
//==============================================================================
//  --- libraries ---
#include "config.h"         //Inclue as configurações de inicializalção do pic 


//==============================================================================
//  --- Main ---
void main(void) {
    TRISB = 0;              //Configura todos os pinos do PORTB como saída
    LATB = 0;               //Inicializa PORTB com nível lógico baixo
    
    
//==============================================================================
//  --- Loop ---
    while(1){
        LATB = 0b00110000;  //Liga o sinal verde1 e vermelho2
        __delay_ms(7000);   //Espera por 7 segundos
        LATB = 0b01010000;  //Desliga o sinal verde1 e liga amarelo1 (mantém vermelho2 aceso)
        __delay_ms(1000);   //Espera por 1 segundo
        LATB = 0b10000100;  //Liga o sinal verde2 e vermelho1
        __delay_ms(7000);   //Espera por 7 segundos
        LATB = 0b10001000;  //Desliga o sinal verde2 e liga amarelo2 (mantém vermelho1 aceso)
        __delay_ms(1000);   //Espera por 1 segundo
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

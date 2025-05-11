/* ============================================================================
    Sistemas Embarcados e Microcontroladores
    Projeto I
    
    Author: Carlos Daniel de Souza Nunes
    Date: 10/05/2025
============================================================================ */


/* ========================================================================= */
/* --- Libraries --- */
#include "config.h"


/* ========================================================================= */
/* --- Function Main --- */
void main(void) {
    int redLed_1 = 2,
        yellowLed_1 = 1,
        greenLed_1 = 0,
        redLed_2 = 5,
        yellowLed_2 = 4,
        greenLed_2 = 3;
    
    //Configuração para o primeiro semáforo
    resetBit(TRISB, redLed_1);
    resetBit(LATB, redLed_1);
    resetBit(TRISB, yellowLed_1);
    resetBit(LATB, yellowLed_1);
    resetBit(TRISB, greenLed_1);
    resetBit(LATB, greenLed_1);
    
    //Configuração para o segundo semáforo
    resetBit(TRISB, redLed_2);
    resetBit(LATB, redLed_2);
    resetBit(TRISB, yellowLed_2);
    resetBit(LATB, yellowLed_2);
    resetBit(TRISB, greenLed_2);
    resetBit(LATB, greenLed_2);

    
/* ========================================================================= */
/* --- Loop --- */
    while(1){
        
        setBit(LATB, greenLed_1);
        resetBit(LATB, yellowLed_1);
        resetBit(LATB, redLed_1);
        setBit(LATB, redLed_2);
        resetBit(LATB, greenLed_2);
        resetBit(LATB, yellowLed_2);
        __delay_ms(7000);
        
        setBit(LATB, yellowLed_1);
        resetBit(LATB, redLed_1);
        resetBit(LATB, greenLed_1);
        setBit(LATB, redLed_2);
        resetBit(LATB, greenLed_2);
        resetBit(LATB, yellowLed_2);
        __delay_ms(1000);
        
        setBit(LATB, redLed_1);
        resetBit(LATB, greenLed_1);
        resetBit(LATB, yellowLed_1);
        setBit(LATB, greenLed_2);
        resetBit(LATB, redLed_2);
        resetBit(LATB, yellowLed_2);
        __delay_ms(7000);
        
        setBit(LATB, redLed_1);
        resetBit(LATB, greenLed_1);
        resetBit(LATB, yellowLed_1);
        setBit(LATB, yellowLed_2);
        resetBit(LATB, redLed_2);
        resetBit(LATB, greenLed_2);
        __delay_ms(1000);
        
    }
}


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

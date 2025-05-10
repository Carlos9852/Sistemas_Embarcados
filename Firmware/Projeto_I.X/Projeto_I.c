/*
 * File:   Projeto_I.c
 * Author: carlo
 *
 * Created on 10 de Maio de 2025, 03:44
 */


#include "config.h"
#define _XTAL_FREQ 20000000


void main(void) {
    resetBit(TRISB, 4);
    resetBit(LATB, 4);
    
    while(1){
        toggleBit(LATB, 4);
        __delay_ms(1000);
    }
}

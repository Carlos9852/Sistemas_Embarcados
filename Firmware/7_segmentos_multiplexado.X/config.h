
// PIC18F4550 Configuration Bit Settings

// 'C' source line config statements


#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)


#include <xc.h>


#include <xc.h>
#define _XTAL_FREQ 20000000

#define setBit(reg, bit) ((reg) |= (1<<bit))
#define resetBit(reg, bit) ((reg) &= ~(1<<bit))
#define toggleBit(reg, bit) ((reg) ^= (1<<bit))
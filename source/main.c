

/*	Author: klai022
 *	Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 3  Exercise 2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
int main(void) {
DDRA = 0x00; PORTA = 0xFF; 
DDRC = 0xFF; PORTC = 0x00; //C is an output

while(1) {

unsigned char input_A = PINA & 0xFF;//fuel level
unsigned char output_C = 0x00;


if((input_A & 0x01) || (input_A & 0x02)){
    output_C = output_C | 0x20;
}
else if((input_A & 0x03) || (input_A & 0x04)){
    output_C = output_C | 0x30;
}
else if((input_A & 0x05) || (input_A & 0x06)){
    output_C = output_C | 0x38;
}
else if((input_A & 0x07) || (input_A & 0x08) || (input_A & 0x09)){
    output_C = output_C | 0x3C;
}
else if((input_A & 0x0A) || (input_A & 0x0B) || (input_A & 0x0C)){
    output_C = output_C | 0x3D;
}

if((input_A & 0x01) || (input_A & 0x02) || (input_A & 0x03) || (input_A & 0x04)){
    output_C = output_C | 0x40;
}





PORTC = output_C;
}
return 0;
}


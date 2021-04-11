/*	Author: klai022
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 3  Exercise 1
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
DDRB = 0x00; PORTB = 0XFF;
DDRC = 0xFF; PORTC = 0x00; //C is an output

while(1) {

unsigned char input_A = PINA;
unsigned char input_B = PINB;

unsigned char i;
unsigned char cnt = 0x00;

for(i = 0; i < 8; i++){
	input_A = input_A >> i;
	
	if(input_A & 0x01){
	cnt++;
	}
}

for(i = 0; i < 8; i++){
        input_B = input_B >> i;

        if(input_B & 0x01){
        cnt++;
        }
}

PORTC = cnt;
}
return 0;
}

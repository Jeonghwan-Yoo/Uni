/*
 * _9_Interrupt.c
 *
 * Created: 2018-05-23 오전 9:56:04
 *  Author: 17
 */ 
#define F_CPU 14745600L
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
unsigned char SEG[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
	
ISR(INT4_vect){
	PORTB=0b11111110;
}
ISR(INT5_vect){
	PORTB=0b11111101;
}
ISR(INT6_vect){
	PORTB=0b11111011;
}
ISR(INT7_vect){
	PORTB=0b11110111;
}

int main(void)
{
	int n=0;
	DDRA=0xff;
	DDRB=0xff;
	DDRE=0x00;
	PORTE=0xf0;
	EIMSK=0b11110000;
	EICRB=0b10101010;
	SREG=0x80;
	PORTB=0xf0;
    while(1)
    {
       PORTA=SEG[n++];
	   _delay_ms(500);
	   if(n>=16) n=0; 
    }
}
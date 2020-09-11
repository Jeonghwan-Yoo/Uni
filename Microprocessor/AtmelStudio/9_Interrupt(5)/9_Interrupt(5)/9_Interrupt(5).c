/*
 * _9_Interrupt_5_.c
 *
 * Created: 2018-05-23 오전 10:42:00
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

unsigned char led=0xFE;

ISR(INT4_vect){
	led<<=1;
	led|=0b00000001;
	if(led==0xff) led=0xfe;
	PORTC=led;
	_delay_ms(100);
}

int main(void)
{
	DDRC=0xFF;
	DDRE=0x00;
	PORTC=led;
	PORTE=0xf0;
	EICRB=0b00000000;
	EIMSK=0b00010000;
	SREG=0x80;
	while(1);
}
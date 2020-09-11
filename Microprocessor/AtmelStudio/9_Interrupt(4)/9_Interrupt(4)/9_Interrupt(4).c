/*
 * _9_Interrupt_4_.c
 *
 * Created: 2018-05-23 오전 10:36:53
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
unsigned char led=0xFE;

ISR(INT4_vect){
	led=led<<1|0b00000001;
	if(led==0xff) led=0xfe;
	PORTA=led;	
}
int main(void)
{
	DDRA=0xFF;
	DDRE=0x00;
	PORTA=led;
	PORTE=0xf0;
	EICRB=0b10101010;
	EIMSK=0b00010000;
	SREG=0x80;
	
    while(1);
}
/*
 * _9_Interrupt_2_.c
 *
 * Created: 2018-05-23 오전 10:02:11
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
unsigned char SEG[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x8e};

int interval;

ISR(INT4_vect){
	interval=1;
}
ISR(INT5_vect){
	interval=2;
}
ISR(INT6_vect){
	interval=-2;
}
ISR(INT7_vect){
	interval=-1;
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
        PORTA=SEG[n];
		n=n+interval;
		if(n>=16) n=0;
		if(n<0) n=15;
		_delay_ms(1000);
    }
}
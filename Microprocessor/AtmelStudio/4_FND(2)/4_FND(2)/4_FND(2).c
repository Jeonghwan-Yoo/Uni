/*
 * _4_FND_2_.c
 *
 * Created: 2018-05-01 오전 10:54:27
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

unsigned char SEG[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};

int main(void)
{
	DDRA=0xff;
	DDRB=0xff;
	PORTB=0x00;
	int n=0;
	while(1)
	{
		PORTA=SEG[n];
		_delay_ms(1000);
		n++;
		if(n==16) n=0;
	}
	return 0;
}
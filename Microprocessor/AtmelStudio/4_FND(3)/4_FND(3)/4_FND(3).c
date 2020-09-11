/*
 * _4_FND_3_.c
 *
 * Created: 2018-05-01 오전 11:01:56
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
	DDRC=0x00;
	PORTB=0xff;
	int n=0;
	unsigned char var1;
	while(1)
	{
		PORTA=SEG[n++];
		var1=PINC&0x0f;
		if(var1==0b00000001) PORTB=0b00001110;
		else if(var1==0b00000010) PORTB=0b00001101;
		else if(var1==0b00000100) PORTB=0b00001011;
		else if(var1==0b00001000) PORTB=0b00000111;
		else PORTB=0xff;
		_delay_ms(1000);
		if(n>=16) n=0;
		
	}
	return 0;
}
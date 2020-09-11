/*
 * _3_Switch_4_.c
 *
 * Created: 2018-04-18 오전 9:30:19
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
unsigned char pattern[8]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};

int main(void)
{
	int i=0;
	DDRA=0xff;
	DDRC=0x00;
	PORTA=pattern[i];
	PORTC=0xf0;
	while(1)
	{
		while(!(~PINC&0x10));
		if(++i==8) i=0;
		PORTA=pattern[i];
	}
}
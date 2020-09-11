/*
 * _3_Switch_7_.c
 *
 * Created: 2018-04-18 오전 10:22:48
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

unsigned char pattern[8]={0xFF,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};

int main(void)
{
	int i=0;
	DDRA=0xFF;
	DDRC=0x00;
	PORTC=0xf0;
	PORTA=0xFE;
	while(1)
	{
		while(!(~PINC&0x30));
		_delay_ms(20);
		if(~PINC&0x10){
			if(++i==8) i=0; PORTA=pattern[i];
		}
		if(~PINC&0x20){
			if(-i==-1) i=7; PORTA=pattern[i];
		}
		while(~PINC&0x30);
		_delay_ms(20);
	}
}
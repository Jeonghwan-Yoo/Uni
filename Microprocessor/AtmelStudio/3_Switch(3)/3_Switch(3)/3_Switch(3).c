/*
 * _3_Switch_3_.c
 *
 * Created: 2018-04-18 오전 9:26:29
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>

int main(void)
{
	unsigned char key;
	DDRA=0xff;
	DDRC=0x00;
	PORTA=0xff;
	PORTC=0xf0;
	while(1)
	{
		key=~PINC&0x10;
		if(key)
			PORTA=0x00;
		else
			PORTA=0xff;
		
	}
}
/*
 * _3_Switch_2_.c
 *
 * Created: 2018-04-17 오전 10:57:50
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>

int main(void)
{
	unsigned char key;
	DDRA=0xff;
	DDRC=00;
	PORTA=0xff;
	while(1)
	{
		key=~PINC&0x03;
		if(key==0x01)
			PORTA=0xf0;
		else if(key==0x02)
			PORTA=0x0f;
		else if(key==0x03)
			PORTA=0x00;
		else
			PORTA=0xff;
	}
}
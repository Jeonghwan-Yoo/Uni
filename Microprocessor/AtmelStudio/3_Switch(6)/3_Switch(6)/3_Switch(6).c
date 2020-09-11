/*
 * _3_Switch_6_.c
 *
 * Created: 2018-04-18 오전 10:10:57
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>

int main(void)
{
	unsigned char key,Lout,Hout;
	DDRA=0xFF;
	DDRC=0x00;
	PORTC=0xf0;
	PORTA=0xFF;
	while(1)
	{
		key=PINC&0xF0;
		Hout=0xF0^key;
		Lout=(key>>4);
		PORTA=Hout|Lout;
	}
}
/*
 * _2_LED.c
 *
 * Created: 2018-04-11 오전 9:14:31
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRA=0xff;
	while(1)
	{
		
	PORTA=0xf0;
	_delay_ms(500);
	PORTA=0x0f;
	_delay_ms(500);
	}
	return 0;
}
/*
 * _4_FND.c
 *
 * Created: 2018-05-01 오전 10:50:37
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRA=0xff;
	DDRB=0xff;
	PORTB=0x00;
	while(1)
	{
		PORTA=0xc0;_delay_ms(1000);
		PORTA=0xf9;_delay_ms(1000);
		PORTA=0xa4;_delay_ms(1000);
		PORTA=0xb0;_delay_ms(1000);
	}
}
/*
 * _2_LED_2_.c
 *
 * Created: 2018-04-11 오전 9:30:03
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	uint8_t ledData; DDRA=0xff; ledData=0xfe;
	while(1)
	{
		PORTA=ledData;
		_delay_ms(500);
		ledData=ledData<<1;
		ledData=ledData|0b00000001;
	}
	return 0;
}
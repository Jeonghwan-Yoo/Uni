/*
 * _2_LED_4_.c
 *
 * Created: 2018-04-11 오전 9:45:15
 *  Author: 17
 */ 
#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	uint8_t ledData; DDRA=0xff; ledData=0xfe;
	int i=0;
	while(1)
	{
		PORTA=ledData;
		//_delay_ms(500);
		if(i<7)
		{
			ledData=ledData<<1;
			ledData=ledData|0b00000001;
		}
		else
		{
			ledData=ledData>>1;
			ledData=ledData|0b10000000;
		}
		if(i++==13)
			i=0;
	}
	return 0;
}
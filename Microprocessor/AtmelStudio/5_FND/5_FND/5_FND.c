/*
 * _5_FND.c
 *
 * Created: 2018-05-08 오전 10:40:27
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>
	
int main(void)
{
	unsigned char FND_DATA[11]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xff};
	int count=0;
	int num=0;
	
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0x00;
	DDRD=0xff;
	PORTC=0xf0;
	PORTB=0xff;
	PORTD=0xff;
    while(1)
    {
		while(!(~PINC&0x10));
		_delay_ms(20);
		if (count<10)
		{
			PORTB=0xfe;
			num=count%10;
			PORTA=FND_DATA[num];
			PORTD=0xfe;
			while(~PINC&0x10);
			_delay_ms(20);
		}
		else
		{
			do
			{
				while(~PINC&0x10);
				_delay_ms(3);
				PORTB=0xfe;
				num=count%10;
				PORTA=FND_DATA[num];
				_delay_ms(10);
				PORTB=0xfd;
				num=count/10;
				PORTA=FND_DATA[num];
				_delay_ms(10);
				PORTD=0xfc;
			}while(!(~PINC&0x10));
			_delay_ms(3);
		}
		count++;
		if(count==100) count=0;
		
    }
}
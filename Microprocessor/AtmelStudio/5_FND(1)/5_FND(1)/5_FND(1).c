/*
 * _5_FND_1_.c
 *
 * Created: 2018-05-09 오전 9:59:09
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

unsigned char SEG[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char FND[4]={0xfe,0xfd,0xfb,0xf7};
	
int main(void)
{
	unsigned char count=0;
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0x0f;
	PORTC=0xf0;
	PORTB=FND[0];
	PORTA=SEG[0];
	while(1)
	{
		while(!(~PINC&0x10))
		{
			PORTB=FND[0];
			PORTA=SEG[count%10];
			PORTC=0xfe;
			_delay_ms(10);
			if(count>=10)
			{
				PORTB=FND[1];
				PORTA=SEG[count/10];
				PORTC=0xfc;
				_delay_ms(10);
			}
		}
		_delay_ms(10);
		count++;
		if(count>99) count=0;
		while(~PINC&0x10)
		{
			PORTB=FND[0];
			PORTA=SEG[count%10];
			PORTC=0xfe;
			_delay_ms(10);
			if(count>=10)
			{
				PORTB=FND[1];
				PORTA=SEG[count/10];
				PORTC=0xfc;
				_delay_ms(10);
			}
		}
	
	}
	
		
	
	
}

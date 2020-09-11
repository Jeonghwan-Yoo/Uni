/*
 * _6_STOPWATCH.c
 *
 * Created: 2018-05-09 오전 10:06:48
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

unsigned char SEG[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char SEG3[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};	

int main(void)
{
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0xfe;
	DDRD=0xff;
	PORTB=0xf0;
	PORTC=0xf0;
	PORTA=SEG[0];
	PORTD=0xff;
	
	int i,num,tenNum,count=0;
	
	while(!(~PINC&0x10));
	_delay_ms(20);
	while(~PINC&0x10);
	_delay_ms(20);
	
	while(1)
	{
		PORTD=0x00;
		
		for(i=0;i<50;i++)
		{
			
			if(count<10)
			{
				PORTB=0xfb;
				num=count%10;
				PORTA=SEG3[num];
				_delay_ms(20);
			}
			else
			{
				PORTB=0xfb;
				num=count%10;
				PORTA=SEG3[num];
				_delay_ms(10);
				PORTB=0xf7;
				tenNum=count/10;
				PORTA=SEG[tenNum];
				_delay_ms(10);
			}
		}
		count++;
		if(count>=100) count=0;
	}
	return 0;
}
/*
 * _6_STOPWATCH_1_.c
 *
 * Created: 2018-05-09 오전 10:30:46
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
		for(i=0;i<50;i++)
		{
			if(count<10)
			{
				PORTB=0xfe;
				num=count%10;
				PORTA=SEG[num];
				_delay_ms(0.2);
				PORTB=0xfd;
				tenNum=0;
				PORTA=SEG[tenNum];
				_delay_ms(0.1);
			}
			else
			{
				PORTB=0xfe;
				num=count%10;
				PORTA=SEG[num];
				_delay_ms(0.1);
				PORTB=0xfd;
				tenNum=count/10;
				PORTA=SEG[tenNum];
				_delay_ms(0.1);
			}
		}
		count++;
		if(count>=100) count=0;
		while(!(~PINC&0x10)&&(count==100));
		
	}
	return 0;
}
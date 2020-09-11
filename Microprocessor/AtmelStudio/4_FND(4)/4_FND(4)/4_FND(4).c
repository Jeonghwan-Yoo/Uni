/*
 * _4_FND_4_.c
 *
 * Created: 2018-05-02 오전 9:20:23
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>

unsigned char SEG[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

int main(void)
{
	DDRA=0xff;
	DDRB=0xff;
	PORTB=0xfc;
	int i,num,tenNum,count=0;
	
	while(1)
	{
		for(i=0;i<50;i++)
		{
			if(count<10)
			{
				PORTB=0xfe;
				num=count%10;
				PORTA=SEG[num];
				_delay_ms(20);
			}
			else
			{
				PORTB=0xfe;
				num=count%10;
				PORTA=SEG[num];
				_delay_ms(10);
				PORTB=0xfd;
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
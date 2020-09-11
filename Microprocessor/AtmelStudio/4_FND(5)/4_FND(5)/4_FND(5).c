/*
 * _4_FND_5_.c
 *
 * Created: 2018-05-02 오전 10:18:58
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>
#define PHONE_NUMBER 14
unsigned char FND[4]={0xfe,0xfd,0xfb,0xf7};
unsigned char FND_DATA[12]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf,0xff};
	
int main(void)
{
	DDRA=0xff;
	DDRB=0xff;
	unsigned int delay;
	unsigned char i;
	unsigned char Phone[PHONE_NUMBER]={FND_DATA[0],FND_DATA[1],FND_DATA[0],FND_DATA[10],FND_DATA[7],FND_DATA[3],FND_DATA[3],FND_DATA[0],FND_DATA[10],FND_DATA[5],
										FND_DATA[6],FND_DATA[3],FND_DATA[9],FND_DATA[11]};
	
	while(1)
	{
		for(i=0;i<PHONE_NUMBER; i++)
		{
			for(delay=0;delay<50;delay++)
			{
				PORTB=FND[3];
				PORTA=Phone[i%PHONE_NUMBER];
				_delay_ms(5);
				PORTB=FND[2];
				PORTA=Phone[(i+1)%PHONE_NUMBER];
				_delay_ms(5);
				PORTB=FND[1];
				PORTA=Phone[(i+2)%PHONE_NUMBER];
				_delay_ms(5);
				PORTB=FND[0];
				PORTA=Phone[(i+3)%PHONE_NUMBER];
				_delay_ms(5);
			}
		}
	}
}
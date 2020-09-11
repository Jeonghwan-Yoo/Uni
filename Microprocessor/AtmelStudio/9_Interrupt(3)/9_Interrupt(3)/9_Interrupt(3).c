/*
 * _9_Interrupt_3_.c
 *
 * Created: 2018-05-23 오전 10:19:58
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

ISR(INT4_vect){
	EICRB=0b00000000;
}

int main(void)
{
	unsigned char led=0xfe;
	DDRA=0xff;
	DDRE=0x00;
	PORTE=0xf0;
	EIMSK=0b00010000;
	EICRB=0b10101010;
	SREG=0x80;
	
    while(1)
    {
        PORTA=led;
		_delay_ms(100);
		led=(led<<1)|0b000001;
		if(led==0xff){
			led=0xfe; 
		}
    }
}
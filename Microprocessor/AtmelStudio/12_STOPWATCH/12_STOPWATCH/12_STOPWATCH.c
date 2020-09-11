/*
 * _12_STOPWATCH.c
 *
 * Created: 2018-06-05 오전 11:30:47
 *  Author: 17
 */ 
#define F_CPU 14745600L
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

unsigned char SEG[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char time_10ms=0, time_100ms=0, time_1s=0, time_10s=0;
unsigned char time_stop=1;

ISR(INT4_vect){
	SREG=0x70;
	if(time_stop==0) time_stop=1;
	else time_stop=0;
	SREG=0x80;
}
ISR(INT5_vect){
	SREG=0x70; time_10ms=0; time_100ms=0;
	time_1s=0; time_10s=0; PORTC=0xff;
	SREG=0x80;
}
int main(void)
{
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0xff;
	DDRE=0x00;
	PORTE=0xf0;
	EIMSK=0b11110000;
	EICRB=0b10101010;
	PORTB=0xf0;
	PORTC=0xf8;
	time_stop=1;
	
    while(1)
    {
        PORTB=0xfe;
		PORTA=SEG[time_10ms];
		PORTB=0xfd;
		PORTA=SEG[time_100ms];
		PORTB=0xfb;
		PORTA=SEG[time_1s];
		PORTB=0xf7;
		PORTA=SEG[time_10s];
		_delay_ms(2);
		if(time_stop==1) continue;
		time_10ms++;
		if(time_10ms==10){
			time_10ms=0;
			time_100ms++;
			PORTC^=(1<<PORTC0);
		}
		if(time_100ms==10){
			time_100ms=0;
			time_1s++;
			PORTC^=(1<<PORTC1);
		}
		if(time_1s==10){
			time_1s=0;
			time_10s++;
			PORTC^=(1<<PORTC2);
		}
	}
 
}
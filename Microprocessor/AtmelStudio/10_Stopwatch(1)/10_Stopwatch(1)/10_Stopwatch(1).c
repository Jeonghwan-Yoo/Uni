/*
 * _10_Stopwatch.c
 *
 * Created: 2018-05-29 오전 10:44:27
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

unsigned char SEG[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
int stop=0;
int reset=0;
int num4,num3,num2,num1=0;
	
ISR(INT4_vect){
	_delay_ms(20);
	
	if(stop==0) stop=1;
	else stop=0;
	

}
ISR(INT5_vect){
	_delay_ms(10);
	num1=0;
	num2=0;
	num3=0;
	num4=0;
	PORTC=0xff;
}

int main(void)
{
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0x0f;
	DDRE=0xfc;
	PORTB=0xf0;
	PORTC=0xff;
	PORTA=SEG[0];
	PORTE=0xf0;
	EICRB=0b00001010;
	EIMSK=0b00110000;
	SREG=0x80;

	while(1){
		PORTB=0xfe;
		PORTA=SEG[num1];
		_delay_ms(2);
		PORTB=0xfd;
		PORTA=SEG[num2];
		_delay_ms(2);
		PORTB=0xfb;
		PORTA=SEG[num3];
		_delay_ms(3);
		PORTB=0xf7;
		PORTA=SEG[num4];
		_delay_ms(3);
		if(stop==1) continue;
		while(!(~PINE&10));
		
		num1++;
		if(num1==10){
			num1=0;
			PORTC=0xff;
			num2++;
			PORTC=0xfe;
		}
		if(num2==10){
			num2=0;
			PORTC=0xff;
			num3++;
			PORTC=0xfc;
		}
		if(num3==10){
			num3=0;
			PORTC=0xff;
			num4++;
			PORTC=0xf8;
		}
		if(num4==10){
			num4=0;
		}
	}
}
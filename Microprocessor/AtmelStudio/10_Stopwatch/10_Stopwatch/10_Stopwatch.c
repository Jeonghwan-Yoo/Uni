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
int count=0;
int cntint=0;

void start(){
	int num4,num3,num2,num1=0;
	while(!(~PINE&0x30)){
		for(int i=0;i<50;i++)
		{
			if(count>1000)
			{
				PORTB=0xfe;
				num1=count%10;
				PORTA=SEG[num1];
				_delay_ms(0.2/4.0);
				PORTB=0xfd;
				num2=(count/10)%10;
				PORTA=SEG[num2];
				_delay_ms(0.2/4.0);
				PORTB=0xfb;
				num3=(count/100)%10;
				PORTA=SEG[num3];
				_delay_ms(0.2/4.0);
				PORTB=0xf7;
				num4=count/1000;
				PORTA=SEG[num4];
				_delay_ms(0.2/4.0);
			}
			else if(count>100)
			{
				PORTB=0xfe;
				num1=count%10;
				PORTA=SEG[num1];
				_delay_ms(0.2/3.0);
				PORTB=0xfd;
				num2=(count/10)%10;
				PORTA=SEG[num2];
				_delay_ms(0.2/3.0);
				PORTB=0xfb;
				num3=(count/100)%10;
				PORTA=SEG[num3];
				_delay_ms(0.2/3.0);
			}
			else if(count>10)
			{
				PORTB=0xfe;
				num1=count%10;
				PORTA=SEG[num1];
				_delay_ms(0.1);
				PORTB=0xfd;
				num2=(count/10)%10;
				PORTA=SEG[num2];
				_delay_ms(0.1);
			}
			else
			{
				PORTB=0xfe;
				num1=count%10;
				PORTA=SEG[num1];
				_delay_ms(0.1);
				PORTB=0xfd;
				num2=0;
				PORTA=SEG[num2];
				_delay_ms(0.1);
			}
		}
		count++;
		if(count>=10000) count=0;	
	}
}
	
ISR(INT4_vect){
	_delay_ms(20);
	
	if(cntint==0){
		start();
		cntint++;
	}
	else if(cntint==1){
		while((PINE&0b0001000)==0);
		cntint++;
	}
	else{
		count=0;
		PORTA=SEG[0];
		cntint=0;
	}
}
ISR(INT5_vect){
	_delay_ms(10);
	count=0;
	start();
}

int main(void)
{
	DDRA=0xff;
	DDRB=0xff;
	DDRC=0x0f;
	DDRE=0xfc;
	PORTB=0xf0;
	PORTC=0xf0;
	PORTA=SEG[0];
	PORTE=0xf0;
	EICRB=0b00001010;
	EIMSK=0b00110000;
	SREG=0x80;

	while(1);
}
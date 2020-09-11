/*
 * _15_Counter5.c
 *
 * Created: 2018-06-12 오전 11:16:51
 *  Author: 17
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>

unsigned char led=0xfe;
int loop=0;
ISR(TIMER0_OVF_vect){
	if(loop<100) loop++; //타이머 클럭 72개를 100번 카운트 했는지 체크
	else{
		PORTC=led;
		led=led<<1|0b00000001;
		if(led==0xff) led=0xfe;
		loop=0;
	}
	TCNT0=112;
}

int main(void)
{
	DDRC=0xff;
	TCCR0=0b00000111; //Normal mode, Presaler 1024
	TCNT0=112; //Overflow interrupt를 위한 시작 지점 저장
	TIMSK=0b00000001; //Overflow interrupt 허용
	SREG=0x80;
	PORTC=0xff;
	while(1) PORTE=led;
}
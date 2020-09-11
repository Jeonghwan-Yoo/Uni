/*
 * _15_Counter3.c
 *
 * Created: 2018-06-12 오전 10:35:11
 *  Author: 17
 */ 

#include <avr/interrupt.h>
#include <avr/io.h>

unsigned char SEG[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
int count=0,loop=0,num=0,tenNum=0;
ISR(TIMER0_OVF_vect){
	if(count<10){ //FND 일의 자리만 킬 경우
		if(loop<100) loop++;
		else{
			loop=0; num=count%10; PORTB=0xfe;
			PORTA=SEG[num]; count++;
		}
	}else{ //FND 10의자리 1의자리 모두 ON
		if(loop<100){ //1초미만 타이머
			loop++;
			if(loop%2==0){ //일의자리 FND
				PORTB=0xfe; num=count%10;
				PORTA=SEG[num];
			}else{ //10의자리 FND
				PORTB=0xfd; tenNum=count/10;
				PORTA=SEG[tenNum];
			}
		}else{ //1초 타이머
			loop=0; count++;
			if(count==100) count=0;
		}
	}
	TCNT0=112; //타이머/카운터 레지스터 리셋
}

int main(void)
{
	DDRA=0xff;
	DDRB=0xff;
	TCCR0=0b00000111;
	TCNT0=112;
	TIMSK=0b00000001; //TOIE0=0
	SREG=0x80;
	PORTB=0xfe; //FND S0,S1,S2,S3
	PORTA=0xff; //PORTA 초기값 oFF
	while(1);
}
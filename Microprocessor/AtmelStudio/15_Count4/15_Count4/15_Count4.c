/*
 * _15_Count4.c
 *
 * Created: 2018-06-12 오전 11:09:23
 *  Author: 17
 */ 
#include <avr/interrupt.h>
#include <avr/io.h>

unsigned char SEG[16]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
int n=0,loop=0;
ISR(TIMER0_OVF_vect){  //출력비교 매치 interrupt발생
	if(loop<100) loop++; //타이머 클럭 144개를 100번 카운트 했는지 체크
	else{
		loop=0; //타이머 클럭 144개를 100번 카운트 했다면 1초가 된 것임, 초기화
		PORTA=SEG[n++]; //FND에 숫자 디스플레이
		if(n>=10) n=0; //10이상인 경우 숫자패턴 초기화
	}
	TCNT0=0x00;
}

int main(void)
{
	DDRA=0xff; //포트A출력
	DDRB=0xff; //포트B출력
	TCCR0=0b00011111; //CTC모드, OC0토글, 분주비 1024
	OCR0=144;
	TCNT0=0x00; //카운터 레지스터 초기화
	TIMSK=0b00000010; //)CIE=1, 출력비교매치 인터럽트 인에이블
	SREG=0x80; //인터럽트 허용
	PORTB=0xf0; //FND S0,S1,S2,S3 스위치를 모두 ON;
	while(1);
}
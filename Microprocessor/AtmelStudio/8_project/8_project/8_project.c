/*
 * _8_project.c
 *
 * Created: 2018-05-16 오전 10:17:52
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>
#include "tpk_lcd8.h"

int main(void)
{
	int i; //데이터 for문 돌리기위한 변수
	unsigned char data11[8]={0x04,0x0a,0x04,0x00,0x1f,0x0a,0x0a,0x0a}; //'유'
	unsigned char data12[8]={0x1d,0x05,0x0b,0x15,0x00,0x04,0x0a,0x04}; //'정'
	unsigned char data13[8]={0x0a,0x1e,0x0a,0x17,0x0a,0x0a,0x1c,0x07}; //'환'
	unsigned char data2[13]={0x30,0x31,0x30,0x2d,0x37,0x33,0x33,0x30,0x2d,0x35,0x36,0x33,0x39}; //010-7330-5639
	lcd_init(); //초기화
	
	while(1){
		lcd_command(0x40); //CGRAM 첫주소를 이용
		for(i=0;i<8;i++) lcd_data(data11[i]); //첫 주소에 '유'만듦
		lcd_command(0x48); //CGRAM 두 번째 주소를 이용
		for(i=0;i<8;i++) lcd_data(data12[i]); //두 번째 주소에 '정'만듦
		lcd_command(0x50); //CGRAM 세 번째 주소를 이용
		for(i=0;i<8;i++) lcd_data(data13[i]); //세 번째 주소에 '환'만듦
		lcd_command(0x80); //1행1열
		lcd_data(0x00); //1행1열에 '유' 출력
		lcd_command(0x82); //1행3열
		lcd_data(0x01); //1행3열 '정' 출력
		lcd_command(0x84); //1행5열
		lcd_data(0x02); //1행5열 '환' 출력
		lcd_command(0xc0); //2행1열 
		for(i=0;i<13;i++) lcd_data(data2[i]); //2행에 전화번호 CGROM으로 출력
		_delay_ms(1000); //1초간 딜레이
		lcd_command(0x01);	//화면지우기
		_delay_ms(100);	//0.1초간 딜레이
	}
}
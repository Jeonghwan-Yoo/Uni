/*
 * _8_LCD.c
 *
 * Created: 2018-05-16 오전 9:14:30
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>
#include "tpk_lcd8.h"

int main(void)
{
	unsigned char key;
    int i;
	DDRD=0x00;
	unsigned char data1[13]={0x4a,0x65,0x6f,0x6e,0x67,0x68,0x77,0x61,0x6e,0xfe,0x59,0x6f,0x6f};
	unsigned char data2[13]={0x30,0x31,0x30,0x2d,0x37,0x33,0x33,0x30,0x2d,0x35,0x36,0x33,0x39};
	lcd_init();
	
	while(1){
		key=PIND&0x01;
		if(key==0x01){
			lcd_command(0x80);
			for(i=0;i<13;i++){
				lcd_data(data1[i]);
			}
			lcd_command(0xc0);
			for(i=0;i<13;i++){
				lcd_data(data2[i]);
			}
		}
		else{
			lcd_command(0x01);
		}
	}
	
	
}
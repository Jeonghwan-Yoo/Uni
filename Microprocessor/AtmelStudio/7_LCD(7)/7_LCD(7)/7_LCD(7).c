/*
 * _7_LCD_7_.c
 *
 * Created: 2018-05-15 오전 11:31:40
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>
#include "tpk_lcd8.h"

int main(void)
{
    int i;
	unsigned char data1[8]={0x09,0x15,0x09,0x00,0x08,0x0f,0x00};
	unsigned char data2[8]={0x1d,0x05,0x05,0x00,0x1f,0x11,0x11,0x1f};
	lcd_init();
	lcd_command(0x40);
	for(i=0;i<8;i++){
		lcd_data(data1[i]);
	}
	lcd_command(0x48);
	for(i=0;i<8;i++){
		lcd_data(data2[i]);
	}
	lcd_command(0x80);
	lcd_data(0x00);
	lcd_command(0xc0);
	lcd_data(0x01);
	
}
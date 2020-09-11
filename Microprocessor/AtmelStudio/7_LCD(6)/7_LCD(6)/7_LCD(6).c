/*
 * _7_LCD_6_.c
 *
 * Created: 2018-05-15 오전 11:28:53
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>
#include "tpk_lcd8.h"

int main(void)
{
    int i;
	unsigned char data[8]={0x09,0x15,0x09,0x00,0x08,0x0f,0x00};
	lcd_init();
	lcd_command(0x40);
	for(i=0;i<8;i++){
		lcd_data(data[i]);
		_delay_ms(30);
	}
	lcd_command(0xc0);
	lcd_data(0x00);
}
/*
 * _7_LCD_5_.c
 *
 * Created: 2018-05-15 오전 11:25:29
 *  Author: 17
 */ 

#define F_CPU 14745600
#include <util/delay.h>
#include <avr/io.h>
#include "tpk_lcd8.h"

int main(void)
{
    unsigned char num;
	lcd_init();
	lcd_display_position(1,1);
	lcd_string("********");
	lcd_entry_mode(1,1);
	
	num=0x30;
	while(1){
		lcd_data(num++);
		if (num>0x39) num=0x30;
		_delay_ms(500);
	}
}
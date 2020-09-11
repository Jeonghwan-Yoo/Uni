/*
 * _7_LCD_4_.c
 *
 * Created: 2018-05-15 오전 11:18:12
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <util/delay.h>
#include <avr/io.h>
#include "tpk_lcd8.h"

int main(void)
{
	lcd_init();
	
    while(1)
    {
        lcd_display_position(1,1);
		lcd_string("Clear display");
		_delay_ms(1000);
		lcd_display_clear();
		_delay_ms(1000);
		lcd_display_position(2,1);
		lcd_string("Cursor home");
		_delay_ms(1000);
		lcd_cursor_home();
		_delay_ms(1000);
    }
}
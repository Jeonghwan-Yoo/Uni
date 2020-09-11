/*
 * _7_LCD_3_.c
 *
 * Created: 2018-05-15 오전 11:15:48
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <util/delay.h>
#include <avr/io.h>
#include "tpk_lcd8.h"

int main(void)
{
    lcd_init();
	lcd_display_position(1,3);
	lcd_string("Hello AVR");
}
/*
 * _7_LCD_2_.c
 *
 * Created: 2018-05-15 오전 11:13:25
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <util/delay.h>
#include <avr/io.h>
#include "tpk_lcd8.h"

int main(void)
{
	lcd_init();
	lcd_string("Hello AVR");
}
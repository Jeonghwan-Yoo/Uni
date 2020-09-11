/*
 * _7_LCD.c
 *
 * Created: 2018-05-15 오전 10:58:52
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
        lcd_data('0');
		_delay_ms(1000);
		lcd_data('1');
		_delay_ms(1000);
		lcd_data('2');
		_delay_ms(1000);
		lcd_data(0x33);
		_delay_ms(1000);
		lcd_data(0x34);
		_delay_ms(1000);
    }
}
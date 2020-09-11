/*
 * _7_LCD_8_.c
 *
 * Created: 2018-05-15 오전 11:49:03
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <util/delay.h>
#include <avr/io.h>
#include "tpk_lcd8.h"


int main(void)
{
    float fvalue;
	char msg[16];
	lcd_init();
	fvalue=0.12345;
	sprintf(msg,"value=%.5f",fvalue);
	lcd_string(msg);
}
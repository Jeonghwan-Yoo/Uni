/*
 * _8_LCD_2_.c
 *
 * Created: 2018-05-16 오후 1:18:37
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>
#include <util/delay.h>
#include "tpk_lcd8.h"
#define DataLEN 13
int main(void)
{
	unsigned char name[DataLEN]={0x4a,0x65,0x6f,0x6e,0x67,0x68,0x77,0x61,0x6e,0xfe,0x59,0x6f,0x6f};
	unsigned char phonenum[DataLEN]={0x30,0x31,0x30,0x2d,0x37,0x33,0x33,0x30,0x2d,0x35,0x36,0x33,0x39};
		
	DDRD=0x00;
	lcd_init();
    while(1)
    {
        if(!(PIND&=0x01)) lcd_command(0b00001000);
		else lcd_command(0b00001111);
		lcd_display_position(1,1);
		for(int n=0;n<DataLEN;n++) lcd_data(name[n]);
		lcd_display_position(2,1);
		for(int i=0;i<DataLEN;i++) lcd_data(phonenum[i]);
		_delay_ms(1000);
	}
}
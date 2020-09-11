/*
 * _1_LED_2_.c
 *
 * Created: 2018-04-11 오전 9:13:40
 *  Author: 17
 */ 
#define F_CPU 14745600L
#include <avr/io.h>

int main(void)
{
	DDRA=0xff;
	PORTA=0x55;
}
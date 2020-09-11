/*
 * _1_LED.c
 *
 * Created: 2018-04-10 오전 11:44:47
 *  Author: 17
 */ 

#define F_CPU 14745600L
#include <avr/io.h>

int main(void)
{
    DDRA=0xff;
	PORTA=0xf0;
}
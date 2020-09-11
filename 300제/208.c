//정수값 10을 16진수 문자열로 변환하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void main(void) {
	char buff[100];
	int radix = 16;

	itoa(10, buff, radix);
	puts(buff); //"a"

	itoa(255, buff, radix);
	puts(buff); //"ff"
}
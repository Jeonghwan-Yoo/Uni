//2진수 문자열을 16진수 문자열로 변환하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int radix = 16; //변환할 기수가 16진수
	int base = 2; //변환할 문자열이 2진수
	char string[] = "10101011";
	char* stop;
	long value;
	char buff[100];

	value = strtol(string, &stop, base); //10진수로 변환
	itoa(value, buff, radix);
	puts(buff); //"ab"
}
//숫자 34567을 16진 문자열 "8707"로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int value;
	char string[100];
	int radix;

	radix = 16; //16진수

	value = 34567;
	_ultoa_s(value, string, sizeof(string), radix);
	printf("변환된 문자열은 %s입니다.\n", string);

	value = 1234567890;
	_ultoa_s(value, string, sizeof(string), radix);
	printf("변환된 문자열은 %s입니다.\n", string);
}
//char* ultoa(unsigned long value, char* string, int radix);
//fcvt()를 사용하면 실수를 문자열로 변환할 수 있습니다.
//숫자값 12345를 이진 문자열 "11000000111001"로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int value;
	char string[100];
	int radix;

	radix = 2; //이진수

	value = 12345;
	_ltoa_s(value, string, sizeof(string), radix);
	printf("변환된 문자열은 %s입니다.\n", string);

	value = -12345;
	_ltoa_s(value, string, sizeof(string), radix);
	printf("변환된 문자열은 %s입니다.\n", string);
}
//char* ltoa(long value, char* string, int radix);
//value는 변환될 숫자값이며, string은 변환될 숫자가 저장될 버퍼입니다.
//radix는 value값을 몇 진수 문자열의 형태로 저장할 지를 지정합니다.
//ultoa()도 가능하다.
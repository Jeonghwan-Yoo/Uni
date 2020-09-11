//숫자값 5를 십진 문자열 "5"로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int value;
	char string[100];
	int radix;

	radix = 10; //십진수

	value = 5;
	_itoa_s(value, string, sizeof(string), radix);
	printf("변환된 문자열은 %s입니다.\n", string);
	
	value = -12345;
	_itoa_s(value, string, sizeof(string), radix);
	printf("변환된 문자열은 %s입니다.\n", string);
}
//char* itoa(int value, char* string, int radix);
//value는 변환될 숫자값이며, string은 변환될 숫자가 저장될 버퍼입니다.
//radix는 value 값을 몇 진수 문자열의 형태로 저장할 지를 지정합니다.
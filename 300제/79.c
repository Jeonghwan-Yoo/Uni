//16진수 문자열을 10진수로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char* string = "0xFF";
	char* stop;
	int radix;
	long value;

	radix = 16;

	value = strtol(string, &stop, radix);

	printf("%d개의 문자가 변환되었습니다.\n", stop - string);
	printf("16진수 %s를 숫자로 변환하면 %ld입니다.\n", string, value);
}
//long strtol(const char* string, char** stop, int radix);
//기수(radix)는 각 진수의 기본이 되는 수입니다.
//stop은 문자열을 숫자로 변환하다가 멈춰진 위치를 저장하기 위한 포인터 변수입니다. 이 값을 사용하여 문자열이
//숫자로 변환된 길이를 확인할 수 있습니다.
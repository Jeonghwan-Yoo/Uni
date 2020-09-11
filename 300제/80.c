//2진수 문자열을 10진수로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char* string = "11000";
	char* stop;
	int radix;
	unsigned long value;

	radix = 2;

	value = strtoul(string, &stop, radix);

	printf("%d개의 문자가 변환되었습니다.\n", stop - string);
	printf("2진수 %s를 숫자로 변환하면 %u입니다.\n", string, value);
}
//unsigned long strtoul(const char* string, char** stop, int radix);
//단지 반환값이 unsigned long형이라는 것이 다르다.
//stop은 문자열을 숫자로 변환하다가 멈춰진 위치를 저장하기 위한 포인터 변수입니다. 
//이 값을 사용하여 문자열이 숫자로 변환된 길이를 확인할 수 있습니다.
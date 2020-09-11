//숫자 2를 비트 쉬프트 연산을 사용하여 곱하기 2를 하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	char value = 2;

	value = value << 1; //value=value*2;

	printf("value : %d\n", value);
}
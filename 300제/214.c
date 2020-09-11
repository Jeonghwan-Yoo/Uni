//숫자 4를 비트 쉬프트 연산을 사용하여 나누기 2를 하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	char value = 4;
	
	value = value >> 1; //value=value/2;

	printf("value : %d\n", value);
}
//홀수인 경우 나누기 값이 정확하지 않을 수 있습니다.
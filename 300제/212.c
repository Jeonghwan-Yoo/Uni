//정수형 변수 i를 -5로 초기화한 후, 비트 연산을 사용하여 i의 값을 0으로 만드는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int i = -5;

	printf("i = %d\n", i);

	i = i ^ i;

	printf("i = %d\n", i);
}
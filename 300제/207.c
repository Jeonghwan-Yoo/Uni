//정수형 변수 i를 정의하고, i가 정의되어 있는 번지 값을 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int i = 127;
	int j;

	printf("%d, %x\n", i, i);

	printf("%#x\n", &i);
	printf("%#x\n", &j);
}
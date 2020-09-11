//매크로 상수의 COUNT의 값이 100이 아니라면, 컴파일 에러를 출력하는 프로그램을 작성하세요.
#include <stdio.h>

#define COUNT 100

#if COUNT!=100
#error "COUNT!=100"
#endif

void main(void) {
	printf("COUNT : %d\n", COUNT);
}
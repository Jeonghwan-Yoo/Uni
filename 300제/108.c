//정수형 변수 x,y를 대신하여 사용할 수 있는 포인터 배열 변수를 사용하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int x = 0, y = 0;
	int* pxy[2];

	pxy[0] = &x;
	pxy[1] = &y;

	*pxy[0] = 5;
	*pxy[1] = 10;

	printf("x = %d, pxy[0] = %d\n", x, *pxy[0]);
	printf("y = %d, pxy[1] = %d\n", y, *pxy[1]);

	printf("x+y=%d\n", x + y);
	printf("x+y=%d\n", *pxy[0] + *pxy[1]);
}
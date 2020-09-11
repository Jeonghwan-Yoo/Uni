//108번에서 사용된 pxy의 값을 함수에 전달해서 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void print_pxy(int* pxy[2]);

void main(void) {
	int x = 0, y = 0;
	int *pxy[2];

	pxy[0] = &x;
	pxy[1] = &y;

	*pxy[0] = 5;
	*pxy[1] = 10;

	print_pxy(pxy);
}

void print_pxy(int* pxy[2]) {
	printf("pxy[0]=%d\n", *pxy[0]);
	printf("pxy[1]=%d\n", *pxy[1]);
}
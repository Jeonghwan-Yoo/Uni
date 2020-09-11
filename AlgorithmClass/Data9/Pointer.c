#include <stdio.h>

void main() {
	int a = 10;
	int *b; //포인터 선언
	int **c; //double point.
	b = &a; //address of b is same as it of a.
	c = &b; //address of c is same as it of b.
	printf("%d %d %d\n", a, *b, **c); //주소에 있는 값 반환
	//*는 처음에는 선언 그다음에는 그주소값의 들어있는 값.
}
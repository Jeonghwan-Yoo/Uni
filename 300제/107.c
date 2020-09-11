//main()에서 정의한 변수 x의 값을 다른 함수에서 변경하는 프로그램을 작성하세요.
#include <stdio.h>

void change_x1(int x1);
void change_x2(int* x2);

void main(void) {
	int x;

	x = 5;
	printf("함수를 호출하기 전 x 값 : %d\n", x);

	change_x1(x);
	printf("change_x1() 함수를 호출한 후의 x 값 : %d\n", x);

	change_x2(&x);
	printf("change_x2() 함수를 호출한 후의 x 값 : %d\n", x);
}

void change_x1(int x1) {
	x1 = 50;
}
void change_x2(int* x2) {
	*x2 = 100;
}
//1번은 값에 의한 호출.
//x2는 x의 분신으로 지정되서 참조에 의한 호출.
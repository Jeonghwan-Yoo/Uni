//111에서 사용된 문자형 배열 변수 one을 출력하는 함수 프로그램을 작성하세요.
#include <stdio.h>

void print_one(char* pone);
void print_one2(char one[]);

void main(void) {
	char one[] = "Korea";

	print_one(one);
	print_one2(one);
}

void print_one(char* pone) {
	puts(pone);
}
void print_one2(char* one[]) {
	puts(one);
}
//1차원 배열을 함수에 전달하기 위해서는
//void func(int* x) or void func(int x[])
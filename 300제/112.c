//111���� ���� ������ �迭 ���� one�� ����ϴ� �Լ� ���α׷��� �ۼ��ϼ���.
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
//1���� �迭�� �Լ��� �����ϱ� ���ؼ���
//void func(int* x) or void func(int x[])
//�Լ����� ȣ�� ���踦 �����ϴµ� ���
#include <stdio.h>

void fun_3() { //3
	printf("this is function 3\n"); //1
}
void fun_2() { //2
	fun_3();
	printf("this is function 2\n"); //2
}
void fun_1() { //1
	fun_2();
	printf("this is function 1\n"); //3
}
int main(void) {
	fun_1();
}
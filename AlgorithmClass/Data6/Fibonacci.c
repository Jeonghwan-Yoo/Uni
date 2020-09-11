#include <stdio.h>

//int fib(int n) {
//	if (n <= 2) {
//		return 1;
//	}
//	else {
//		return fib(n - 1) + fib(n - 2);
//	}
//}

//n���� fibonacci ���ڸ� ��ȯ�ϴ� �Լ�
int fibo(int n) {
	if (n <= 2) { //ù ��°�� �� ��° fibonacci���ڴ� 1�̴�.
		return 1;
	}
	else {
		int before_before = 1; //a1=1.
		int before = 1; //a2=1.
		int me; //a3.
		int i = 2;
		while (i < n) {
			i++;
			me = before_before + before; //a3=a1+a2.
			before_before = before; //a1=a2.
			before = me; //a2=a3.
		}
		return me;
	}
}
int main(void) {
	int i = 12;
	printf("%d��° Fibonacci ���ڴ� %d\n", i, fibo(i));
	return 0;
}
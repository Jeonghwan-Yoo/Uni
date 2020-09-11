#include <stdio.h>

//int fib(int n) {
//	if (n <= 2) {
//		return 1;
//	}
//	else {
//		return fib(n - 1) + fib(n - 2);
//	}
//}

//n번쨰 fibonacci 숫자를 반환하는 함수
int fibo(int n) {
	if (n <= 2) { //첫 번째와 두 번째 fibonacci숫자는 1이다.
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
	printf("%d번째 Fibonacci 숫자는 %d\n", i, fibo(i));
	return 0;
}
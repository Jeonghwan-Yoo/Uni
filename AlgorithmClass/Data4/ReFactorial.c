#include <stdio.h>

int fact(int n) { //재귀함수 recursive function.
	if (n <= 1) { //탈출조건 escape condition
		return 1; //1까지 다 곱하면, 그만
	}
	return n * fact(n - 1); //지속, factorial의 정의에 충실하게 factorial=n*(n-1)*...*2*1. So, fact(n) is calling fact(n-1) and etc...
}

int main(void) {
	int n = 10; //factorial을 계산하고 싶은 값
	printf("Factorial %d is %d\n", n, fact(n));

}
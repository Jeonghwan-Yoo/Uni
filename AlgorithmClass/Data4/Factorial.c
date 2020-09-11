#include <stdio.h>

int main(void) {
	int n = 10; //계산하고자 하는 factorial
	int i; //for-loop에서 사용하려고,
	int result = 1; //factorial결과 저장, 초기값이 0이 아니라 1

	for (i = n;i >= 1;i--) { //factorial 계산
							 //n,n-1,n-2... 계속해서 곱해
		result = result * i; //1*n*(n-1)*(n-2)*...*2*1
	}
	printf("Factorial %d is %d\n", n, result);
}
#include <stdio.h>

int main(void) {
	int n = 10; //����ϰ��� �ϴ� factorial
	int i; //for-loop���� ����Ϸ���,
	int result = 1; //factorial��� ����, �ʱⰪ�� 0�� �ƴ϶� 1

	for (i = n;i >= 1;i--) { //factorial ���
							 //n,n-1,n-2... ����ؼ� ����
		result = result * i; //1*n*(n-1)*(n-2)*...*2*1
	}
	printf("Factorial %d is %d\n", n, result);
}
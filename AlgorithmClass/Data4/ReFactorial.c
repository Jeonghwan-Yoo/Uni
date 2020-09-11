#include <stdio.h>

int fact(int n) { //����Լ� recursive function.
	if (n <= 1) { //Ż������ escape condition
		return 1; //1���� �� ���ϸ�, �׸�
	}
	return n * fact(n - 1); //����, factorial�� ���ǿ� ����ϰ� factorial=n*(n-1)*...*2*1. So, fact(n) is calling fact(n-1) and etc...
}

int main(void) {
	int n = 10; //factorial�� ����ϰ� ���� ��
	printf("Factorial %d is %d\n", n, fact(n));

}
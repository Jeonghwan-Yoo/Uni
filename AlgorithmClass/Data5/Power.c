#include <stdio.h>

int main(void) {
	//2�� 3���� ����ϰ��� �Ѵ�.
	int base = 2; //base.
	int exponent = 3; //exponent.
	int result = 1; //initialization.

	for (int i = 1;i <= exponent;i++) {
		result = result * base; //base*base*..*base
	}
	printf("%d�� %d���� %d\n", base, exponent, result);

	return 0;
}
#include <stdio.h>

/*�������� ����ϴ� �Լ�
*/
int calcPower(int base, int exponent) { //arguments are base and exponent.
	int result = 1; //initialization.
	for (int i = 1;i <= exponent;i++) {
		result = result * base; //base*base*....*base.
	}
	return result;
}

int main(void) {
	//5�� 2���� ����ϰ��� �Ѵ�.
	int base = 5;
	int exponent = 2;

	printf("%d�� %d���� %d\n", base, exponent, calcPower(base, exponent));

	return 0;
}
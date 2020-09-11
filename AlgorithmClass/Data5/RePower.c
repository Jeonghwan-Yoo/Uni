#include <stdio.h>

/*�������� ����ϴ� ����Լ�
*/
int calcPower(int base, int exponent) {
	if (exponent == 1) { //if exponent is 1,
		return base; //last.
	}
	else {
		return base * calcPower(base, exponent - 1); //recursive function with exponent-1.
	}
}

int main(void) {
	//2�� 4���� ����ϰ��� �Ѵ�.
	int base = 2;
	int exponent = 30;

	printf("%d�� %d���� %d\n", base, exponent, calcPower(base, exponent));

	return 0;
}
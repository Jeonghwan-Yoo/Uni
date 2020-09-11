#include <stdio.h>

/*지수승을 계산하는 함수
*/
int calcPower(int base, int exponent) { //arguments are base and exponent.
	int result = 1; //initialization.
	for (int i = 1;i <= exponent;i++) {
		result = result * base; //base*base*....*base.
	}
	return result;
}

int main(void) {
	//5의 2승을 계산하고자 한다.
	int base = 5;
	int exponent = 2;

	printf("%d의 %d승은 %d\n", base, exponent, calcPower(base, exponent));

	return 0;
}
#include <stdio.h>

/*지수승을 계산하는 재귀함수
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
	//2의 4승을 계산하고자 한다.
	int base = 2;
	int exponent = 30;

	printf("%d의 %d승은 %d\n", base, exponent, calcPower(base, exponent));

	return 0;
}
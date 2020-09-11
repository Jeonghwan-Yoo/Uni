#include <stdio.h>

/*지수승을 계산하는 재귀함수
*/
//this is for good efficiency.
//this is like 2^30 is 4^15 and 4*8^7....
int calcPower(int base, int exponent) {
	if (exponent == 1) {
		return base;
	}
	else if (exponent % 2 == 0) {
		return calcPower(base*base, exponent / 2);
	}
	else if (exponent % 2 == 1) {
		return base * calcPower(base*base, (exponent - 1) / 2);
	}
}

int main(void) {
	//2의 4승을 계산하고자 한다.
	int base = 2;
	int exponent = 30;

	printf("%d의 %d승은 %d\n", base, exponent, calcPower(base, exponent));

	return 0;
}
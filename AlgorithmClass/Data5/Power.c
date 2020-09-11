#include <stdio.h>

int main(void) {
	//2의 3승을 계산하고자 한다.
	int base = 2; //base.
	int exponent = 3; //exponent.
	int result = 1; //initialization.

	for (int i = 1;i <= exponent;i++) {
		result = result * base; //base*base*..*base
	}
	printf("%d의 %d승은 %d\n", base, exponent, result);

	return 0;
}
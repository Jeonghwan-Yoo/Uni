//1~100까지 홀수의 합을 구하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int i, hap = 0;

	for (i = 0;i <= 100;i++) {
		if (i % 2) {
			hap += i;
		}
	}
	printf("1~100까지의 홀수의 합:%d\n", hap);
}
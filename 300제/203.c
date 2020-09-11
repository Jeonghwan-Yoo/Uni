//'*'를 사용하여 다음과 같은 삼각형을 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int i, j;

	for (i = 0;i < 5;i++) {
		for (j = 0;j <= i;j++) {
			printf("*");
		}
		printf("\n");
	}
}
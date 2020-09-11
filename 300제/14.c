//논리형 변수 b를 정의하고, 10과 5의 비교값을 저장하는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	int b;
	int j;

	b = 10 > 5;
	j = 10 > 20;

	printf("논리형 변수 b의 값은 %d\n", b);
	printf("논리형 변수 j의 값은 %d\n", j);

	if (b) { //참
		printf("10>5의 식은 참입니다.\n");
	}
	else {
		printf("10>5의 식은 거짓입니다.\n");
	}
	
	if (j) { //거짓
		printf("10>20의 식은 참입니다.\n");
	}
	else {
		printf("10>20의 식은 거짓입니다.\n");
	}
	if (-1) { //참 0을 제외한 모든 수.
		printf("-1은 참입니다.\n");
	}
	else {
		printf("-1은 거짓입니다.\n");
	}
}

//c언어는 bool말고 int사용.
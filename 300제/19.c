//상수 TRUE를 1로 FALSE를 0으로 정의하고, if 문으로 조건을 판단하여 참, 거짓을 출력하는 프로그램을 작성하세요.
#include <stdio.h>

#define TRUE 1
#define FALSE 0

main() {
	if (TRUE) {
		printf("TRUE의 값은 참입니다.\n");
	}
	else {
		printf("TRUE의 값은 거짓입니다.\n");
	}
	if (FALSE) {
		printf("FALSE의 값은 참입니다.\n");
	}
	else {
		printf("FALSE의 값은 거짓입니다.\n");
	}
}
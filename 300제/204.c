//scanf() 함수를 사용하여 값을 하나 입력받고, 그 값이 홀수인지, 짝수인지 구분하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int num;

	printf("숫자를 입력하세요 : ");

	scanf_s("%d", &num);

	if (num % 2 == 1) printf("%d는 홀수입니다.\n", num);
	else printf("%d는 짝수입니다.\n",num);
}
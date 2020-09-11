//데이터형별로 포인터 변수를 정의하고, 각각의 크기를 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	char *p_char;
	short *p_short;
	int *p_int;
	long *p_long;
	float *p_float;
	double *p_double;

	printf("문자형의 크기 : %d 바이트\n", sizeof(char));
	printf("정수형의 크기 : %d 바이트\n", sizeof(short));
	printf("정수형의 크기 : %d 바이트\n", sizeof(int));
	printf("정수형의 크기 : %d 바이트\n", sizeof(long));
	printf("실수형의 크기 : %d 바이트\n", sizeof(float));
	printf("실수형의 크기 : %d 바이트\n", sizeof(double));

	printf("문자형 포인터의 크기 : %d 바이트\n", sizeof(p_char));
	printf("정수형 포인터의 크기 : %d 바이트\n", sizeof(p_short));
	printf("정수형 포인터의 크기 : %d 바이트\n", sizeof(p_int));
	printf("정수형 포인터의 크기 : %d 바이트\n", sizeof(p_long));
	printf("실수형 포인터의 크기 : %d 바이트\n", sizeof(p_float));
	printf("실수형 포인터의 크기 : %d 바이트\n", sizeof(p_double));
}
//일반 변수는 사용되는 숫자의 범위에 맞게 정의하고 사용합니다.
//포인터 변수는 일반 변수가 저장되어 있는 메모리 번지를 저장하기 때문에, 숫자의 범위에 관계없이 무조건 4바이트.
//포인터 변수에 char*, int* 등을 사용하는 이유는 그것에 따라 증감 연산에 대한 동작을 구분하기 위해서입니다.
//포인터의 증감 연산은 주로 배열 변수에서 사용하며, 증감 연산자를 포인터 변수에 사용시,
//char*형 포인터는 1, short*형은 2, int*형은 4, double*형은 8바이트 증가 또는 감소 합니다.
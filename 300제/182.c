//2.0에 대해 밑수를 10으로 하는 로그값을 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <math.h>

void main(void) {
	double x;

	x = log10(2.0);

	printf("log10(2.0) : %g\n", x);
}
//double log10(double x);
//단, 인수는 0보다 커야합니다.
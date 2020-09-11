//10의 3승을 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <math.h>

void main(void) {
	double x = 10.0, y = 3.0, r;

	r = pow(x, y);

	printf("10의 3승은 %g입니다.\n", r);
}
//double pow(double x, double y);
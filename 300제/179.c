//x가 1.0이고, y가 1.0일 때 x/y의 아크 탄젠트 값을 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <math.h>

void main(void) {
	double x;

	x = atan2(1.0, 1.0);

	printf("atan2(1.0,1.0) : %g\n", x);
}
//double atan2(double y, double x);
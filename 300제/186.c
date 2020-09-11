//1.1보다 작은 최소의 정수값을 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <math.h>

void main(void) {
	printf("floor(1.0) : %g\n", floor(1.0)); //1
	printf("floor(1.1) : %g\n", floor(1.1)); //1
	printf("floor(1.9) : %g\n", floor(1.9)); //1
	printf("floor(2.5) : %g\n", floor(2.5)); //2
	printf("floor(-2.5) : %g\n", floor(-2.5)); //-3
	printf("floor(-3.0) : %g\n", floor(-3.0)); //-3
}
//double floor(double x);
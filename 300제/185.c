//1.1보다 큰 최소의 정수값을 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <math.h>

void main(void) {
	printf("ceil(1.0) : %g\n", ceil(1.0)); //1
	printf("ceil(1.1) : %g\n", ceil(1.1)); //2
	printf("ceil(1.9) : %g\n", ceil(1.9)); //2
	printf("ceil(2.5) : %g\n", ceil(2.5)); //3
	printf("ceil(-2.5) : %g\n", ceil(-2.5)); //-2
	printf("ceil(-3.0) : %g\n", ceil(-3.0)); //-3
}
//double ceil(double x);
//정수형 상수 1과 실수형 상수 3.141592를 더하는 프로그램을 작성하세요.
#include <stdio.h>

#define X 1
#define PI 3.141592

main() {
	double z;

	z = X + PI;

	printf("%f", z);
}

//상수는 변할 수 없는 수.
//쓰는 이유는 버그의 위험성을 줄일 수 있다.
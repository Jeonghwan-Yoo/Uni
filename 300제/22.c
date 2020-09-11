//변수 x, y를 정의하고, x의 값은 +4로. y의 값은 -2로 초기화하는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	int x = +4;
	int y = -2;

	printf("x+(-y)=%d\n", x + (-y));
	printf("-x+(+y)=%d\n", -x + (+y));
}
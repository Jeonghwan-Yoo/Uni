//매크로 상수 COUNT가 선언되어 있지 않다면, COUNT를 선언하는 프로그램을 작성하세요.
#include <stdio.h>

#define COUNT 100

#if !defined COUNT
#define COUNT 90
#endif

void main(void) {
	printf("COUNT : %d\n", COUNT);
}
//#if로 시작하면 반드시 #endif로 종료.
//#if~#else~#endif
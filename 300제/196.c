//매크로 상수 COUNT가 선언되어 있지 않다면, 컴파일 에러를 출력하는 프로그램을 작성하세요.
#include <stdio.h>

#if !defined COUNT
#error "COUNT MACRO is not defiend!"
#endif

void main(void) {
	printf("COUNT : %d\n", COUNT);
}
//컴파일은 되지 않고 에러메세지 출력
//#error문은 조건부 컴파일을 할 때 주로 사용.
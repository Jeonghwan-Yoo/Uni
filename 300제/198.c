//매크로 상수 COUNT를 선언하고, 취소하는 프로그램을 작성하세요.
#include <stdio.h>

#define COUNT 100

#if defined COUNT //defined 되있으면 
#undef COUNT //COUNT를 다시 undefined 하고
#define COUNT 99 //99로 다시 define
#else //아니면, 
#define COUNT 88
#endif

void main(void) {
	printf("COUNT : %d\n", COUNT);
}

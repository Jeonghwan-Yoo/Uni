//내장 매크로를 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	printf("파일명 : %s\n", __FILE__);
	printf("날 짜 : %s\n", __DATE__);
	printf("시 간 : %s\n", __TIME__);
	printf("줄 수 : %d\n", __LINE__);
}
//내장 매크로는 주로 디버깅을 위해 많이 사용합니다.
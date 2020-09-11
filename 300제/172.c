//time() 함수로 구한 날짜 및 시간을 문자열로 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;

	time(&now);

	printf("현재 날짜 및 시간 : %s", ctime(&now));
}
//char* ctime(const time_t* timer);
//현재 날짜 및 시간에 대한 now값을 문자열로 출력합니다.
//단, ctime() 함수는 문자열의 끝에 개행문자('\n')를 자동으로 추가하므로 주의하세요.
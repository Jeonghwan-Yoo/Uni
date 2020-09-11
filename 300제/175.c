//현재 날짜를 "Fri Sep 16 13:32:22 2005"의 형태로 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;
	struct tm t;

	now = time(NULL);
	t = *localtime(&now);

	printf("현재 날짜 및 시간 : %s\n", asctime(&t));
}
//char* asctime(const struct tm* timeptr);
//날짜와 시간을 아스키 문자열로 출력합니다.
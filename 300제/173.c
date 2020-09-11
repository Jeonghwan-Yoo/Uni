//오늘 날짜에 100일을 더하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;
	struct tm t;

	time(&now);
	t = *localtime(&now);
	t.tm_mday += 100;
	mktime(&t);

	printf("현재 날짜에 100일 더한 날짜 : %4d.%d.%d %d:%d:%d\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, 
		t.tm_hour, t.tm_min, t.tm_sec);
}
//time_t mktime(struct tm* timeptr);
//mktime함수를 사용하면 시간도 바꿀 수 있다.
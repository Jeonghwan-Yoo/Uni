//영국의 그리니치를 기준으로 하는 세계 표준시를 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;
	struct tm t;

	time(&now);

	t = *gmtime(&now);

	printf("세계 표준 시 : %4d.%d.%d %d:%d:%d\n", t.tm_year + 1900, t.tm_mon+1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
}
//struct tm* gmtime(const time_t* timer);
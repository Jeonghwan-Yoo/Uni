//문자열로 된 날짜 "2005-06-23"을 time_t 형식으로 변환하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(void) {
	char date[] = "2005-06-23";
	//             01234567890
	time_t now;
	struct tm t = { 0, };

	t.tm_mday = atoi(&date[8]);
	date[7] = 0;
	t.tm_mon = atoi(&date[5]) - 1;
	date[4] = 0;
	t.tm_year = atoi(&date[0]) - 1900;

	now = mktime(&t);
	printf("2005-06-23을 time_t로 변환하면 %d입니다.\n", now);
}
//char *date라고 하면 에러 발생.
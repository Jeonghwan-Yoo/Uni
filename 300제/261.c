//문자열로 된 날짜 및 시간 "2005-06-23 02:09:21"을 struct tm형식으로 변환하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(void) {
	char date[] = "2005-06-23 02:09:21";
	//             01234567890123456789
	struct tm t = { 0, };

	t.tm_sec = atoi(&date[17]);
	date[16] = 0;
	t.tm_min = atoi(&date[14]);
	date[13] = 0;
	t.tm_hour = atoi(&date[11]);
	date[10];
	t.tm_mday = atoi(&date[8]);
	date[7] = 0;
	t.tm_mon = atoi(&date[5]) - 1;
	date[4] = 0;
	t.tm_year = atoi(&date[0]) - 1900;

	mktime(&t);
	printf("struct tm 변환 후 날짜 : %4d-%02d-%02d %02d:%02d:%02d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
}

//오늘 날짜를 표시하고 AM/PM을 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#include <string.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;
	struct tm t;
	char buff[100], AMPM[10];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", &t);

	strftime(AMPM, sizeof(AMPM), "%p", &t);
	if (strcmp(buff, "오전")) strcpy(AMPM, "AM");
	else if (strcmp(buff, "오후")) strcpy(AMPM, "PM");
	strcat(buff, AMPM);

	puts(buff);
}
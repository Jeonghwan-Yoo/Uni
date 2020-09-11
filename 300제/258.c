//오늘 날짜를 표시하고 오전/오후를 출력하는 프로그램을 작성하세요.
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
	if (strcmp(buff, "AM")) strcpy(AMPM, "오전");
	else if (strcmp(buff, "PM")) strcpy(AMPM, "오후");
	strcat(buff, AMPM);

	puts(buff);
}
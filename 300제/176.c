//날짜 및 시간에 AM/PM을 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	t = *localtime(&now);
	strftime(buff, sizeof(buff), "%Y-%m-%d %I:%M:%S %p", &t);

	puts(buff);
}
//size_t strftime(char* strDest, size_t maxsize, const char* format, const struct tm* timeptr);
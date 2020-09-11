//지금까지 학습한 모든 방법을 동원해서 다양한 날짜 및 시간을 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#pragma warning(disable:4996)

void main(void) {
	struct _timeb tb;
	struct tm t;
	char buff[100];

	_ftime(&tb);

	localtime_s(&t, &tb.time);

	printf("%4d-%d-%d %d:%d:%d.%d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec, tb.millitm);

	printf(ctime(&tb.time));
	printf(asctime(&t));
	puts(_strdate(buff)); //mon/day/year
	puts(_strtime(buff)); //hour:min:sec
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S %p (%a)", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%#Y-%#m-%#d %#H:%#M:%#S %p (%a)", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%c", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%x %X", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%#c", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%#x", &t);
	puts(buff);
}
//c는 날짜+시간, x는 날짜 X는 시간, #은 자세히 문자로.
//%#H를 사용하면, 02를 2로 표시.
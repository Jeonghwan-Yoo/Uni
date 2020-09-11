//오늘 날짜를 기준으로 D-Day를 정하고 D-Day까지 몇 일이 남았는지 계산하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

#define DAYSEC 86400L

void main(void) {
	time_t now;
	struct tm t, dday = { 0,0,0,8,8,2020 }; //2005년 8월 8일
	int n1, n2, nDday;

	now = time(NULL);
	localtime_s(&t, &now);

	dday.tm_year -= 1900;
	dday.tm_mon -= 1;

	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;

	n1 = mktime(&t); //현재시간 초로바꿈
	n2 = mktime(&dday); //DDAY 초로 바꿈.

	nDday = (n2 - n1) / DAYSEC;

	printf("오늘의 날짜는 %s", ctime(&now));
	printf("최수린의 돌 : %d일 남았습니다. (%d/%d/%d)\n", nDday, dday.tm_year + 1900, dday.tm_mon + 1, dday.tm_mday);
}
//프로그램의 이식성이란 프로그램의 소스 코드를 어떤 환경에서 다른 환경으로 얼마나 쉽게 이동시킬 수 있는지를 말하는 것입니다.
//C는 가장 이식성이 높은 프로그래밍 언어 중 하나.
//오늘 날짜를 기준으로 크리스마스까지 남은 시간을 월,일,시,분,초로 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;
	struct tm t, christmas = { 0,0,0,25,12,2019 };
	int n1, n2, nChristmas;

	now = time(NULL);
	localtime_s(&t, &now);

	christmas.tm_year -= 1900; //struct tm 형식으로 변환
	christmas.tm_mon -= 1;

	n1 = mktime(&t);
	n2 = mktime(&christmas);

	nChristmas = n2 - n1;
	
	localtime_s(&christmas, &nChristmas);

	printf("오늘의 날짜는 %s", ctime(&now));
	printf("크리스마스까지 남은 시간은 %d개월 %d일 %d시간 %d분 %d초입니다.\n",
		christmas.tm_mon, christmas.tm_mday, christmas.tm_hour, christmas.tm_min, christmas.tm_sec);
}
//두 개의 날짜 및 시간이 2005년 6월 15일 1시 12분 50초와 2005년 8월 19일 3시 35분 22초라고 할 때,
//차이나는 날짜 및 시간의 차이를 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>

void main(void) {
	struct tm t1, t2, t3;
	int n1, n2, n3;

	t1.tm_year = 2005 - 1900;
	t1.tm_mon = 6 - 1;
	t1.tm_mday = 15;
	t1.tm_hour = 1;
	t1.tm_min = 12;
	t1.tm_sec = 50;

	t2.tm_year = 2005 - 1900;
	t2.tm_mon = 8 - 1;
	t2.tm_mday = 19;
	t2.tm_hour = 3;
	t2.tm_min = 35;
	t2.tm_sec = 22;

	n1 = mktime(&t1);
	n2 = mktime(&t2);

	n3 = n2 - n1;
	gmtime_s(&t3, &n3);
	//기본적으로 1970년을 기준으로해서 70을 뺀다.
	t3.tm_year -= 70;
	
	printf("날짜 1 : %4d-%02d-%02d %02d:%02d:%02d\n",
		t1.tm_year + 1900, t1.tm_mon + 1, t1.tm_mday, t1.tm_hour, t1.tm_min, t1.tm_sec);

	printf("날짜 2 : %4d-%02d-%02d %02d:%02d:%02d\n",
		t2.tm_year + 1900, t2.tm_mon + 1, t2.tm_mday, t2.tm_hour, t2.tm_min, t2.tm_sec);

	printf("날짜차이 : %4d-%02d-%02d %02d:%02d:%02d\n",
		t3.tm_year, t3.tm_mon, t3.tm_mday, t3.tm_hour, t3.tm_min, t3.tm_sec);
}

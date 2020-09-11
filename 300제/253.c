//동일 날짜의 1시 12분 50초와 3시 35분 22초 사이의 시간 차이를 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>

void main(void) {
	struct tm t1, t2;
	int n1, n2, n3;

	t1.tm_year = 2005 - 1900; //년
	t1.tm_mon = 6 - 1; //월
	t1.tm_mday = 15; //일
	t1.tm_hour = 1; //시
	t1.tm_min = 12; //분
	t1.tm_sec = 50; //초

	t2.tm_year = 2005 - 1900; //년
	t2.tm_mon = 6 - 1; //월
	t2.tm_mday = 15; //일
	t2.tm_hour = 3; //시
	t2.tm_min = 35; //분
	t2.tm_sec = 22; //초

	n1 = mktime(&t1);
	n2 = mktime(&t2);

	n3 = n2 - n1;

	printf("시간 1 : %4d-%02d-%02d %02d:%02d:%02d\n",
		t1.tm_year + 1900, t1.tm_mon + 1, t1.tm_mday, t1.tm_hour, t1.tm_min, t1.tm_sec);

	printf("시간 2 : %4d-%02d-%02d %02d:%02d:%02d\n",
		t2.tm_year + 1900, t2.tm_mon + 1, t2.tm_mday, t2.tm_hour, t2.tm_min, t2.tm_sec);

	printf("시간차이 : %d:%d:%d\n", n3 / 3600, (n3 - ((n3 / 3600) * 3600)) / 60, n3 % 60);
}
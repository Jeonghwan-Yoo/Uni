//출생일로부터 오늘까지의 경과된 날짜 수를 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>

#define DAYSEC (24*60*60) //반드시 괄호로 묶어야 합니다.

void main(void) {
	time_t n1, n2;
	struct tm t1, t2;
	double elapsed;

	t1.tm_year = 103; //2003
	t1.tm_mon = 10 - 1; //10
	t1.tm_mday = 15; //15
	t1.tm_hour = 0;
	t1.tm_min = 0;
	t1.tm_sec = 0;

	n1 = time(NULL);
	localtime_s(&t2,&n1);

	n1 = mktime(&t1); //출생일까지의 시간(초)
	n2 = mktime(&t2); //지금까지의 시간(초)

	n2 = n2 - n1;
	elapsed = (double)(n2 / DAYSEC);

	printf("김서진은 태어난 지 %.f일째 입니다.\n", elapsed);
}
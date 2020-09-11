//오늘 날짜에 100개월 90일 80시간을 더하거나 빼는 프록램을 작성하세요.
#include <stdio.h>
#include <time.h>

void main(void) {
	time_t now;
	struct tm t, tb;

	now = time(NULL);
	localtime_s(&t, &now);

	tb = t;

	t.tm_mon += 100; //100개월
	t.tm_mday += 90; //90일
	t.tm_hour += 80; //80시간

	mktime(&t);

	printf("오늘 날짜는 %d/%d/%d %d:%d:%d입니다.\n",
		tb.tm_year + 1900, tb.tm_mon + 1, tb.tm_mday, tb.tm_hour, tb.tm_min, tb.tm_sec);

	printf("100개월 90일 80시간을 더한 날짜는 %d/%d/%d %d:%d:%d입니다.\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);

	tb.tm_mon -= 100; //100개월
	tb.tm_mday -= 90; //90일
	tb.tm_hour -= 80; //80시간

	mktime(&tb);

	printf("100개월 90일 80시간을 뺀 날짜는 %d/%d/%d %d:%d:%d입니다.\n",
		tb.tm_year + 1900, tb.tm_mon + 1, tb.tm_mday, tb.tm_hour, tb.tm_min, tb.tm_sec);
}
//시간을 실제 날짜에 맞게 자동변환해 주는 기능이 있다.
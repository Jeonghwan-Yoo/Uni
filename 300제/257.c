//오늘의 요일을 영문과 숫자로 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>

void main(void) {
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "요일 : %A", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "요일 : %a", &t);
	puts(buff);
	printf("%d\n", t.tm_wday);
}
//%A는 영문으로 요일 전부 %a는 영문으로 요일 축약
//tm_wday는 일요일이면 0, 월요일이면 1,...
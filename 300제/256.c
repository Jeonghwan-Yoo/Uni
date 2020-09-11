//올해 몇 주(week)가 경과되었는지 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>

void main(void) {
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "올해의 경과된 주 : %U", &t);

	puts(buff);
}
//경과된 일을 구하기 위해서는 %U또는 %W를 사용합니다. %U는 일요일 기준으로 주의 수, %W는 월요일 기준으로 주의 수
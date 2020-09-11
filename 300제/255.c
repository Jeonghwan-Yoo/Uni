//1월 1일부터 오늘까지 경과된 날짜수를 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>

void main(void) {
	time_t now;
	struct tm t;

	now = time(NULL);
	localtime_s(&t, &now);

	printf("올해의 경과일수 : %d\n", t.tm_yday);
}
//tm.tm_yday에는 자동으로 올해의 경과된 일 수가 계산되어 저장됩니다.
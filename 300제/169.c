//현재 국가의 날짜 및 시간을 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;
	struct tm t;

	time(&now);

	t = *localtime(&now);

	printf("현재 날짜 및 시간 : %4d.%d.%d %d:%d:%d\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
}
//struct tm *localtime(const time_t* timer);
//time()에서 구한 now값을 struct tm구조체 값으로 변환합니다. localtime()함수가 struct tm구조체의 포인터 값을
//반환하기 때문에 포인터가 가리키는 값을 얻기 위해 *localtime()처럼 사용
//대인연산자는 구조체를 대입할 수 있기 때문에 struct tm구조체 t에 localtime()함수에서 생성된 struct tm구조체를 복사
//한국은 세계 표준시보다 9시간 빠르다.
/*
struct tm{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday; 일0 월1 화2 ...
	int tm_yday; 1년의 경과 일 수 1월2일은 1,...
	int tm_isdst; 써머타임 적용이되면 0이 아닌 값
*/
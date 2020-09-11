//세계 표준시와 국내 표준시의 시간차를 계산하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now, n1, n2;
	struct tm t1, t2;

	time(&now);
	t1 = *localtime(&now);
	t2 = *gmtime(&now);

	n1 = mktime(&t1);
	n2 = mktime(&t2);

	printf("세계 표준시와 대한민국의 시간차이 : %g시간\n", difftime(n1, n2) / 3600.);
}
//struct tm *localtime(time_t *ptr);
//tm구조체는 출력이나 신쇄에 더욱 적합한 형식으로 자료를 포함.
//tm형에 대한 포인터를 선언해야하고, localtime()이 호출될 때마다 다시 사용되고 내용이 대체됩니다.
//만약 복귀되는 값을 저장하기 원한다면 프로그램에서는 독립된 tm형 구조체를 선언하고 정적 구조체의 값을 복사해야 합니다.
//time_t mktime(struct tm *ntime);
//tm구조체에서 time_t형으로 값을 변환하는 함수다.
//localtime()은 TZ라는 환경변수를 참조하며, TZ은 _timezone, _daylight 그리고 _tzname의 환경 변수를 갖습니다.
//이 변수들을 설정하기 위해서는 _tzset() 함수를 사용합니다.
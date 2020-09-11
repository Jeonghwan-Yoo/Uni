//for 문을 중복하여 0~10000000까지 순환시킬 때 경과시간을 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>

void main(void) {
	time_t s1, s2;
	double gop=0.0;
	int i;

	time(&s1);

	for (i = 0;i < 10000000;i++) {
		gop = gop * 100;
	}

	time(&s2);

	printf("경과시간 : %g초\n", difftime(s2, s1));
}
//double difftime(time_t timer1, time_t timer0);
//timer1은 종료시간이며, timer0은 시작 시간입니다.
//assert() 프로그램읭 버그를 분석하는데 사용됩니다. <assert.h> void assert(int expression);
//인수 expression은 확인하기 원하는 어떤 변수나 c의 수식이 될 수 있습니다.
//expression이 TRUE로 평가되면 assert는 아무 것도 수행하지 않지만, expression이 FALSE로 평가되면,
//assert()는 stderr로 에러 메시지를 출력하고 프로그램의 실행을 마치게 됩니다.
//버그는 프로그램이 컴파일되지 않게 하거나 또는 프로그램이 컴파일되게 하면서도 부정확한 결과를 나타내거나
//부적절하게 실행되게 하는 것을 말합니다.
//difftime()사용 시 바꾸면 음수의 값이 나옵니다.
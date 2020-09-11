//시간을 5초간 지연하는 sleep()함수를 구현하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>

void sleep(int sec);

void main(void) {
	time_t n1, n2;

	time(&n1);
	sleep(5);
	time(&n2);

	printf("%g초가 지연되었습니다.\n", difftime(n2, n1));
}

void sleep(int sec) {
	clock_t ct;
	ct = clock();
	while (ct + CLK_TCK * sec > clock());
}
//CLK_TCK는 CLOCKS_PER_SEC값과 동일하며, 1000입니다. clock()함수가 현재 실행중인 함수에서 소비한 시간을
//1/1000초 단위로 반환하기 때문에.
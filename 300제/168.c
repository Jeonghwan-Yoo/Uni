//1970년 1월 1일부터 현재까지 경과된 초의 수를 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>

void main(void) {
	time_t now;

	time(&now);
	printf("1970년 1월 1일부터 현재까지 경과된 초 : %d\n", now);
}
//time_t time(time_t* timer);
//timer는 경과된 시간을 읽어올 변수입니다.
//time_t형 변수는 내부적으로 long형으로 선언
//세계 표준시 기준
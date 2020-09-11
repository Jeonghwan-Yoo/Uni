//날짜 및 시간을 구하고 1/1000초를 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#pragma warning(disable:4996)

void main(void) {
	struct _timeb tb;
	struct tm t;

	_ftime(&tb);

	t = *localtime(&tb.time);

	printf("현재 날짜 및 시간 : %4d.%d.%d %d:%d:%d.%d\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour,
		t.tm_min, t.tm_sec, tb.millitm);

}
//void _ftime(struct _timeb* timeptr);
//timeptr은 날짜 및 시간이 읽혀진 _timeb 구조체 버퍼입니다.
/*
struct _timeb{
	time_b time; //time_t
	unsigned short millitm; //1/1000
	short timezone; //세계 표준시와 현지와의 분수의 차이
	short dstflag; //써버타임 적용 시 0이 아닌 값
};
*/
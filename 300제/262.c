//���ݱ��� �н��� ��� ����� �����ؼ� �پ��� ��¥ �� �ð��� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#pragma warning(disable:4996)

void main(void) {
	struct _timeb tb;
	struct tm t;
	char buff[100];

	_ftime(&tb);

	localtime_s(&t, &tb.time);

	printf("%4d-%d-%d %d:%d:%d.%d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec, tb.millitm);

	printf(ctime(&tb.time));
	printf(asctime(&t));
	puts(_strdate(buff)); //mon/day/year
	puts(_strtime(buff)); //hour:min:sec
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S %p (%a)", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%#Y-%#m-%#d %#H:%#M:%#S %p (%a)", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%c", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%x %X", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%#c", &t);
	puts(buff);
	strftime(buff, sizeof(buff), "%#x", &t);
	puts(buff);
}
//c�� ��¥+�ð�, x�� ��¥ X�� �ð�, #�� �ڼ��� ���ڷ�.
//%#H�� ����ϸ�, 02�� 2�� ǥ��.
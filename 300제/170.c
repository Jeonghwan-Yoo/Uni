//��¥ �� �ð��� ���ϰ� 1/1000�ʸ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>
#pragma warning(disable:4996)

void main(void) {
	struct _timeb tb;
	struct tm t;

	_ftime(&tb);

	t = *localtime(&tb.time);

	printf("���� ��¥ �� �ð� : %4d.%d.%d %d:%d:%d.%d\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour,
		t.tm_min, t.tm_sec, tb.millitm);

}
//void _ftime(struct _timeb* timeptr);
//timeptr�� ��¥ �� �ð��� ������ _timeb ����ü �����Դϴ�.
/*
struct _timeb{
	time_b time; //time_t
	unsigned short millitm; //1/1000
	short timezone; //���� ǥ�ؽÿ� �������� �м��� ����
	short dstflag; //���Ÿ�� ���� �� 0�� �ƴ� ��
};
*/
//������ 1��~12�������� ������ ��¥�� ���ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>

#define DAYSEC 86400L //�ʷ� �Ϸ�

void main(void) {
	int i;
	time_t now;
	struct tm t1, t2;
	int n1, n2, last;

	now = time(NULL);
	localtime_s(&t1, &now);
	t1.tm_mday = 1; //1�Ϸ� ����.
	t2 = t1;

	for (i = 0;i <= 11;i++) {
		t1.tm_mon = i;
		t2.tm_mon = i + 1;
		n1 = mktime(&t1);
		n2 = mktime(&t2);
		last = (n2 - n1) / DAYSEC;
		printf("%d�� %2d���� ������ ��¥�� %d���Դϴ�.\n", t1.tm_year + 1900, t1.tm_mon + 1, last);
	}
}
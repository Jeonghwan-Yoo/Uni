//���� ��¥�� �������� D-Day�� ���ϰ� D-Day���� �� ���� ���Ҵ��� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

#define DAYSEC 86400L

void main(void) {
	time_t now;
	struct tm t, dday = { 0,0,0,8,8,2020 }; //2005�� 8�� 8��
	int n1, n2, nDday;

	now = time(NULL);
	localtime_s(&t, &now);

	dday.tm_year -= 1900;
	dday.tm_mon -= 1;

	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;

	n1 = mktime(&t); //����ð� �ʷιٲ�
	n2 = mktime(&dday); //DDAY �ʷ� �ٲ�.

	nDday = (n2 - n1) / DAYSEC;

	printf("������ ��¥�� %s", ctime(&now));
	printf("�ּ����� �� : %d�� ���ҽ��ϴ�. (%d/%d/%d)\n", nDday, dday.tm_year + 1900, dday.tm_mon + 1, dday.tm_mday);
}
//���α׷��� �̽ļ��̶� ���α׷��� �ҽ� �ڵ带 � ȯ�濡�� �ٸ� ȯ������ �󸶳� ���� �̵���ų �� �ִ����� ���ϴ� ���Դϴ�.
//C�� ���� �̽ļ��� ���� ���α׷��� ��� �� �ϳ�.
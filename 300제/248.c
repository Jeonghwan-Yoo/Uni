//���� ��¥�� �������� ũ������������ ���� �ð��� ��,��,��,��,�ʷ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;
	struct tm t, christmas = { 0,0,0,25,12,2019 };
	int n1, n2, nChristmas;

	now = time(NULL);
	localtime_s(&t, &now);

	christmas.tm_year -= 1900; //struct tm �������� ��ȯ
	christmas.tm_mon -= 1;

	n1 = mktime(&t);
	n2 = mktime(&christmas);

	nChristmas = n2 - n1;
	
	localtime_s(&christmas, &nChristmas);

	printf("������ ��¥�� %s", ctime(&now));
	printf("ũ������������ ���� �ð��� %d���� %d�� %d�ð� %d�� %d���Դϴ�.\n",
		christmas.tm_mon, christmas.tm_mday, christmas.tm_hour, christmas.tm_min, christmas.tm_sec);
}
//���� ������ ��¥ �� �ð��� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	time_t now;
	struct tm t;

	time(&now);

	t = *localtime(&now);

	printf("���� ��¥ �� �ð� : %4d.%d.%d %d:%d:%d\n", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
}
//struct tm *localtime(const time_t* timer);
//time()���� ���� now���� struct tm����ü ������ ��ȯ�մϴ�. localtime()�Լ��� struct tm����ü�� ������ ����
//��ȯ�ϱ� ������ �����Ͱ� ����Ű�� ���� ��� ���� *localtime()ó�� ���
//���ο����ڴ� ����ü�� ������ �� �ֱ� ������ struct tm����ü t�� localtime()�Լ����� ������ struct tm����ü�� ����
//�ѱ��� ���� ǥ�ؽú��� 9�ð� ������.
/*
struct tm{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday; ��0 ��1 ȭ2 ...
	int tm_yday; 1���� ��� �� �� 1��2���� 1,...
	int tm_isdst; ���Ÿ�� �����̵Ǹ� 0�� �ƴ� ��
*/
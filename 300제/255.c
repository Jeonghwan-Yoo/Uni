//1�� 1�Ϻ��� ���ñ��� ����� ��¥���� ���ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>

void main(void) {
	time_t now;
	struct tm t;

	now = time(NULL);
	localtime_s(&t, &now);

	printf("������ ����ϼ� : %d\n", t.tm_yday);
}
//tm.tm_yday���� �ڵ����� ������ ����� �� ���� ���Ǿ� ����˴ϴ�.
//���� �� ��(week)�� ����Ǿ����� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>

void main(void) {
	time_t now;
	struct tm t;
	char buff[100];

	now = time(NULL);
	localtime_s(&t, &now);
	strftime(buff, sizeof(buff), "������ ����� �� : %U", &t);

	puts(buff);
}
//����� ���� ���ϱ� ���ؼ��� %U�Ǵ� %W�� ����մϴ�. %U�� �Ͽ��� �������� ���� ��, %W�� ������ �������� ���� ��
//1970�� 1�� 1�Ϻ��� ������� ����� ���� ���� ���ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>

void main(void) {
	time_t now;

	time(&now);
	printf("1970�� 1�� 1�Ϻ��� ������� ����� �� : %d\n", now);
}
//time_t time(time_t* timer);
//timer�� ����� �ð��� �о�� �����Դϴ�.
//time_t�� ������ ���������� long������ ����
//���� ǥ�ؽ� ����
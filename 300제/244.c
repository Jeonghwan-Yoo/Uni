//��/��/�� ��:��:�ʸ� ���Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	FILE* fp;
	char buff[200];
	time_t now;
	struct tm t;

	fopen_s(&fp, "file11.txt", "w+");

	if (fp == NULL) {
		perror("���� ���� ���� ����");
		_fcloseall();
		return;
	}

	now = time(NULL); //���� ǥ�ؽ�
	t = *localtime(&now); //�ѱ� ǥ�ؽ÷� ��ȯ.
	sprintf(buff, "%d/%d/%d %d:%d:%d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);

	fputs(buff, fp);
	fcloseall();

	puts(buff);
	puts("�ð��� file11.txt�� �����Ͽ����ϴ�.");
}
//�ð� ���� ���� �ΰ��� ���
//1. now=time(NULL);
//2. time(&now);
//file_name.txt������ �����Ͽ� �� ���� ���ڸ� �д� ���α׷��� �ڼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int ch;

	fopen_s(&fp, "file_name.txt", "r");

	if (fp == NULL) {
		puts("���� ���� ����");
	}
	else {
		ch = fgetc(fp);
		if (ferror(fp)) {
			perror("���� �б� ����");
		}
		fclose(fp);
	}
}
//void perror(const char* string);
//perror()�Լ��� ���� ������ ���е� �� ���ο� ���Ͽ� ��� �޽����� �����ݴϴ�.
//strerror�� ����մϴ�.
//perror�� ���������� error��� �ý��� ���������� ���� ���Ͽ� _sys_errlist�迭�� �����͸� �����Ͽ� ������ ����� �ݴϴ�.
//�� ���� ���� �����Ϸ���,
/*
extern int errno;
extern char* _sys_errlist[];
*/
//perror�� ������ ó���ϱ� ���ؼ� � ������ ���������� �ʽ��ϴ�.
//ó���ϱ� ���ؼ��� ���α׷��� �����ϴ� �Ͱ� ���� ������ �����ϵ��� �����ϴ� ������ �����ؾ��մϴ�.
//���α׷��� �����ϴ� ������ errno�� ���� ������ Ư���� Ȯ���Ͽ� �����˴ϴ�.
//���� ���� errno�� ����ϱ� ���� errno.h�� �ʿ����� �ʽ��ϴ�.
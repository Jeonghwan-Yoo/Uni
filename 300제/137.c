//file.txt ������ �����ϰ�, ���� 'A'�� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE *fp;

	fopen_s(&fp, "file.txt", "w+");

	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		fputc('A', fp);
		puts("���� 'A'�� ���Ͽ� �����Ͽ����ϴ�.");
		fclose(fp);
	}
}
//int fputc(int c, FILE* stream);
//c�� ������ �����̸�, stream�� ����� ������ �������Դϴ�.
//w+�� ������ �ִ� ������ �����ϰ�, �ٽ� �����մϴ�. ���� ������ ������ ���� �ִ�.
/*
struct _iobuf{
	char* _ptr;
	int _cnt;
	char* _base;
	int _flag;
	int _file;
	int _charbuf;
	int _bufsiz;
	char* _tmpfname;
};
typedef struct _iobuf FILE;
*/
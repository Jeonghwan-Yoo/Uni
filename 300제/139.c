//"���ѹα�"�� ���Ͽ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file1.txt", "w+");

	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		fputs("���ѹα�\n",fp);
		fclose(fp);
	}
}
//int fputs(const char* string, FILE* stream);
//string�� ������ ���ڿ�, stream�� ����� ������ ������.
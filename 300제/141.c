//������ ���� file.txt ���Ͽ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int i = 12345;

	fopen_s(&fp, "file2.txt", "w+");

	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		fprintf(fp, "%d", i);
		fclose(fp);
	}
}
//int fprintf(FILE* stream, const char* format[,argument]...);
//format�� printf�Լ��� ���� ������ ���� ���� ���ڿ�.
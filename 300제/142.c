//141���� ������ ������ ���� �д� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int i;

	fopen_s(&fp, "file2.txt", "r");

	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		fscanf_s(fp, "%d", &i);
		printf("i=%d\n", i);
		fclose(fp);
	}
}
//int fscanf(FILE* stream, const char* format[,argument]...);
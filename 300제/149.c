//148���� �ۼ��� file.txt������ ���̸� ���ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file4.txt", "r");

	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		fseek(fp, 0L, SEEK_END);
		printf("������ ���� : %d\n", ftell(fp)); //5
		fclose(fp);
	}
}
//������ ���̸� ���ϱ� ���ؼ��� �ǳ����� �̵��� ftell�ϸ� �ȴ�.
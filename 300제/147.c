//���� �����͸� ������ ������ �̵��ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file4.txt", "w+");

	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		printf("���� �������� ��ġ : %d\n", ftell(fp)); //0
		fputs("abcde", fp);
		printf("���� �������� ��ġ : %d\n", ftell(fp)); //5
		rewind(fp);
		printf("���� �������� ��ġ : %d\n", ftell(fp)); //0
		fseek(fp, 0L, SEEK_END);
		printf("���� �������� ��ġ : %d\n", ftell(fp)); //5
		fclose(fp);
	}
}
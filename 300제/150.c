//���� �������� ��ġ�� ���ϴ� ���α׷��� fgetpos() �Լ��� ����Ͽ� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	fpos_t pos;

	fopen_s(&fp, "file4.txt", "w+");

	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		fputs("abcde", fp);
		fgetpos(fp, &pos);
		printf("���� �������� ��ġ : %d\n", pos); //5
		fclose(fp);
	}
}
//int fgetpos(FILE* stream, fpos_t* pos);
//pos�� ���� �������� ��ġ�� ����˴ϴ�.
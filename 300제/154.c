//������ �аų� �� �� ���� �߻� ������ Ȯ���ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int ch;

	fopen_s(&fp, "file4.txt", "r");

	if (fp == NULL) {
		puts("������ ������ �� �����ϴ�.");
	}
	else {
		while (!feof(fp)) {
			ch = fgetc(fp);
			if (ferror(fp)) {
				puts("������ �д� �߿� ������ �߻��Ͽ����ϴ�.");
			}
			printf("���� ���� : %c\n", ch);
		}
		fclose(fp);
	}
}
//int ferror(FILE* stream);
//������ �аų� �� �� ������ �߻��Ͽ������� ���θ� Ȯ���ϱ� ���� ����մϴ�.
//������ �ִ� ��� 0�� �ƴ� ���� ��ȯ�մϴ�.
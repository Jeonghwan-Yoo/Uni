//���� �����͸� ������ ó������ �̵��ϴ� ���α׷��� �ۼ��ϼ���.
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
		fseek(fp, 0L, SEEK_SET); //ó�����κ��� 0��ŭ������ ��
		printf("���� �������� ��ġ : %d\n", ftell(fp)); //0
		fclose(fp);
	}
}
//int fseek(FILE* stream, long offset, int origin);
//offset�� ������ �̵��� �Ÿ��̸�, origin�� �̵��� ������ ��ġ�Դϴ�.
//���� �������� ��ġ�� ������ ó���� �������� �ؼ� 0L��ŭ �̵��մϴ�.
//��, ������ ó������ �̵��ϴ� ���Դϴ�. 
//SEEK_SET�� ó���̹Ƿ� offset�� ���
//SEEK_END�� �������̹Ƿ� offset�� ����
//SEEK_CUR�� ���� ��ҿ� ���ؼ� ������ �� �ִ�.



//242���� ����� ���Ͽ��� "���ѹα�"�� "�ѱ�"���� ��ü�Ͽ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable:4996)

void main(void) {
	FILE* fpR, *fpW;
	char buff[200];
	char *pbuf, *dup;
	int len, pos1, pos2;

	fopen_s(&fpR, "file10.txt", "r");

	if (fpR == NULL) {
		perror("���� �б� ���� ����");
		return;
	}
	
	fopen_s(&fpW, "file_change.txt", "w+");

	if (fpW == NULL) {
		perror("���� ���� ���� ����");
		fcloseall();
		return;
	}
	while (!feof(fpR)) {
		fgets(buff, 200, fpR);

		pbuf = strstr(buff, "���ѹα�");

		if (pbuf) {
			len = strlen(buff); //���� ���ڿ��� ����
			pos1 = pbuf - buff; //���ѹα��� �˻��� ��ġ

			dup = strdup(buff); //���� ���ڿ��� �ϳ� �� ����.
			strnset(&buff[pos1], 0, len - pos1); //���ѹα��� 0���� ä��ϴ�.
			strcat(buff, "�ѱ�"); //�ѱ��� �߰��մϴ�
			
			pos1 = pbuf - buff + strlen("���ѹα�"); //���ѹα� ������ ��ġ�� ����մϴ�.
			pos2 = pbuf - buff + strlen("�ѱ�"); //���ѹα� ������ ��ġ�� �ѱ��� �߰��� ���� ��ġ�� ����մϴ�.

			strcpy(&buff[pos2], &dup[pos1]); //�ѱ��� �߰��� ���ۿ� ���ѹα� ������ ���ڿ��� �����մϴ�.
			free(dup); //�޸� ����.
		}
		if (!feof(fpR)) fputs(buff, fpW);
	}
	fcloseall();
	puts("���ѹα��� �ѱ����� ��� ��ü�Ͽ����ϴ�.");
}
//269���� �ۼ��� addrlist.txt ������ �о�鿩 ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h> //printf, fopen, fwrite, fclose

#define ADDRFILE "addrlist.txt"

typedef struct tagLinkedList {
	char name[30]; //�̸�
	char tel[30]; //��ȭ
	char addr[100]; //�ּ�

	struct tagLinkedList *prev;
	struct tagLinkedList *next;
}ADDR;

void main(void) {
	ADDR addr;
	FILE *fp;

	fopen_s(&fp, ADDRFILE, "rb");

	if (fp == NULL) {
		perror("���� ���� ����");
		return;
	}

	while (!feof(fp)) {
		fread(&addr, 1, sizeof(ADDR), fp);
		if (ferror(fp)) {
			fclose(fp);
			perror("���� �б� ����");
			return;
		}
		if (feof(fp)) break;

		printf("�̸� : %s\n", addr.name);
		printf("��ȭ : %s\n", addr.tel);
		printf("�ּ� : %s\n", addr.addr);
	}
	fclose(fp);
}
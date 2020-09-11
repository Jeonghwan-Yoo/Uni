//269���� ������ addrlist.txt ������ �ּ� �����͸� ���� ��ũ�� ����Ʈ�� �а�, �ּҸ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h> //printf, puts, fopen, fwrite, fclose, getchar
#include <malloc.h> //malloc, free
#include <string.h> //strcpy, strstr
#pragma warning(disable:4996)

#define ADDRFILE "addrlist.txt"

typedef struct tagLinkedList {
	char name[30];
	char tel[30];
	char addr[100];

	struct tagLinkedList *prev;
	struct tagLinkedList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;
ADDR *g_pFind;

int add_list(const ADDR *addr) {
	ADDR *plocal;

	//g_pAddrHead�� �ʱ�ȭ���� ���� ���, �� ���� ����˴ϴ�.
	if (g_pAddrHead == NULL) {
		g_pAddrHead = malloc(sizeof(ADDR)); //ADDR ����ü �Ҵ�

		if (g_pAddrHead == NULL) {
			return 0;
		}

		g_pAddrHead->prev = NULL; //ó������ �ݵ�� NULL�� �ʱ�ȭ
		g_pAddrHead->next = NULL; //ó������ �ݵ�� NULL�� �ʱ�ȭ
	}
	else { //g_pAddrHead�� �ʱ�ȭ�� �� ��� ����˴ϴ�.
		plocal = malloc(sizeof(ADDR)); //ADDR ����ü �Ҵ�

		if (plocal == NULL) {
			return 0;
		}

		g_pAddrHead->next = plocal; //���� ����Ʈ�� ����
		plocal->prev = g_pAddrHead; //���� ����Ʈ�� ����
		g_pAddrHead = plocal; //���� ����Ʈ�� plocal�� ����
		g_pAddrHead->next = NULL; //���� ����Ʈ�� NULL�� ����
	}

	strcpy(g_pAddrHead->name, addr->name);
	strcpy(g_pAddrHead->tel, addr->tel);
	strcpy(g_pAddrHead->addr, addr->addr);

	return 1;
}

void get_addrlist(void) {
	ADDR addr;
	FILE *fp;

	fp = fopen(ADDRFILE, "rb");

	if (fp == NULL) {
		perror("���� ���� ����");
		return;
	}
	while (!feof(fp)) {
		fread(&addr, sizeof(ADDR), 1, fp);

		if (ferror(fp)) {
			fclose(fp);
			perror("���� �б� ����");
			return;
		}

		if (feof(fp)) break;

		if (add_list(&addr) == 0) {
			printf("�ּ� �����͸� ��ũ�� ����Ʈ�� �߰��� �� �����ϴ�.\n");
		}
	}
	fclose(fp);
}

void SetHeadPosition(void) {
	if (g_pAddrHead == NULL) return;

	while (g_pAddrHead->prev) {
		g_pAddrHead = g_pAddrHead->prev;
	}
}

int find_list(const char *name) {
	ADDR *plocal;

	SetHeadPosition(); //g_pAddrHead�� ù �ּ� �����͸� ����Ű���� ����
	plocal = g_pAddrHead;

	while (plocal) {
		if (strstr(plocal->name, name)) { //�̸��� �˻�
			puts(plocal->name);
			puts(plocal->tel);
			printf("%s\n\n", plocal->addr);
			g_pFind = plocal;
			return 1;
		}
	}
	printf("\n%s�� ã�� �� �����ϴ�.\n\n", name);
	return 0;
}

void delete_list(void) {
	ADDR *plocal;

	if (g_pFind->prev == NULL) {
		if (g_pFind->next == NULL) { //1��
			free(g_pFind);
			g_pAddrHead = NULL;
		}
		else { //�� ��
			plocal = g_pFind->next;
			free(g_pFind);
			plocal->prev = NULL;
			g_pAddrHead = plocal;
		}
	}
	else if (g_pFind->next == NULL) { //�� ��
		plocal = g_pFind->prev;
		free(g_pFind);
		plocal->next = NULL;
		g_pAddrHead = plocal;
	}
	else { //�߰�
		plocal = g_pFind->prev;
		plocal->next = g_pFind->next;

		plocal = g_pFind->next;
		plocal->prev = g_pFind->prev;

		free(g_pFind);
		g_pAddrHead = plocal;
	}
	printf("�˻��� �ּ� �����͸� �����Ͽ����ϴ�.\n\n");
}

void remove_list(void) {
	ADDR *plocal;
	FILE *fp;

	if (g_pAddrHead == NULL) return;

	fp = fopen(ADDRFILE, "w+b");

	if (fp == NULL) {
		perror("���� ���� ����");
	}

	SetHeadPosition();

	//�� ���� �޸� ����
	while (g_pAddrHead) {
		plocal = g_pAddrHead->next;

		if (fp) fwrite(g_pAddrHead, 1, sizeof(ADDR), fp);

		free(g_pAddrHead);

		g_pAddrHead = plocal;
	}
	g_pAddrHead = NULL; //�����ϱ� ���� �ʱ�ȭ

	if (fp) fclose(fp);
}

void main(void) {
	char name[30];
	int ch;

	get_addrlist();

	puts("������ �̸��� �Է��ϼ���.");

	while (1) {
		printf("������ �̸� : ");
		gets(name);
		if (strlen(name) == 0) break;
		if (find_list(name) == 1) {
			printf("%s�� �����Ͻðڽ��ϱ�(y/n)?", name);
			ch = getchar();
			while (getchar() != '\n');
			if (ch == 'Y' || ch == 'y') {
				delete_list();
			}
		}
	}
	remove_list();
}
//�ּ� �����͸� ������ ��ũ�� ����Ʈ�� �ּ� �����͸� ���Ͽ� �����մϴ�.
//�����Ϸ���
//ù ��ũ�� �����ϱ� ���ؼ� ��� �����Ͱ� ��ũ�� ����Ʈ���� �� ��° ��ũ�� ����Ű���� ����.
//������ ��ũ�� �����ϱ� ���ؼ� ������ �ٷ� ���� ��ũ�� next�����͸� NULL�� ����.
//�����Ǵ� �ٷ� �� ��ũ�� next �����͸� �����Ǵ� �ٷ� ���� ��ũ�� ����Ű���� ����.
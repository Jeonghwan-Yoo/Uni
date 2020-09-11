//269���� ������ addrlist.txt ������ �ּ� �����͸� ���� ��ũ�� ����Ʈ�� �а�, �̸��� ���� �˻��� �ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h> //printf, puts, fopen, fwrite, fclose
#include <malloc.h> //malloc, free
#include <string.h> //strcpy, strstr
#pragma warning(disable:4996)

#define ADDRFILE "addrlist.txt"

typedef struct tagLinkedList {
	char name[30]; //�̸�
	char tel[30]; //��ȭ
	char addr[100]; //�ּ�

	struct tagLinkedList *prev;
	struct tagLinkedList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;

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
		g_pAddrHead->next = NULL; //���� ����Ʈ�� NULL�� ����.
	}

	strcpy(g_pAddrHead->name, addr->name);
	strcpy(g_pAddrHead->tel, addr->tel);
	strcpy(g_pAddrHead->addr, addr->addr);

	return 1;

}

void get_addrlist(void) {
	ADDR addr;
	FILE *fp;

	fopen_s(&fp, ADDRFILE, "rb");

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
			return 1;
		}
		plocal = plocal->next;
	}

	printf("\n%s�� ã�� �� �����ϴ�.\n\n", name);

	return 0;
	
}

void remove_list(void) {
	ADDR *plocal;

	if (g_pAddrHead == NULL) return;

	//PA�� ����Ʈ�� �� ó������ �̵�
	while (g_pAddrHead->prev) {
		g_pAddrHead = g_pAddrHead->prev;
	}

	//�� ���� �޸� ����
	while (g_pAddrHead) {
		plocal = g_pAddrHead->next;

		free(g_pAddrHead);

		g_pAddrHead = plocal;
	}
	g_pAddrHead = NULL; //������ �ϱ� ���� �ʱ�ȭ.
}
void main(void) {
	char name[30];

	get_addrlist();

	puts("�˻��� �̸��� �Է��ϼ���");

	while (1) {
		printf("�̸� : ");
		gets(name);
		if (strlen(name) == 0) break;
		find_list(name);
	}

	remove_list();
}
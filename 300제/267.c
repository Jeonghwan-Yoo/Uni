//5���� �̸�, ��ȭ��ȣ �׸��� �ּҸ� �����ϰ� ����ϴ� ���α׷��� ���� ��ũ�� ����Ʈ�� ����Ͽ� �ۼ��ϼ���.
#include <stdio.h> //printf, puts
#include <malloc.h> //malloc, free
#include <string.h> //strcpy
#pragma warning(disable:4996)

int add_list(char *name, char *tel, char *addr);
void print_list(void);
void remove_list(void);

typedef struct tagLinkedList {
	char name[30]; //�̸�
	char tel[30]; //��ȭ��ȣ
	char addr[100]; //�ּ�

	struct tagLinkedList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;

void main(void) {
	add_list("ȫ�浿", "1111", "����Ư���� ���α�");
	add_list("ȫ���", "2222", "����Ư���� ������");
	add_list("Mr.Kim", "3333", "����Ư���� ���α�");
	add_list("��C", "4444", "����Ư���� ������");
	add_list("��C", "5555", "���������� ����");

	print_list();
	remove_list();
}

int add_list(char *name, char* tel, char *addr) {
	ADDR *plocal, *pn = g_pAddrHead; //pn�� ��ũ�� ����Ʈ�� ������ �����͸� ã�� ���� ���˴ϴ�.

	//g_pAddrHead�� �ʱ�ȭ���� ���� ���, �� ���� ����˴ϴ�.
	if (g_pAddrHead == NULL) {
		g_pAddrHead = malloc(sizeof(ADDR)); //����ü �Ҵ�

		if (g_pAddrHead == NULL) {
			return 0;
		}

		g_pAddrHead->next = NULL; //ó������ �ݵ�� NULL�� �ʱ�ȭ
		plocal = g_pAddrHead;
	}
	else {
		plocal = malloc(sizeof(ADDR)); //ADDR ����ü �Ҵ�

		if (plocal == NULL) {
			return 0;
		}
		while (pn->next) {
			pn = pn->next; //ù �����Ϳ��� ������ �����ͷ� ���� �ڵ�.
		}
		pn->next = plocal; //���� ����Ʈ�� ����
		plocal->next = NULL; //���� ����Ʈ�� NULL�� ����
	}

	strcpy(plocal->name, name); //���� �Ҵ�� ����ü�� �̸� ����.
	strcpy(plocal->tel, tel); //���� �Ҵ�� ����ü�� ��ȭ ����.
	strcpy(plocal->addr, addr); //���� �Ҵ�� ����ü�� �ּ� ����.

	return 1;
}

void print_list(void) {
	int count = 1;
	ADDR *plist;

	plist = g_pAddrHead;

	//�� ���� ���
	while (plist) {
		printf("No. %d\n", count++);
		puts(plist->name);
		puts(plist->tel);
		printf("%s\n\n", plist->addr);

		plist = plist->next;
	}
}

void remove_list(void) {
	ADDR *plocal;

	//�� ���� �޸� ����
	while (g_pAddrHead) {
		plocal = g_pAddrHead->next; //g_pAddrHead�� ����Ű�� �����ּ� �������� ���� �̸� plocal�� ����.

		free(g_pAddrHead); //g_pAddrHead�� ����Ű�� �ּ� �����͸� ����.

		g_pAddrHead = plocal; //g_pAddrHead->next ���� �ٽ� �޾ƿɴϴ�.
	}
}
//��ũ�� ����Ʈ�� ������ �κа� ��ũ�κ����� �����Ǹ�, �������� ����/�˻�/���� ���� ������ �ڷ��� ���� ���.
//������ ��ũ�� ���� �����Ͱ� ����� ������ ����Ű�� �ֽ��ϴ�.

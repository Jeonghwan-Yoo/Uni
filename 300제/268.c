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

	struct tagLinkedList *prev;
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

int add_list(char *name, char *tel, char *addr) {
	ADDR *plocal;

	//g_pAddrHead�� �ʱ�ȭ���� ���� ���, �� ���� ����˴Ϥ���.
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

		g_pAddrHead->next = plocal; //���� ����Ʈ�� ����.
		plocal->prev = g_pAddrHead; //���� ����Ʈ�� ����.
		g_pAddrHead = plocal; //���� ����Ʈ�� plocal�� ����
		g_pAddrHead->next = NULL; //���� ����Ʈ�� NULL�� ����
	}

	strcpy(g_pAddrHead->name, name); //���� �Ҵ�� ����ü�� �̸� ����
	strcpy(g_pAddrHead->tel, tel); //���� �Ҵ�� ����ü�� ��ȭ ����
	strcpy(g_pAddrHead->addr, addr); //���� �Ҵ�� ����ü�� �ּ� ����
}

void print_list(void) {
	int count = 1;
	ADDR *plocal;

	plocal = g_pAddrHead;

	//plocal ����Ʈ�� �� ó������ �̵�
	while (plocal->prev) {
		plocal = plocal->prev;
	}

	//�� ���� ���
	while (plocal) {
		printf("No. %d\n", count++);
		puts(plocal->name);
		puts(plocal->tel);
		printf("%s\n\n", plocal->addr);

		plocal = plocal->next;
	}
}

void remove_list(void) {
	ADDR *plocal;

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
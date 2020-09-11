//�ּ� �����͸� �Է¹޴� ���α׷��� �ۼ��۰�, �Էµ� �����͸� ���Ϸ� �����Ͻʽÿ�.
#include <stdio.h> //printf,puts,fopen,fwrite, fclose
#include <malloc.h> //malloc, free
#include <string.h> //strcpy
#pragma warning(disable:4996)

typedef struct tagLinkedList {
	char name[30]; //�̸�
	char tel[30]; //��ȭ
	char addr[100]; //�ּ�

	struct tagLinkedList *prev;
	struct tagLinkedList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;

int add_list(ADDR *addr) {
	ADDR *plocal;
	FILE *fp;

	fp = fopen("addrlist.txt", "a+b");
	if (fp == NULL) {
		perror("���� ���� ����");
		return 0;
	}

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

	fwrite(addr, 1, sizeof(ADDR), fp);

	fclose(fp);

	return 1;
}

void print_list(void) {
	int count = 1;
	ADDR *plocal;

	if (g_pAddrHead == NULL) return;

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

	if (g_pAddrHead == NULL) return;

	//PA�� ����Ʈ�� �� ó������ �̵�
	while (g_pAddrHead->prev) {
		g_pAddrHead = g_pAddrHead -> prev;
	}

	//�� ���� �޸� ����
	while (g_pAddrHead) {
		plocal = g_pAddrHead->next;
		free(g_pAddrHead);
		g_pAddrHead = plocal;
	}

	g_pAddrHead = NULL; //������ �ϱ� ���� �ʱ�ȭ
}

void main(void) {
	ADDR addr;
	puts("�߰��� �ּ� �����͸� �Է��ϼ���.");
	puts("���α׷��� �����Ϸ��� ����Ű�� ġ�ʽÿ�.");

	while (1) {
		memset(&addr, 0, sizeof(ADDR));

		printf("�̸� : ");
		gets(addr.name);

		if (strlen(addr.name) == 0) break;

		printf("��ȭ : ");
		gets(addr.tel);

		printf("�ּ� : ");
		gets(addr.addr);

		if (add_list(&addr)) {
			printf("\n�ּҷϿ� �����Ͱ� �߰��Ǿ����ϴ�.\n\n");
		}
	}
	print_list();
	remove_list();
}
//��ũ�� ����Ʈ�� ���ۺκп� ��ũ �߰��ϱ�
//1. malloc()�� ����Ͽ� �޸� ������ �Ҵ��ϸ� ����ü�� ������ �����մϴ�.
//2. ���ο� ��ũ�� next �����͸� ��� �������� ���� ������ �����մϴ�.
//�� ���� ��ũ�� ����Ʈ�� ��� �ִٸ� NULL�� �� ���̰�, �׷��� �ʴٸ� ���� ù ��° ��ũ�� �ּҰ� �� ���Դϴ�.
//3. ��� �����Ͱ� ���ο� ��Ҹ� ����Ű�� �˴ϴ�.
//��ũ�� ����Ʈ�� �������� ��ũ �߰��ϱ�
//��� �����Ϳ��� �����ϰ� ������ ��ũ�� ã�� ������ ��ũ�� ����Ʈ�� ���� ���ʴ�� �����ؾ� �մϴ�. ��������ũ�� �߰��ϸ�
//1. malloc()�� ����Ͽ� �޷θ� ������ �Ҵ��ϸ� ����ü�� ������ �����մϴ�.
//2. ������ ��ũ�� next �����Ͱ� ���ο� ��ũ�� ����Ű�� �����մϴ�. ���ο� ��ũ�� �ּҴ� malloc()�� ���� ���͵˴ϴ�.
//3. ���ο� ��ũ�� ��ũ�� ����Ʈ���� ������ �׸��̶�� ���� ǥ���ϱ� ���� ���ο� ��ũ�� next �����͸� NULL�� �����մϴ�.
//��ȯ ���� ��ũ�� ����Ʈ�� �� ó�� prev�� �� ���� ����Ʈ ���� ������, �� ���� next�� ��ó�� ����Ʈ�� ���� �����ϴ�.
//���� �߿��� ����
//��ũ�� ����Ʈ�� ũ��� ���α׷��� ����Ǵ� ���� �����ϰų� ������ �� �ְ�, �̸� ������ �ʿ䰡 �����ϴ�.
//��ũ�� ����Ʈ�� ��� �������� ���ο� ��ũ�� ���� �߰��ϰ�, ������ ��ũ�� ������ �� �����Ƿ� ���ĵ� ������ �����ϱ� ����.
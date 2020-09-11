//DLL implementation
#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node *next;
	struct node *prev;
};

struct node *head = 0; //initialization

void addToDLL(int k) {
	//���ο� ��� ����
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->i = k;
	new_node->next = 0;
	new_node->prev = 0;

	if (head == 0) { //DLL�� �ƹ��� ���� ���
		head = new_node;
		return;
	}
	else {
		struct node *cur = head;
		while (cur->next != 0) {
			cur = cur->next;
		}
		//cur�� ������ ��带 ����Ű�� �ִ�.
		cur->next = new_node;
		new_node->prev = cur;
		return;
	}
}

void printDLL() {
	struct node *cur = head;
	while (cur != 0) {
		printf("%d --> ", cur->i);
		cur = cur->next;
	}
}

void insertToDLL(int where, int what) {
	//���� ���� ��ġ�� ã�´�.
	struct node *cur = head;
	struct node *new_node = 0;
	while (1) {
		if (cur == 0) { //�ƹ��͵�������
			return;
		}
		if (cur->i != where) { //where���̶� ����������
			cur = cur->next; //������ҷ� �̵�.
		}
		else { //������ ����.
			break;
		}
	}
	//���� ������ �ȴ�.
	//cur�� ���� ���� ��ġ�� ����Ű�� ����
	new_node = (struct node*)malloc(sizeof(struct node)); //new_node->��
	new_node->i = what;
	new_node->next = new_node->prev = 0;

	new_node->next = cur->next; //new��->curnext��
	new_node->prev = cur; //cur��<-new��
	cur->next = new_node; //cur��->new��
	if (new_node->next != 0) { //�������� �ƴ϶��
		new_node->next->prev = new_node; //new��<-curnext��
	}
}

int main(void) {
	addToDLL(1);
	addToDLL(2);
	addToDLL(3);
	addToDLL(4);

	// 1 - 2 - 3 - 4

	insertToDLL(3, 10); //1->2->3->10->4
	insertToDLL(1, 50); //1->50->2->3->10->4
	insertToDLL(8, 100);

	printDLL();

	//1, 50, 2, 3, 10, 4

	return 0;
}
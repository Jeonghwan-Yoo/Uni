//DLL implementation
#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node *next; //��
	struct node *prev; //��
};

struct node *head = 0; //initialization

void addToDLL(int k) {
	//���ο� ��� ����
	struct node *new_node = (struct node*)malloc(sizeof(struct node)); //new_node->��
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
		cur->next = new_node; //null�ΰ��� new_node
		new_node->prev = cur; //cur<-new_node��
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

int main(void) {
	addToDLL(1);
	addToDLL(2);
	addToDLL(3);
	addToDLL(4);

	// 1 - 2 - 3 - 4

	printDLL();

	//1, 2, 3, 4

	return 0;
}
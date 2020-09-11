#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node *next;
};

struct node *head = 0; //�� �տ� ��带 ����Ű�� �� �ʱⰪ�� 0

void addToSLL(int v) {
	//���ο� ��带 �Ҵ�
	struct node *_new = (struct node*)malloc(sizeof(struct node));
	_new->i = v;
	_new->next = 0;

	if (head == 0) {
		//SLL�� �ƹ��͵� ���� ���
		head = _new;
		return;
	}
	else {
		//SLL�� �̹� ���𰡰� �ִ� ���
		struct node *last = 0;
		last = head;
		while (last->next != 0) {
			last = last->next;
		}
		//�� ������ last�� ������ ��带 ����Ű�� ����.
		last->next = _new;
		return;
	}
}

void printSLL() {
	struct node *cur = head;
	while (cur != 0) {
		printf("%d\n", cur->i);
		cur = cur->next;
	}
}

void destroySLL() {
	struct node *cur = head; //head�� ����Ű�� ���� cur�� ����Ų��.
	while (1) {
		if (head == 0) { //�� ���ָ� 
			break; //��
		}
		head = head->next; //head�� �����ּҿ� head�� ����Ű�� �ϰ�,
		free(cur); //cur�� ����Ű�� ���� �޸�����.
		cur = head; //�׸���, �����ּҸ� ����Ű�� head�� cur�� ����Ű�� �Ѵ�.
	}
}

int main(void) {

	addToSLL(1);
	addToSLL(2);
	addToSLL(3);

	printSLL();

	destroySLL();

	addToSLL(4);
	addToSLL(5);
	addToSLL(6);

	printSLL();

	return 0;
}
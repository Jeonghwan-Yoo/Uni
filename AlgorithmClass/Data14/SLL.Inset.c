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

void insertToSLL(int a, int b) {
	struct node *cur = head; //head�� ����Ű�� ���� cur�� ����Ű�� ��.
	//a�� �߰ߵ� ������
	while (cur != 0) {
		if (cur->i == a) { //i���� a�� ������.
			//������ ��ġ�� ã����.
			struct node *_new = (struct node*)malloc(sizeof(struct node)); //_new->��
			_new->i = b; //���� ���� ������ b���� �ִ´�.
			//������ �����ϴ� ����
			_new->next = cur->next; //_new������ cur������ �ּҸ� �����Ѿ��Ѵ�. _new��->��
			cur->next = _new; //cur������ _new�� �����Ѿ� �Ѵ�. cur��->_new��->��
			return;
		}
		else { //��ã���� ��� �̵�.
			cur = cur->next; 
		}
	}
}

int main(void) {

	addToSLL(1);
	addToSLL(2);
	addToSLL(3);

	insertToSLL(2, 10);
	insertToSLL(10, 100);
	insertToSLL(90, 4);

	printSLL(); //1, 2, 10, 100, 3

	return 0;
}
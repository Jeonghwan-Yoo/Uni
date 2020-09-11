#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node *next;
};

struct node *head = 0; //�� �տ� ��带 ����Ű�� �� �ʱⰪ�� 0

void addToSLL(int v) {
	//���ο� ��带 �Ҵ�
	struct node *_new = (struct node*)malloc(sizeof(struct node)); //_new->��
	_new->i = v; //���ȿ� i���� v
	_new->next = 0; //�������� ����Ű�� ���� ����.

	if (head == 0) {
		//SLL�� �ƹ��͵� ���� ���
		head = _new; //_new�� ����Ű�� ���� head�̴�.
		return;
	}
	else {
		//SLL�� �̹� ���𰡰� �ִ� ���
		struct node *last = 0;
		last = head; //head�� ����Ű�� ���� last�� ����Ű�� ���̴�.
		while (last->next != 0) { //last�� ���� �ּҰ� �� ������
			last = last->next; //�ٽ� �� ������ �̵�.
		}
		//�� ������ last�� ������ ��带 ����Ű�� ����.
		last->next = _new; //_new�� ����Ű�� �ּҴ� �ᱹ ������ ���� �ּ��̴�.
		return;
	}
}

void printSLL() {
	struct node *cur = head; //head�� ����Ű�� ���� cur�̶�� ���� ����� ����Ű�� �Ѵ�.
	while (cur != 0) { //������ ������
		printf("%d\n", cur->i); //i�� ���� ���.
		cur = cur->next; //�� ���� ������ �̵�.
	} //������ ��.
}

int main(void) {

	addToSLL(1);
	addToSLL(2);
	addToSLL(3);

	printSLL();

	return 0;
}
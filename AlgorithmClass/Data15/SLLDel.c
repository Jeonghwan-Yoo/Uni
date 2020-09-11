//head->��->��->��->null
//SLL�� struct node���ְ� head�� ������ ���¿��� ��ġ�� ã������ cur�� �����Ѵ�.
//�� 4�� addSLL, destroySLL, insertSLL, deleteSLL�� ���ش�.
//addSLL�� �Ǹ������� �߰��ϴ� ��. cur->next==0�� ã�Ƽ� cur->next=new_node�� �ǰ� �ϸ�ȴ�.
//destorySLL�� ó������ �����ؼ� ��� ����. head=head->next�� �Ű��ְ� free(cur)�� cur=head�� �缳��.
//insertSLL�� ��ġ�� ã�Ƽ� �� �ڿ� �ִ´�. cur�� ���ؼ� ã��, new_node->next=cur->next��
//�׸��� cur->next=new_node�� ���ش�.
//deleteSLL�� ��ġ�� ã�Ƽ� ����� ������ �� �� ��ġ�� �˾ƾ��Ѵ�. cur,cur_prev�� �ʿ��ϸ�,
//cur_prev->next�� �ش� ��ġ�� ��, cur�� ��ġ�� ���� �ϰ� cur_prev->next=cur->next�� �ǰ� �ϰ�,
//free(cur)�� ���ش�.
//return��ġ�� �׻� �� �����Ѵ�.
//SLL�� Array���� �ӵ��� �������� ��ġ�� ����� �ٲܼ� �ִ�.


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
	struct node *cur = head;
	//a�� �߰ߵ� ������
	while (cur != 0) {
		if (cur->i == a) {
			//������ ��ġ�� ã����.
			struct node *_new = (struct node*)malloc(sizeof(struct node));
			_new->i = b;
			//������ �����ϴ� ����
			_new->next = cur->next;
			cur->next = _new;
			return;
		}
		else {
			cur = cur->next;
		}
	}
}

void deleteFromSLL(int v) {
	//�ϴ�, ���� ��带 ã�´�.
	//del_next:���� ��� �ٷ� ���� ��带 ����Ű�� ������
	//del:���� ��带 ����Ű�� ������.
	struct node *del_next, *del;
	del_next = head; //del_next�� ����Ű�� ���� head�� ����Ű�� ���̴�.

	//�����尡 head�� ���.
	if (head->i == v) {
		del = head; //������� head�� ���ϰ�
		head = head->next; //head�� head���� �ּҸ� ����Ű�� �Ѵ�.
		free(del); //�����.
		return;
	}
	else {
		//del_next�� �Ͽ��� ���� ����� �ٷ� ���� ��带 ����Ű�� �Ѵ�.
		while (del_next->next != 0) {
			if (del_next->next->i == v) { //����� ����� ����带 ã�´�.
				del = del_next->next; //del_next��->del��->��
				del_next->next = del->next; //del_next��->��
				free(del); //�޸� ����.
				return;
			}
			else { //v�� ã�� �� ���� ��� �̵�.
				del_next = del_next->next;
			}
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

	deleteFromSLL(10);
	deleteFromSLL(50);

	printSLL(); //1, 2, 100, 3

	return 0;
}
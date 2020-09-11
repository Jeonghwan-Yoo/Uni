//head<=>��<=>��<=>��->null
//DLL�� struct node���ְ� head�� ������ ���¿��� ��ġ�� ã������ cur�� �����Ѵ�.
//�� 4�� addDLL, destroyDLL, insertDLL, deleteDLL�� ���ش�.
//addDLL�� �Ǹ������� �߰��ϴ� ��. cur->next==0�� ã�Ƽ� cur->next=new_node�� �ǰ� �ϰ�
//new_node->prev=cur�� �ǰ� �Ѵ�.
//destoryDLL�� ó������ �����ؼ� ��� ����. head=head->next�� �Ű��ְ� free(cur)�� cur=head�� �缳��.
//insertDLL�� ��ġ�� ã�Ƽ� �� �ڿ� �ִ´�. cur�� ���ؼ� ã��, new_node->next=cur->next��
//�׸��� cur->next=new_node, new_node->prev=cur�� ���ش�.
//�ڿ� �� ���� ��� new_node->next->prev=new_node�� �ǰ� �ؼ� �������׸� �� �����. 4�� �ʿ�.
//deleteDLL�� ��ġ�� ã�Ƽ� ����� ������ �� �� ��ġ�� �˾ƾ������� DLL�� cur�ϳ��� �־ �ȴ�.
//cur�� �ش� ��ġ�� ��, cur->prev->next=cur->next�� �ǰ� �ϰ�, 
//�ڿ� �� ���� ���, cur->next->prev=cur->prev
//free(cur)�� ���ش�.
//return��ġ�� �׻� �� �����Ѵ�.
//SLL�� �ٸ��� �ڿ� ������ ��츦 ������ ������ �߰������� �տ��� �ڸ� �����ϴ°��� �����.
//�޸𸮰� �� �þ���� �յڷ� �����̴µ� ��������.

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
		if (cur == 0) {
			return;
		}
		if (cur->i != where) {
			cur = cur->next;
		}
		else {
			break;
		}
	}
	//���� ������ �ȴ�.
	//cur�� ���� ���� ��ġ�� ����Ű�� ����
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->i = what;
	new_node->next = new_node->prev = 0;

	new_node->next = cur->next;
	new_node->prev = cur;
	cur->next = new_node;
	if (new_node->next != 0) {
		new_node->next->prev = new_node;
	}
}

void delFromDLL(int which) {
	struct node *cur = head;
	//���� ��带 ã�´�.
	while (1) {
		if (cur == 0) { //�ƹ��͵� ������ return
			return;
		}
		if (cur->i != which) { //���� �ƴϸ�
			cur = cur->next; //�������� �̵�
		}
		else { //ã���� ����
			break;
		}
	}
	//cur�� ���� ��带 ����Ű�� �ִ�.
	if (cur == head) { //����� ���� head�̸�
		head = head->next; //head�� �ű��.
		if (head != 0) {
			head->prev = 0;
		}
		free(cur);
	}
	else { //head�� �ƴϸ�
		cur->prev->next = cur->next; //�̰����� node�� �ϳ� �������. cur_prev�� ���� cur��������Ŵ. curprev��->curnext��
		if (cur->next != 0) { //cur_next�� 0�̾ƴϸ�
			cur->next->prev = cur->prev; //�ٽ� cur�������� cur_prev�� ����. curprev��<-curnext��
		}
		free(cur);
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

	delFromDLL(50);
	delFromDLL(8);
	delFromDLL(1);
	delFromDLL(4);
	printDLL();

	//2, 3, 10

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node *next;
};

struct node *head = 0; //맨 앞에 노드를 가리키는 것 초기값은 0

void addToSLL(int v) {
	//새로운 노드를 할당
	struct node *_new = (struct node*)malloc(sizeof(struct node));
	_new->i = v;
	_new->next = 0;

	if (head == 0) {
		//SLL에 아무것도 없는 경우
		head = _new;
		return;
	}
	else {
		//SLL에 이미 무언가가 있는 경우
		struct node *last = 0;
		last = head;
		while (last->next != 0) {
			last = last->next;
		}
		//이 순간에 last는 마지막 노드를 가리키고 있음.
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
	struct node *cur = head; //head가 가리키는 곳에 cur이 가리킨다.
	while (1) {
		if (head == 0) { //다 없애면 
			break; //끝
		}
		head = head->next; //head의 다음주소에 head를 가리키게 하고,
		free(cur); //cur이 가리키는 곳을 메모리해제.
		cur = head; //그리고, 다음주소를 가리키는 head로 cur이 가리키게 한다.
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
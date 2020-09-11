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

void insertToSLL(int a, int b) {
	struct node *cur = head; //head가 가리키는 곳이 cur이 가리키는 곳.
	//a가 발견될 때까지
	while (cur != 0) {
		if (cur->i == a) { //i값이 a인 곳에서.
			//삽입할 위치를 찾았음.
			struct node *_new = (struct node*)malloc(sizeof(struct node)); //_new->ㅁ
			_new->i = b; //새로 만든 공간에 b값을 넣는다.
			//실제로 삽입하는 과정
			_new->next = cur->next; //_new다음은 cur다음의 주소를 가리켜야한다. _newㅁ->ㅁ
			cur->next = _new; //cur다음은 _new를 가리켜야 한다. curㅁ->_newㅁ->ㅁ
			return;
		}
		else { //못찾으면 계속 이동.
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
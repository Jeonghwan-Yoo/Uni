#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node *next;
};

struct node *head = 0; //맨 앞에 노드를 가리키는 것 초기값은 0

void addToSLL(int v) {
	//새로운 노드를 할당
	struct node *_new = (struct node*)malloc(sizeof(struct node)); //_new->ㅁ
	_new->i = v; //ㅁ안에 i값은 v
	_new->next = 0; //ㅁ다음의 가리키는 값은 없다.

	if (head == 0) {
		//SLL에 아무것도 없는 경우
		head = _new; //_new가 가리키는 곳이 head이다.
		return;
	}
	else {
		//SLL에 이미 무언가가 있는 경우
		struct node *last = 0;
		last = head; //head가 가리키는 곳이 last가 가리키는 곳이다.
		while (last->next != 0) { //last의 다음 주소가 또 있으면
			last = last->next; //다시 그 옆으로 이동.
		}
		//이 순간에 last는 마지막 노드를 가리키고 있음.
		last->next = _new; //_new가 가리키는 주소는 결국 마지막 다음 주소이다.
		return;
	}
}

void printSLL() {
	struct node *cur = head; //head가 가리키는 곳에 cur이라는 것을 만들고 가리키게 한다.
	while (cur != 0) { //뭔가가 있으면
		printf("%d\n", cur->i); //i의 값을 출력.
		cur = cur->next; //그 다음 번지로 이동.
	} //없으면 끝.
}

int main(void) {

	addToSLL(1);
	addToSLL(2);
	addToSLL(3);

	printSLL();

	return 0;
}
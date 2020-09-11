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
	//새로운 노드 생성
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->i = k;
	new_node->next = 0;
	new_node->prev = 0;

	if (head == 0) { //DLL에 아무도 없을 경우
		head = new_node;
		return;
	}
	else {
		struct node *cur = head;
		while (cur->next != 0) {
			cur = cur->next;
		}
		//cur는 마지막 노드를 가리키고 있다.
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
	//끼워 넣을 위치를 찾는다.
	struct node *cur = head;
	struct node *new_node = 0;
	while (1) {
		if (cur == 0) { //아무것도없으면
			return;
		}
		if (cur->i != where) { //where값이랑 같지않으면
			cur = cur->next; //다음장소로 이동.
		}
		else { //같으면 멈춤.
			break;
		}
	}
	//끼워 넣으면 된다.
	//cur는 끼워 넣을 위치를 가리키는 상태
	new_node = (struct node*)malloc(sizeof(struct node)); //new_node->ㅁ
	new_node->i = what;
	new_node->next = new_node->prev = 0;

	new_node->next = cur->next; //newㅁ->curnextㅁ
	new_node->prev = cur; //curㅁ<-newㅁ
	cur->next = new_node; //curㅁ->newㅁ
	if (new_node->next != 0) { //마지막이 아니라면
		new_node->next->prev = new_node; //newㅁ<-curnextㅁ
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
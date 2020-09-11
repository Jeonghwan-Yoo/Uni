//DLL implementation
#include <stdio.h>
#include <stdlib.h>

struct node {
	int i;
	struct node *next; //뒤
	struct node *prev; //앞
};

struct node *head = 0; //initialization

void addToDLL(int k) {
	//새로운 노드 생성
	struct node *new_node = (struct node*)malloc(sizeof(struct node)); //new_node->ㅁ
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
		cur->next = new_node; //null인곳에 new_node
		new_node->prev = cur; //cur<-new_nodeㅁ
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
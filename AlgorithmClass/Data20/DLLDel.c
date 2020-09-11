//head<=>ㅁ<=>ㅁ<=>ㅁ->null
//DLL은 struct node해주고 head를 정해준 상태에서 위치를 찾기위해 cur을 생성한다.
//총 4개 addDLL, destroyDLL, insertDLL, deleteDLL을 해준다.
//addDLL은 맨마지막에 추가하는 것. cur->next==0을 찾아서 cur->next=new_node가 되게 하고
//new_node->prev=cur이 되게 한다.
//destoryDLL은 처음부터 시작해서 모두 해제. head=head->next로 옮겨주고 free(cur)후 cur=head로 재설정.
//insertDLL은 위치를 찾아서 그 뒤에 넣는다. cur을 통해서 찾고, new_node->next=cur->next로
//그리고 cur->next=new_node, new_node->prev=cur로 해준다.
//뒤에 더 있을 경우 new_node->next->prev=new_node가 되게 해서 지그제그를 잘 만든다. 4개 필요.
//deleteDLL은 위치를 찾아서 지우기 때문에 그 전 위치도 알아야하지만 DLL은 cur하나만 있어도 된다.
//cur가 해당 위치일 때, cur->prev->next=cur->next가 되게 하고, 
//뒤에 더 있을 경우, cur->next->prev=cur->prev
//free(cur)을 해준다.
//return위치를 항상 잘 생각한다.
//SLL와 다르게 뒤에 더있을 경우를 생각해 있으면 추가적으로 앞에서 뒤를 연결하는것을 만든다.
//메모리가 더 늘어나지만 앞뒤로 움직이는데 편해진다.

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
	//끼워 넣으면 된다.
	//cur는 끼워 넣을 위치를 가리키는 상태
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
	//지울 노드를 찾는다.
	while (1) {
		if (cur == 0) { //아무것도 없으면 return
			return;
		}
		if (cur->i != which) { //값이 아니면
			cur = cur->next; //다음으로 이동
		}
		else { //찾으면 멈춤
			break;
		}
	}
	//cur는 지울 노드를 가리키고 있다.
	if (cur == head) { //지우는 곳이 head이면
		head = head->next; //head를 옮긴다.
		if (head != 0) {
			head->prev = 0;
		}
		free(cur);
	}
	else { //head가 아니면
		cur->prev->next = cur->next; //이것으로 node가 하나 더없어도됨. cur_prev가 기존 cur다음가리킴. curprevㅁ->curnextㅁ
		if (cur->next != 0) { //cur_next가 0이아니면
			cur->next->prev = cur->prev; //다시 cur다음에서 cur_prev로 연결. curprevㅁ<-curnextㅁ
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
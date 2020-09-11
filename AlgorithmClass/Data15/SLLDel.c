//head->ㅁ->ㅁ->ㅁ->null
//SLL은 struct node해주고 head를 정해준 상태에서 위치를 찾기위해 cur을 생성한다.
//총 4개 addSLL, destroySLL, insertSLL, deleteSLL을 해준다.
//addSLL은 맨마지막에 추가하는 것. cur->next==0을 찾아서 cur->next=new_node가 되게 하면된다.
//destorySLL은 처음부터 시작해서 모두 해제. head=head->next로 옮겨주고 free(cur)후 cur=head로 재설정.
//insertSLL은 위치를 찾아서 그 뒤에 넣는다. cur을 통해서 찾고, new_node->next=cur->next로
//그리고 cur->next=new_node로 해준다.
//deleteSLL은 위치를 찾아서 지우기 때문에 그 전 위치도 알아야한다. cur,cur_prev가 필요하며,
//cur_prev->next가 해당 위치일 때, cur을 위치해 놓게 하고 cur_prev->next=cur->next가 되게 하고,
//free(cur)을 해준다.
//return위치를 항상 잘 생각한다.
//SLL은 Array보다 속도는 느리지만 위치를 맘대로 바꿀수 있다.


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
	struct node *cur = head;
	//a가 발견될 때까지
	while (cur != 0) {
		if (cur->i == a) {
			//삽입할 위치를 찾았음.
			struct node *_new = (struct node*)malloc(sizeof(struct node));
			_new->i = b;
			//실제로 삽입하는 과정
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
	//일단, 지울 노드를 찾는다.
	//del_next:지울 노드 바로 앞의 노드를 가리키는 포인터
	//del:지울 노드를 가리키는 포인터.
	struct node *del_next, *del;
	del_next = head; //del_next가 가리키는 곳이 head가 가리키는 곳이다.

	//지울노드가 head인 경우.
	if (head->i == v) {
		del = head; //지울곳을 head로 정하고
		head = head->next; //head는 head다음 주소를 가리키게 한다.
		free(del); //지운다.
		return;
	}
	else {
		//del_next로 하여금 지울 노드의 바로 직전 노드를 가리키게 한다.
		while (del_next->next != 0) {
			if (del_next->next->i == v) { //지우는 노드의 전노드를 찾는다.
				del = del_next->next; //del_nextㅁ->delㅁ->ㅁ
				del_next->next = del->next; //del_nextㅁ->ㅁ
				free(del); //메모리 해제.
				return;
			}
			else { //v를 찾을 때 까지 계속 이동.
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
#include <stdio.h>
#include <stdlib.h>
//원본데이터는 항상 그대로 냅두고 주소로 해보자.
//Linked list
struct node {
	int x;
	int y;
	struct node *next;
};

struct node *head = 0;

//kd-tree의 root를 가리키는 root pointer
struct kdtree_node *kd_root = 0;

//kd-tree의 노드 구조체를 정의
struct kdtree_node {
	struct node *data;
	struct kdtree_node *left;
	struct kdtree_node *right;
};

//linked list에 노드가 몇 개 있는지를 세는 함수
int howManyNodes(struct node *_head) {
	int cnt = 0;
	struct node *temp = _head;
	while (1) {
		if (temp == 0)
			return cnt;
		else {
			cnt++;
			temp = temp->next;
		}
	}
}

//array에 담긴 주소들을 x혹은y값에 따라 오름차순으로 정렬
//_byX가 1이면 x에 대해서 0이면 y에 대해서 정렬
//_size:array의 길이
void doBubbleSort(struct node **_array, int _byX, int _size) {
	int i = 0;
	int j = 0;

	for (j = 0;j < _size;j++) {
		for (i = 0;i < _size - 1 - j;i++) { //(0,1) (1,2), .....
			if (_byX == 1) { //x에 대해서 비교
				if (_array[i]->x > _array[i + 1]->x) {
					//swap
					struct node *temp = _array[i];
					_array[i] = _array[i + 1];
					_array[i + 1] = temp;
				}
			}
			else { //y에 대해서 비교
				if (_array[i]->y > _array[i + 1]->y) {
					//swap
					struct node *temp = _array[i];
					_array[i] = _array[i + 1];
					_array[i + 1] = temp;
				}
			}
		}
	}
}

struct node *rebuildSLL(struct node **_array, int from, int to) {
	//탈출 조건
	if (from > to) {
		return 0;
	}
	struct node *cur = _array[from];
	cur->next = 0; //끊어버리고 계속해서 붙여넣기 시작
	struct node *temp = cur;
	for (int i = from + 1;i <= to;i++) {
		temp->next = _array[i];
		temp->next->next = 0;
		temp = temp->next;
	}
	return cur;
}

//kd-tree를 생성해내는 함수
//반환:생성된 kdtree node를 반환한다.
//입력:kdtree에 들어갈 linked list
//		depth정보:x축 혹은 y축에 대해서 비교할 정보
//		dimension:데이터의 차원, 2차원 점의 경우 2
struct kdtree_node *build_kdtree(struct node *sll, int _depth, int _dimension) {
	//탈출 조건
	if (sll == 0) {
		return 0;
	}
	//1. SLL 노드들의 주소를 array에 저장한다.
	//SLL에 담긴 노드의 개수를 가져온다.
	int numSLLNodes = howManyNodes(sll);

	//노드 주소들을 담을 array를 할당한다.
	struct node **nodeAddrArray = (struct node**)malloc(sizeof(struct node *)*numSLLNodes);

	//array에다가 노드 주소들을 하나씩 넣는다.
	int i;
	struct node *temp = sll; //head는 고정되어야 한다.
	for (i = 0;i < numSLLNodes;i++) {
		nodeAddrArray[i] = temp;
		temp = temp->next;
	}

	//검증
	//nodeAddrArray를 이용해서 SLL 노드들의 값을 모두 출력
	//for (i = 0;i < numSLLNodes;i++) {
	//	int _x = nodeAddrArray[i]->x;
	//	int _y = nodeAddrArray[i]->y;
	//	printf("%d,%d\n", _x, _y);
	//}

	// x축 혹은 y축에 대해서 소팅하는지 결정
	int axis = _depth % _dimension;

	doBubbleSort(nodeAddrArray, !axis, numSLLNodes); //2차원 용(2!=0)

	int _median = numSLLNodes / 2;

	//이제부터 kdtree만들자
	struct kdtree_node *cur = (struct kdtree_node *)malloc(sizeof(struct kdtree_node)); //cur은 kdtree의 root
	cur->data = nodeAddrArray[_median];
	cur->left = build_kdtree(rebuildSLL(nodeAddrArray, 0, _median - 1), _depth + 1, 2);
	cur->right = build_kdtree(rebuildSLL(nodeAddrArray, _median + 1, numSLLNodes - 1), _depth + 1, 2);
	free(nodeAddrArray); //다썼으니까 free
	return cur;
}

void addToSLL(int _x, int _y) {
	//데이터를 저장할 노드를 생성한다.
	struct node *new_one = (struct node *)malloc(sizeof(struct node));
	new_one->x = _x;
	new_one->y = _y;
	new_one->next = 0;

	//SLL에 new_one을 추가한다.
	if (head == 0) {
		head = new_one;
		return;
	}
	else //SLL의 끝을 찾아서 붙여 넣는다.
	{
		struct node *temp = head;
		while (1) {
			if (temp->next == 0) //맨 끝을 찾은 경우
			{
				temp->next = new_one; //끝에 붙여 넣는다.
				return;
			}
			else //아직 맨 끝 노드가 아닌 경우
			{
				//그 다음 노드로 이동한다.
				temp = temp->next;
			}
		}
	}

}

int main(void) {


	while (1) {
		int x, y;
		scanf_s("%d", &x);
		scanf_s("%d", &y);
		if (x == -1 && y == -1) break;
		addToSLL(x, y);
	}

	int num = howManyNodes(head);
	printf("num of SLL nodes:%d\n", num);

	kd_root = build_kdtree(head, 0, 2); //head가 들어가야 할 모든 정보를 가지고 있다. 다음 root node의 주소를 반환한다.

	printf("%d %d\n", head->x, head->y);
	printf("%d %d\n", kd_root->left->data->x, kd_root->left->data->y);
	printf("%d %d\n", kd_root->left->left->right->data->x, kd_root->left->left->right->data->y);

	return 0;
}
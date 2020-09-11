#include <stdio.h>
#include <stdlib.h>
//���������ʹ� �׻� �״�� ���ΰ� �ּҷ� �غ���.
//Linked list
struct node {
	int x;
	int y;
	struct node *next;
};

struct node *head = 0;

//kd-tree�� root�� ����Ű�� root pointer
struct kdtree_node *kd_root = 0;

//kd-tree�� ��� ����ü�� ����
struct kdtree_node {
	struct node *data;
	struct kdtree_node *left;
	struct kdtree_node *right;
};

//linked list�� ��尡 �� �� �ִ����� ���� �Լ�
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

//array�� ��� �ּҵ��� xȤ��y���� ���� ������������ ����
//_byX�� 1�̸� x�� ���ؼ� 0�̸� y�� ���ؼ� ����
//_size:array�� ����
void doBubbleSort(struct node **_array, int _byX, int _size) {
	int i = 0;
	int j = 0;

	for (j = 0;j < _size;j++) {
		for (i = 0;i < _size - 1 - j;i++) { //(0,1) (1,2), .....
			if (_byX == 1) { //x�� ���ؼ� ��
				if (_array[i]->x > _array[i + 1]->x) {
					//swap
					struct node *temp = _array[i];
					_array[i] = _array[i + 1];
					_array[i + 1] = temp;
				}
			}
			else { //y�� ���ؼ� ��
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
	//Ż�� ����
	if (from > to) {
		return 0;
	}
	struct node *cur = _array[from];
	cur->next = 0; //��������� ����ؼ� �ٿ��ֱ� ����
	struct node *temp = cur;
	for (int i = from + 1;i <= to;i++) {
		temp->next = _array[i];
		temp->next->next = 0;
		temp = temp->next;
	}
	return cur;
}

//kd-tree�� �����س��� �Լ�
//��ȯ:������ kdtree node�� ��ȯ�Ѵ�.
//�Է�:kdtree�� �� linked list
//		depth����:x�� Ȥ�� y�࿡ ���ؼ� ���� ����
//		dimension:�������� ����, 2���� ���� ��� 2
struct kdtree_node *build_kdtree(struct node *sll, int _depth, int _dimension) {
	//Ż�� ����
	if (sll == 0) {
		return 0;
	}
	//1. SLL ������ �ּҸ� array�� �����Ѵ�.
	//SLL�� ��� ����� ������ �����´�.
	int numSLLNodes = howManyNodes(sll);

	//��� �ּҵ��� ���� array�� �Ҵ��Ѵ�.
	struct node **nodeAddrArray = (struct node**)malloc(sizeof(struct node *)*numSLLNodes);

	//array���ٰ� ��� �ּҵ��� �ϳ��� �ִ´�.
	int i;
	struct node *temp = sll; //head�� �����Ǿ�� �Ѵ�.
	for (i = 0;i < numSLLNodes;i++) {
		nodeAddrArray[i] = temp;
		temp = temp->next;
	}

	//����
	//nodeAddrArray�� �̿��ؼ� SLL ������ ���� ��� ���
	//for (i = 0;i < numSLLNodes;i++) {
	//	int _x = nodeAddrArray[i]->x;
	//	int _y = nodeAddrArray[i]->y;
	//	printf("%d,%d\n", _x, _y);
	//}

	// x�� Ȥ�� y�࿡ ���ؼ� �����ϴ��� ����
	int axis = _depth % _dimension;

	doBubbleSort(nodeAddrArray, !axis, numSLLNodes); //2���� ��(2!=0)

	int _median = numSLLNodes / 2;

	//�������� kdtree������
	struct kdtree_node *cur = (struct kdtree_node *)malloc(sizeof(struct kdtree_node)); //cur�� kdtree�� root
	cur->data = nodeAddrArray[_median];
	cur->left = build_kdtree(rebuildSLL(nodeAddrArray, 0, _median - 1), _depth + 1, 2);
	cur->right = build_kdtree(rebuildSLL(nodeAddrArray, _median + 1, numSLLNodes - 1), _depth + 1, 2);
	free(nodeAddrArray); //�ٽ����ϱ� free
	return cur;
}

void addToSLL(int _x, int _y) {
	//�����͸� ������ ��带 �����Ѵ�.
	struct node *new_one = (struct node *)malloc(sizeof(struct node));
	new_one->x = _x;
	new_one->y = _y;
	new_one->next = 0;

	//SLL�� new_one�� �߰��Ѵ�.
	if (head == 0) {
		head = new_one;
		return;
	}
	else //SLL�� ���� ã�Ƽ� �ٿ� �ִ´�.
	{
		struct node *temp = head;
		while (1) {
			if (temp->next == 0) //�� ���� ã�� ���
			{
				temp->next = new_one; //���� �ٿ� �ִ´�.
				return;
			}
			else //���� �� �� ��尡 �ƴ� ���
			{
				//�� ���� ���� �̵��Ѵ�.
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

	kd_root = build_kdtree(head, 0, 2); //head�� ���� �� ��� ������ ������ �ִ�. ���� root node�� �ּҸ� ��ȯ�Ѵ�.

	printf("%d %d\n", head->x, head->y);
	printf("%d %d\n", kd_root->left->data->x, kd_root->left->data->y);
	printf("%d %d\n", kd_root->left->left->right->data->x, kd_root->left->left->right->data->y);

	return 0;
}
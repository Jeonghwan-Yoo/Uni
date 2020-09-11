#include <stdio.h>
#include <stdlib.h>

struct node {
	int x;
	int y;
	struct node *next;
};

struct node *root = 0;
struct kdtree_node *kd_root = 0;

struct kdtree_node {
	struct node *data;
	struct kdtree_node *left;
	struct kdtree_node *right;
};

int howManyNodes(struct node *_head) {
	int cnt = 0;
	struct node *temp = _head;
	while (1) {
		if (temp == 0) {
			return cnt;
		}
		else {
			cnt++;
			temp = temp->next;
		}
	}
}

void doBubbleSort(struct node **_array, int _byX, int _size) {
	int i = 0;
	int j = 0;
	for (j = 0;j < _size;j++) {
		for (i = 0;i < _size - 1 - j;i++) {
			if (_byX == 1) {
				if (_array[i]->x > _array[i + 1]->x) {
					struct node *temp = _array[i];
					_array[i] = _array[i + 1];
					_array[i + 1] = temp;
				}
			}
			else {
				if (_array[i]->y > _array[i + 1]->y) {
					struct node *temp = _array[i];
					_array[i] = _array[i + 1];
					_array[i + 1] = temp;
				}
			}
		}
	}
}

struct node *rebuildSLL(struct node **_array, int from, int to) {
	if (from > to) {
		return 0;
	}
	struct node *cur = _array[from];
	cur->next = 0;
	struct node *temp = cur;
	for (int i = from + 1;i <= to;i++) {
		temp->next = _array[i];
		temp->next->next = 0;
		temp = temp->next;
	}
	return cur;
}

struct kdtree_node *build_kdtree(struct node *sll, int _depth, int _dimension) {
	if (sll == 0) {
		return 0;
	}
	int numSLLNodes = howManyNodes(sll);
	struct node **nodeAddrArray = (struct node **)malloc(sizeof(struct node*)*numSLLNodes);
	int i;
	struct node *temp = sll;
	for (i = 0;i < numSLLNodes;i++) {
		nodeAddrArray[i] = temp;
		temp = temp->next;
	}
	int axis = _depth % _dimension;
	doBubbleSort(nodeAddrArray, !axis, numSLLNodes);
	int _median = numSLLNodes / 2;
	struct kdtree_node *cur = (struct kdtree_node *)malloc(sizeof(struct kdtree_node));
	cur->data = nodeAddrArray[_median];
	cur->left = build_kdtree(rebuildSLL(nodeAddrArray, 0, _median - 1), _depth + 1, 2);
	cur->right = build_kdtree(rebuildSLL(nodeAddrArray, _median + 1, numSLLNodes - 1), _depth + 1, 2);
	free(nodeAddrArray);
	return cur;
}

void addToBST(int _x, int _y) {
	struct node *new_one = (struct node*)malloc(sizeof(struct node));
	new_one->x = _x;
	new_one->y = _y;
	new_one->next = 0;

	if (root == 0) {
		root = new_one;
		return;
	}
	else {
		struct node *temp = root;
		while (1) {
			if (temp->next == 0) {
				temp->next = new_one;
				return;
			}
			else {
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
		if (x == -1 && y == -1) {
			break;
		}
		addToBST(x, y);
	}

	kd_root = build_kdtree(root, 0, 2);

	printf("%d %d\n", root->x, root->y);
	printf("%d %d\n", kd_root->left->data->x, kd_root->left->data->y);
	printf("%d %d\n", kd_root->left->left->right->data->x, kd_root->left->left->right->data->y);
}
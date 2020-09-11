#include <stdlib.h>
#include <stdio.h>

struct node {
	int i;
	struct node *left;
	struct node *right;
};

struct node *root = 0;

void addToBST(int n) {
	struct node *cur = (struct node*)malloc(sizeof(struct node));
	cur->left = cur->right = 0;
	cur->i = n;

	if (root == 0) {
		root = cur;
	}
	else {
		struct node *temp = root;
		while (1) {
			if (temp->i > cur->i) {
				//왼쪽
				if (temp->left == 0) {
					temp->left = cur;
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				//오른쪽
				if (temp->right == 0) {
					temp->right = cur;
					return;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}
}

//트리중 가장 작은 노드의 위치를 찾아 반환하는 함수.
struct node *findLeast(struct node *node) {
	struct node *cur = node;
	while (cur->left != 0) {
		cur = cur->left;
	}
	return cur;
}

struct node *removeNode(struct node *node, int key) {
	if (node == 0) { //트리가 없으면
		return 0;
	}
	if (key == node->i) { //root가 대상이면,
		//found match
		if (node->left == 0 && node->right == 0) { //root만 있을 경우
			free(node);
			return 0;
		}
		else if (node->left == 0) { //오른쪽 자식만 있는 경우
			struct node *ret = node->right;
			free(node);
			return ret; //부모에게 자식노드를 다시 연결해줌.
		}
		else if (node->right == 0) { //왼쪽 자식만 있는 경우
			struct node *ret = node->left;
			free(node);
			return ret;
		}
		else { //자식이 둘다 있는 경우
			struct node *toReplace = findLeast(node->right); //오른쪽 중에 가장 작은 노드를 가리킨다.
			node->i = toReplace->i; //root의 값에 가장 작은 값을 대입.
			node->right = removeNode(node->right, toReplace->i); //toReplace의 값을 찾아 제거.
			return node;
		}

	}
	else if (key < node->i) { //왼쪽에 있을 경우
		node->left = removeNode(node->left, key);
		return node;
	}
	else { //key>node->i 오른쪽에 있을 경우
		node->right = removeNode(node->right, key);
		return node;
	}
}
int main(void) {
	addToBST(10);
	addToBST(5);
	addToBST(20);
	addToBST(7);
	addToBST(30);

	printf("root %d\n", root->i);
	printf("left of root %d\n", root->left->i);
	printf("right of root %d\n", root->right->i);
	printf("%d\n", root->left->right->i);

	removeNode(root, 5);
	removeNode(root, 10);


	printf("------------------------------\n");
	printf("root %d\n", root->i);
	printf("left of root %d\n", root->left->i);
	printf("right of root %d\n", root->right->i);

	return 0;
}
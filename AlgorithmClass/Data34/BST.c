#include <stdlib.h>
#include <stdio.h>

struct node {
	int i;
	struct node *left;
	struct node *right;
};

struct node *root = 0;

void addToBST(int n) {
	struct node *cur = (struct node*)malloc(sizeof(struct node)); //cur->ㅁ
	cur->left = cur->right = 0;
	cur->i = n;

	if (root == 0) {
		root = cur;

	}
	else {
		struct node *temp = root;
		while (1) {
			if (temp->i > cur->i) { //root나 내려가는 값이 더 크면 왼쪽.
				//왼쪽
				if (temp->left == 0) { //왼쪽이 비어있으면,
					temp->left = cur; //왼쪽에다가 새로운 노드를 넣는다.
					return;
				}
				else { //왼쪽에 뭔가 있으면 
					temp = temp->left; //다시 왼쪽으로 이동.
				}
			}
			else { //root의 값이나 내려가는 값보다 적으면 오른쪽.
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

	return 0;
}
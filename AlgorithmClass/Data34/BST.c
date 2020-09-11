#include <stdlib.h>
#include <stdio.h>

struct node {
	int i;
	struct node *left;
	struct node *right;
};

struct node *root = 0;

void addToBST(int n) {
	struct node *cur = (struct node*)malloc(sizeof(struct node)); //cur->��
	cur->left = cur->right = 0;
	cur->i = n;

	if (root == 0) {
		root = cur;

	}
	else {
		struct node *temp = root;
		while (1) {
			if (temp->i > cur->i) { //root�� �������� ���� �� ũ�� ����.
				//����
				if (temp->left == 0) { //������ ���������,
					temp->left = cur; //���ʿ��ٰ� ���ο� ��带 �ִ´�.
					return;
				}
				else { //���ʿ� ���� ������ 
					temp = temp->left; //�ٽ� �������� �̵�.
				}
			}
			else { //root�� ���̳� �������� ������ ������ ������.
				//������
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
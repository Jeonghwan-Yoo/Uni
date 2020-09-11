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
				//����
				if (temp->left == 0) {
					temp->left = cur;
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
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

//Ʈ���� ���� ���� ����� ��ġ�� ã�� ��ȯ�ϴ� �Լ�.
struct node *findLeast(struct node *node) {
	struct node *cur = node;
	while (cur->left != 0) {
		cur = cur->left;
	}
	return cur;
}

struct node *removeNode(struct node *node, int key) {
	if (node == 0) { //Ʈ���� ������
		return 0;
	}
	if (key == node->i) { //root�� ����̸�,
		//found match
		if (node->left == 0 && node->right == 0) { //root�� ���� ���
			free(node);
			return 0;
		}
		else if (node->left == 0) { //������ �ڽĸ� �ִ� ���
			struct node *ret = node->right;
			free(node);
			return ret; //�θ𿡰� �ڽĳ�带 �ٽ� ��������.
		}
		else if (node->right == 0) { //���� �ڽĸ� �ִ� ���
			struct node *ret = node->left;
			free(node);
			return ret;
		}
		else { //�ڽ��� �Ѵ� �ִ� ���
			struct node *toReplace = findLeast(node->right); //������ �߿� ���� ���� ��带 ����Ų��.
			node->i = toReplace->i; //root�� ���� ���� ���� ���� ����.
			node->right = removeNode(node->right, toReplace->i); //toReplace�� ���� ã�� ����.
			return node;
		}

	}
	else if (key < node->i) { //���ʿ� ���� ���
		node->left = removeNode(node->left, key);
		return node;
	}
	else { //key>node->i �����ʿ� ���� ���
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
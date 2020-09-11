/*
Binary Search Tree
1. the most left side node would be the minimum node
2. the most right side node would be the maximum node

strong point
1. easy to search node
2. easy to search minimum and maximum node

*/
#include <stdlib.h> //malloc
#include <stdio.h> //printf

struct node { //SLL�����
	int number; //��
	struct node *left; //������
	struct node *right; //��������
};

struct node *root = 0; //null ��, ����Ű�� ���� ����.

void addToBST(int n) { //�Լ��� ȣ���ϸ� ���� Ư�� �ڸ��� ����ִ´�
	struct node *new_one = (struct node*)malloc(sizeof(struct node)); //�޸� �Ҵ��ؼ� new_one����
	new_one->number = n; //new_one�� ����n�̴�
	new_one->left = new_one->right = 0; //new_one�� ���ʰ� �������� Null
	if (root == 0) //no BST
	{
		root = new_one; //ó�������ϴ� ���� root�� ���� �ȴ�.
		return;
	}
	else
	{
		struct node *temp = root; //temp��� ����ü�� ����� ������ �ִ� root�� ����Ű�� �Ѵ�.
		while (1) { //���� ������� ���� ã������ ���ѷ�������
			if (n < temp->number) //������� ��n�� root�� ������ ������� left��
			{
				if (temp->left == 0) { //left�� �Դµ� �ƹ��� ���� �׷���
					temp->left = new_one; //�ű�� new_one�� ����Ű�� �Ѵ�.
					return;
				}
				else
					temp = temp->left; //left�� �Դµ� ���� �� �ִ��ϸ� root���� parent node�� ���� ���ϸ� ��������.
			}
			else //������� ��n�� root�� ������ Ŭ��� right����
			{
				if (temp->right == 0) { //right�� �Դµ� �ƹ��� ���� �׷���
					temp->right = new_one; //�ű�� new_one�� ����Ű�� �Ѵ�.
					return;
				}
				else
					temp = temp->right; //right�� �Դµ� ������ root���� parent node�� ���� ���ϸ� ��������.
			}
		}
	}
}
//recurisve used
void inorderTraversal(struct node* _node) { //��->��->��
	if (_node == 0) //Ż������, ���� ���� �ƹ��͵� �����ϸ� �׳� ������
		return;
	inorderTraversal(_node->left); //������ ���� �湮, ���� ������
	printf("%d\n", _node->number); //������ ���
	inorderTraversal(_node->right); //�׸����� ������ �湮
}

void preorderTraversal(struct node* _node) { //��->��->��
	if (_node == 0) //Ż������, ���� ���� �ƹ��͵� �����ϸ� �׳� ������
		return;
	printf("%d\n", _node->number); //��Ʈ���� ���
	preorderTraversal(_node->left); //�������� ��ĭ���� ��Ʈ ��� �������� ���
	preorderTraversal(_node->right); //�״����� ������ ��� �������� ���
}

void postorderTraversal(struct node* _node) { //��->��->��
	if (_node == 0) //Ż������, ���� ���� �ƹ��͵� �����ϸ� �׳� ������
		return;
	postorderTraversal(_node->left); //�ǿ��ʾƷ���
	postorderTraversal(_node->right); //�ǿ����ʾƷ���
	printf("%d\n", _node->number); //�ǳ��������� ���
}

struct node* findNearestNeighbor(int v, struct node *where, int minDiff, struct node *nn) { //v�� ã�� ��, �Ʈ��, �ּҰ�, �ּҰ�����Ű�� �ּ�
	//Ż������
	if (where == 0) //Ʈ���� ������
		return nn; //�׳� ���ų� ���ݱ��� �����״� �ּҰ� ���� ����
	if (where->number == v) //����� ã�°��� ������
		return where; //����� ã�� ��
	int dist = abs(where->number - v); //ã�����ϴ� ���� �Ÿ��� dist
	if (dist < minDiff) //dist�� minDiff���� ������
	{
		minDiff = dist; //�������� ���� dist�� �ٲٰ� �ȴ�.
		nn = where; //�׸��� �������� ���� ����Ű�� �ּҰ� �ش� �ش��ּҸ� ����Ų��.
	}
	if (where->number > v) //�ٵ� where�� ���� ã�� ������ ũ��
		return findNearestNeighbor(v, where->left, minDiff, nn); //going to the left(���ʿ� �ִ� ���� number���� �����Ƿ�)�ؼ� �ٽ� ���غ���
	else
		return findNearestNeighbor(v, where->right, minDiff, nn); //going to the right(�����ʿ� �ִ� ���� number���� ũ�Ƿ�)�ؼ� �ٽ� ���غ���.
}

int main(void) {
	//tree building
	addToBST(100); //100�߰�
	addToBST(50); //50�߰�
	addToBST(150); //150�߰�
	addToBST(25); //25�߰�
	addToBST(75); //75�߰�

	printf("%d\n", root->number); //root�� ���� ���
	printf("%d\n", root->left->left->number); //root->left->left�� ���� ���
	printf("\n");
	inorderTraversal(root); //root�� inorder
	preorderTraversal(root); //root�� preorder
	postorderTraversal(root); //root�� postorder

	struct node *nn1 = findNearestNeighbor(76, root, INT_MAX, NULL); //76�� ���尡��� ��?, root���� ����, int�߿� ���� ū2147483647, ���尡������ �հ��� �𸣱� ������ NULL
	printf("%d\n", nn1->number); //���� �������� ����Ű�� �ּ��� ��

	struct node *nn2 = findNearestNeighbor(99, root, INT_MAX, NULL); //99�� ���尡��� ��?, root���� ����, int�߿� ���� ū2147483647, ���尡������ �հ��� �𸣱� ������ NULL
	printf("%d\n", nn2->number); //���� �������� ����Ű�� �ּ��� ��

	struct node *nn3 = findNearestNeighbor(150, root, INT_MAX, NULL); //150�� ���尡��� ��?, root���� ����, int�߿� ���� ū2147483647, ���尡������ �հ��� �𸣱� ������ NULL
	printf("%d\n", nn3->number); //���� �������� ����Ű�� �ּ��� ��

	struct node *nn4 = findNearestNeighbor(1000, root, INT_MAX, NULL); //1000�� ���尡��� ��?, root���� ����, int�߿� ���� ū2147483647, ���尡������ �հ��� �𸣱� ������ NULL
	printf("%d\n", nn4->number); //���� �������� ����Ű�� �ּ��� ��

}
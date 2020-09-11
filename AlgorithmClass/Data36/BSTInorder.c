//Tree ������ ������ ���.
//���� �����͸� ��� ���� �������.
//(���������) ���� �ִ� ��� parent node. �Ʒ� �ִ� ��� child node.
//�� ���� �ִ� ��� root node(head ����).
//�ڽ� ��尡 ������ leaf node or terminal node.
//�ڽ� ��尡 ������ non-leaf or non-terminal.
//�Ϻκ��� sub-tree.
//���� level�� ������ sibling node.
//degree of a node:�� ��忡�� sub-tree�� ����
//degree of a tree:�� Ʈ������ degree of a node�� ���� ū ��.
//root node=1 level, ... ������ maximum level.

//Binary Tree�� degree of a tree�� 2�� tree.
//What is the maximum number of nodes on level i of binary tree? 
//1, 2, 4, ... ,2^(i-1)
//What is the maximum nubmer of nodes of a depth-k binary tree?
//1+2+4+..+2^(k-1)=2^k-1

//Traversal:Systematic way of visiting all nodes. ����Լ� �̿��Ѵ�.
//parent node�� ���� �湮�ϳĿ� ���� Preorder, Inorder and Postorder
//�̵� �Ŀ��� �ٽ� ��ó��
//preorder:visit parent node->left subtree->right subtree.
//print;preorder(root->left);preorder(root->right);
//inorder:left subtree->visit parent node->right subtree.
//preorder(root->left);print;preorder(root->right);
//postorder:left subtree->right subtree->visit parent node.
//preorder(root->left);preorder(root->right);print;
//����Լ��� �ݺ����� Ż�������� �׻� �����Ѵ�.

//Binary Search Tree
//Every node entry has a unique key.
//All the keys in the left subtree of a node are less than the key of the node.
//All the keys in the right subtree of a node are greater than the key of the node.

//insertBST
//node���� ��, parent node�� ���ϸ� �������� ����� �����ش�.

//deleteBST
//�ڽĳ�尡 0,1,2�� �� ������, key�� ã�Ƽ� free���ش�.
//�ڽĳ�尡 1�� ����
//node->left or right=���� ����� �������� return.
//�ڽĳ�尡 2�� ����
//�����Ǵ� ��尪���� ������ ������ �������� ��带 �����ؾ� �մϴ�.(findLeast)
//�׸��� �� ������ ���� ���� ���� �� ���� �ִ� ���� ���־� �մϴ�.
//��͹��� ���� ���ǹǷ� �򰥸��� �ʾƾ� �Ѵ�. Ư�� return.

//Binary Search Tree�� ����
//Easy to seach an item in the BST
//Easy to find maximum or minimum item in the BST
//Easy to sort the items in the BST
//Easy to find successor of an item in the BST

//���� ������, ���丮, Abstract Data Type

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

struct node *findLeast(struct node *node) {
	struct node *cur = node;
	while (cur->left != 0) {
		cur = cur->left;
	}
	return cur;
}

struct node *removeNode(struct node *node, int key) {
	if (node == 0) {
		return 0;
	}
	if (key == node->i) {
		//found match
		if (node->left == 0 && node->right == 0) {
			free(node);
			return 0;
		}
		else if (node->left == 0) { //������ �ڽĸ� �ִ� ���
			struct node *ret = node->right;
			free(node);
			return ret;
		}
		else if (node->right == 0) { //���� �ڽĸ� �ִ� ���
			struct node *ret = node->left;
			free(node);
			return ret;
		}
		else { //�ڽ��� �Ѵ� �ִ� ���
			struct node *toReplace = findLeast(node->right);
			node->i = toReplace->i;
			node->right = removeNode(node->right, toReplace->i);
			return node;
		}

	}
	else if (key < node->i) {
		node->left = removeNode(node->left, key);
		return node;
	}
	else { //key>node->i
		node->right = removeNode(node->right, key);
		return node;
	}
}

void inorderTraversal(struct node *node) {
	if (node == 0) { //Ż�� ����.
		return;
	}
	inorderTraversal(node->left);
	printf("%d\n", node->i);
	inorderTraversal(node->right);
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

	inorderTraversal(root);

	removeNode(root, 5);
	removeNode(root, 10);

	inorderTraversal(root);

	printf("------------------------------\n");
	printf("root %d\n", root->i);
	printf("left of root %d\n", root->left->i);
	printf("right of root %d\n", root->right->i);

	return 0;
}
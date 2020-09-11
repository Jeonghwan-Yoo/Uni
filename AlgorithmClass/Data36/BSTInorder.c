//Tree 나무를 뒤집은 모양.
//각각 데이터를 담는 곳을 노드라고함.
//(상대적으로) 위에 있는 노드 parent node. 아래 있는 노드 child node.
//맨 위에 있는 노드 root node(head 역할).
//자식 노드가 없으면 leaf node or terminal node.
//자식 노드가 있으면 non-leaf or non-terminal.
//일부분은 sub-tree.
//같은 level에 있으면 sibling node.
//degree of a node:한 노드에서 sub-tree의 개수
//degree of a tree:한 트리에서 degree of a node가 가장 큰 수.
//root node=1 level, ... 마지막 maximum level.

//Binary Tree는 degree of a tree가 2인 tree.
//What is the maximum number of nodes on level i of binary tree? 
//1, 2, 4, ... ,2^(i-1)
//What is the maximum nubmer of nodes of a depth-k binary tree?
//1+2+4+..+2^(k-1)=2^k-1

//Traversal:Systematic way of visiting all nodes. 재귀함수 이용한다.
//parent node가 언제 방문하냐에 따라 Preorder, Inorder and Postorder
//이동 후에는 다시 맨처음
//preorder:visit parent node->left subtree->right subtree.
//print;preorder(root->left);preorder(root->right);
//inorder:left subtree->visit parent node->right subtree.
//preorder(root->left);print;preorder(root->right);
//postorder:left subtree->right subtree->visit parent node.
//preorder(root->left);preorder(root->right);print;
//재귀함수와 반복문은 탈출조건을 항상 생각한다.

//Binary Search Tree
//Every node entry has a unique key.
//All the keys in the left subtree of a node are less than the key of the node.
//All the keys in the right subtree of a node are greater than the key of the node.

//insertBST
//node생성 후, parent node와 비교하며 내려가서 빈곳에 붙혀준다.

//deleteBST
//자식노드가 0,1,2일 때 나눠서, key를 찾아서 free해준다.
//자식노드가 1일 때는
//node->left or right=없앤 노드의 다음값을 return.
//자식노드가 2일 때는
//삭제되는 노드값과의 차이의 절댓값이 가장작은 노드를 선정해야 합니다.(findLeast)
//그리고 그 값으로 없앨 곳에 덮고 그 값이 있던 값을 없애야 합니다.
//재귀문이 많이 사용되므로 헷갈리지 않아야 한다. 특히 return.

//Binary Search Tree의 장점
//Easy to seach an item in the BST
//Easy to find maximum or minimum item in the BST
//Easy to sort the items in the BST
//Easy to find successor of an item in the BST

//조직 구성도, 디렉토리, Abstract Data Type

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
		else if (node->left == 0) { //오른쪽 자식만 있는 경우
			struct node *ret = node->right;
			free(node);
			return ret;
		}
		else if (node->right == 0) { //왼쪽 자식만 있는 경우
			struct node *ret = node->left;
			free(node);
			return ret;
		}
		else { //자식이 둘다 있는 경우
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
	if (node == 0) { //탈출 조건.
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
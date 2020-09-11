#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	struct node *left;
	struct node *right;
	char *name; //실제 저장공간은 없고, 저장공간의 주소를 저장할 수 있을 뿐이다.
	char *phone_number;
};

struct node *root = 0;

struct node *createNewNode(char *name, char *phoneNumber) {
	char *_name, *_phoneNumber;
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->left = 0;
	new_node->right = 0;
	_name = (char *)malloc(strlen(name) + 1); //문자열 맨마지막에는 null이있어야 하는데 strlen은 null을 제외하고 리턴
	strcpy_s(_name, strlen(name) + 1, name);

	_phoneNumber = (char *)malloc(strlen(phoneNumber) + 1); //문자열 맨마지막에는 null이있어야 하는데 strlen은 null을 제외하고 리턴
	strcpy_s(_phoneNumber, strlen(phoneNumber) + 1, phoneNumber);

	new_node->name = _name;
	new_node->phone_number = _phoneNumber;
	return new_node;
}

void addToBST(char *name, char *phoneNumber) {
	struct node *new_node = createNewNode(name, phoneNumber);
	if (root == 0) {
		root = new_node;
		return;
	}
	else {
		struct node *cur_node = root;
		while (1) {
			//strcmp:string compare return 0:s1==s2 -1:s1<s2 1:s1>s2 작은게 먼저나옴
			if (strcmp(cur_node->name, new_node->name) < 0) { //right
				if (cur_node->right == 0) {
					cur_node->right = new_node;
					return;
				}
				else {
					cur_node = cur_node->right;
				}
			}
			else if (strcmp(cur_node->name, new_node->name) > 0) { //left
				if (cur_node->left == 0) {
					cur_node->left = new_node;
					return;
				}
				else {
					cur_node = cur_node->left;
				}
			}
			else { //same
				printf("same name\n");
				return;
			}
		}
	}
}

void displayNodeInfo(struct node *node) {
	if (node == 0) {
		printf("node is null\n");
		return;
	}

	printf("name:%s phone:%s\n", node->name, node->phone_number);
}

void inorder(struct node *node) {
	if (node == 0) {
		return;
	}
	inorder(node->left);
	displayNodeInfo(node);
	inorder(node->right);
}

void searchBST(char *name) {
	struct node *cur_node = root;
	while (1) {
		if (cur_node == 0) {
			printf("%s라는 이름을 가진 사람이 없사오니, 다음 기회에...\n", name);
			return;
		}
		else {
			if (strcmp(cur_node->name, name) < 0) { //right
				cur_node = cur_node->right;
			}
			else if (strcmp(cur_node->name, name) > 0) { //left
				cur_node = cur_node->left;
			}
			else { //same
				printf("%s의 전화번호는 %s입니다.\n", name, cur_node->phone_number);
				return;
			}
		}
	}
}
int main() {
	char buff[30];

	addToBST((char*)"박철수", (char*)"000-0000-0000");
	addToBST((char*)"김영희", (char*)"000-0000-0001");
	addToBST((char*)"박민철", (char*)"000-0000-0002");

	displayNodeInfo(root);

	printf("이름을 입력해주시기 바랍니다: ");
	gets_s(buff);

	searchBST(buff); //이름을 입력받아, 전화번호를 보여준다

	return 0;
}
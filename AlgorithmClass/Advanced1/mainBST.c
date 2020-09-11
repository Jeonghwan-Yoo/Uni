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

struct node { //SLL만들기
	int number; //값
	struct node *left; //왼쪽팔
	struct node *right; //오른쪽팔
};

struct node *root = 0; //null 즉, 가리키는 값이 없다.

void addToBST(int n) { //함수를 호출하면 값을 특정 자리에 집어넣는다
	struct node *new_one = (struct node*)malloc(sizeof(struct node)); //메모리 할당해서 new_one생성
	new_one->number = n; //new_one의 값은n이다
	new_one->left = new_one->right = 0; //new_one의 왼쪽과 오른쪽은 Null
	if (root == 0) //no BST
	{
		root = new_one; //처음생성하는 값이 root에 오게 된다.
		return;
	}
	else
	{
		struct node *temp = root; //temp라는 구조체를 만들고 그전에 있던 root를 가리키게 한다.
		while (1) { //값을 집어놓을 곳을 찾기위해 무한루프생성
			if (n < temp->number) //집어놓을 값n이 root의 값보다 적을경우 left로
			{
				if (temp->left == 0) { //left로 왔는데 아무도 없다 그러면
					temp->left = new_one; //거기는 new_one을 가리키게 한다.
					return;
				}
				else
					temp = temp->left; //left로 왔는데 뭐가 또 있다하면 root말고 parent node의 값을 비교하며 내려간다.
			}
			else //집어놓을 값n이 root의 값보다 클경우 right으로
			{
				if (temp->right == 0) { //right로 왔는데 아무도 없다 그러면
					temp->right = new_one; //거기는 new_one을 가리키게 한다.
					return;
				}
				else
					temp = temp->right; //right로 왔는데 있으면 root말고 parent node의 값을 비교하며 내려간다.
			}
		}
	}
}
//recurisve used
void inorderTraversal(struct node* _node) { //왼->루->오
	if (_node == 0) //탈출조건, 넣은 값이 아무것도 없다하면 그냥 나가기
		return;
	inorderTraversal(_node->left); //왼쪽을 먼저 방문, 없을 때까지
	printf("%d\n", _node->number); //없으면 출력
	inorderTraversal(_node->right); //그리고나서 오른쪽 방문
}

void preorderTraversal(struct node* _node) { //루->왼->오
	if (_node == 0) //탈출조건, 넣은 값이 아무것도 없다하면 그냥 나가기
		return;
	printf("%d\n", _node->number); //루트먼저 출력
	preorderTraversal(_node->left); //왼쪽으로 한칸가고 루트 출력 갈때마다 출력
	preorderTraversal(_node->right); //그다음에 오른쪽 출력 갈때마다 출력
}

void postorderTraversal(struct node* _node) { //왼->오->루
	if (_node == 0) //탈출조건, 넣은 값이 아무것도 없다하면 그냥 나가기
		return;
	postorderTraversal(_node->left); //맨왼쪽아래로
	postorderTraversal(_node->right); //맨오른쪽아래로
	printf("%d\n", _node->number); //맨끝에서부터 출력
}

struct node* findNearestNeighbor(int v, struct node *where, int minDiff, struct node *nn) { //v는 찾을 값, 어떤트리, 최소값, 최소값가리키는 주소
	//탈출조건
	if (where == 0) //트리가 없으면
		return nn; //그냥 없거나 지금까지 가리켰던 주소가 제일 작음
	if (where->number == v) //어떤값이 찾는값과 같으면
		return where; //어떤값이 찾는 값
	int dist = abs(where->number - v); //찾고자하는 값과 거리를 dist
	if (dist < minDiff) //dist가 minDiff보다 작으면
	{
		minDiff = dist; //제일작은 값이 dist로 바꾸게 된다.
		nn = where; //그리고 제일작은 값을 가리키는 주소가 해당 해당주소를 가리킨다.
	}
	if (where->number > v) //근데 where의 수가 찾는 값보다 크면
		return findNearestNeighbor(v, where->left, minDiff, nn); //going to the left(왼쪽에 있는 값은 number보다 작으므로)해서 다시 비교해본다
	else
		return findNearestNeighbor(v, where->right, minDiff, nn); //going to the right(오른쪽에 있는 값은 number보다 크므로)해서 다시 비교해본다.
}

int main(void) {
	//tree building
	addToBST(100); //100추가
	addToBST(50); //50추가
	addToBST(150); //150추가
	addToBST(25); //25추가
	addToBST(75); //75추가

	printf("%d\n", root->number); //root의 값을 출력
	printf("%d\n", root->left->left->number); //root->left->left의 값을 출력
	printf("\n");
	inorderTraversal(root); //root로 inorder
	preorderTraversal(root); //root로 preorder
	postorderTraversal(root); //root로 postorder

	struct node *nn1 = findNearestNeighbor(76, root, INT_MAX, NULL); //76과 가장가까운 수?, root에서 시작, int중에 제일 큰2147483647, 가장가까운곳과 먼곳을 모르기 때문에 NULL
	printf("%d\n", nn1->number); //제일 작은값을 가리키는 주소의 값

	struct node *nn2 = findNearestNeighbor(99, root, INT_MAX, NULL); //99과 가장가까운 수?, root에서 시작, int중에 제일 큰2147483647, 가장가까운곳과 먼곳을 모르기 때문에 NULL
	printf("%d\n", nn2->number); //제일 작은값을 가리키는 주소의 값

	struct node *nn3 = findNearestNeighbor(150, root, INT_MAX, NULL); //150과 가장가까운 수?, root에서 시작, int중에 제일 큰2147483647, 가장가까운곳과 먼곳을 모르기 때문에 NULL
	printf("%d\n", nn3->number); //제일 작은값을 가리키는 주소의 값

	struct node *nn4 = findNearestNeighbor(1000, root, INT_MAX, NULL); //1000과 가장가까운 수?, root에서 시작, int중에 제일 큰2147483647, 가장가까운곳과 먼곳을 모르기 때문에 NULL
	printf("%d\n", nn4->number); //제일 작은값을 가리키는 주소의 값

}
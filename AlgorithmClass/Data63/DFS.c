//Depth First Search
//Graph Searching은 하나의 vertex에서 시작하여 Graph의 모든
//vertex를 방문하는 알고리즘(중복없이).
//DFS, BFS.
//미로찾기와 비슷
//일단 한곳으로 쭉가보자~
//길이 막히면, 갈림길이 있었던 곳으로 돌아와서 다시 시작=>스택을 이용.
//visited array를 통해 중복확인+스택(막다른길).
//방문하면 array에 체크하고 스택에 저장.
//인접노드가 없으면 pop해서 backTrack한다.
//array에 모드 체크되고, 스택을 비우면 종료.

//stack과 배열을 구성한다.
//먼저 doDFS를 시작하면 v값을 push하고 방문기록한다.
//스택이 빌때까지 계속하는데 다음 노드의 값을 받는 함수를 만든다.
//graphp[v]에서 방문하지 않았던 노드가 나오면 리턴한다.
//다음 노드를 받았을 때 모두 방문한거면, pop해준다.
//아니면, 출력하면서 push하고 방문체크한다.

#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTEX 5

struct node {
	int  v; //vertex 번호
	struct node *next;
};

struct node *graph[NUM_VERTEX]; //init with null

//vertex 방문여부 표시 배열
//if visited[i]==1, visited
int visited[NUM_VERTEX] = { 0 };

//stack related
int stack[NUM_VERTEX];
int top = -1;

void push(int v) {
	if (top == NUM_VERTEX - 1) {
		printf("------stack is full-------\n");
		return;
	}
	top++;
	stack[top] = v;
}
//return 1 if the stack is empty
//       0 otherwise
int isStackEmpty() {
	return (top == -1) ? 1 : 0;
}
int pop() {
	int temp = 0;
	if (top == -1) {
		printf("-------stack is empty-------\n");
		return -1;
	}
	temp = stack[top];
	top--;
	return temp;
}

//if doReverse==1, 1->0
//otherwise, nothing
void addEdge(int v1, int v2, int doReverse) { //0,1을 넣으면 0->1과 1->0 동시에
	struct node *new_one = (struct node *)malloc(sizeof(struct node));
	struct node *cur = graph[v1];

	new_one->v = v2;
	new_one->next = 0;

	if (cur == 0) { //v1에 아무 것도 붙어있지 않는 상태
		graph[v1] = new_one;
	}
	else { //v1에 이미 다른 vertex가 붙어있는 상태
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = new_one;
	}
	if (doReverse == 1) {
		addEdge(v2, v1, 0);
	}
	return;
}

void showAdjacentVertex(int v) {
	struct node *cur = graph[v];

	while (cur != 0) {
		printf("%d is the adjacent vertex\n", cur->v);
		cur = cur->next;
	}
}

//v와 연결된 vertex중 아직까지 방문하지 않은 vertex를 반환
//만약, 조건만족 vertex가 없으면 -1을 반환
int findNextVertex(int v) {
	struct node *cur = graph[v];
	while (cur != 0) {
		if (visited[cur->v] == 0) {
			return cur->v;
		}
		cur = cur->next;
	}
	return -1; //v에 연결된 vertex 중에 방문하지 않은 것이 없다.
}
void doDFS(int v) {
	printf("visited %d\n", v);
	//처음 해야할 작업.
	visited[v] = 1;
	push(v);

	while (isStackEmpty() == 0) {
		int next_vertex = -1;
		next_vertex = findNextVertex(stack[top]);
		if (next_vertex == -1) {
			pop();
		}
		else {
			printf("visited %d\n", next_vertex);
			visited[next_vertex] = 1;
			push(next_vertex);
		}
	}
}

void main() {
	addEdge(0, 1, 1);
	addEdge(0, 2, 1);
	addEdge(0, 4, 1);
	addEdge(1, 2, 1);
	addEdge(2, 3, 1);
	addEdge(2, 4, 1);
	addEdge(3, 4, 1);

	//vertex v1의 adjacent vertex는 누구?
	showAdjacentVertex(2);

	//vertex 0에서 시작하여 DFS를 시행
	doDFS(0);
}
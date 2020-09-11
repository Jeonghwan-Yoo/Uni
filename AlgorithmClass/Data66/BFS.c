//Breadth First Search
//연결되어 있는 모든 Vertex들을 먼저 방문(queue이용)
//위에서 차례대로 내려옴.
//Enqueued array로 방문했는지 확인+큐.
//방문하면, 다음것을 새로 더하고, 자신은 dequeue하면서 array에 체크.
//array에 다 체크가 되고 큐가 비면 종료한다.

//queue 구성하고, array도 하나 만들어 놓는다.
//doBFS 시작하면 시작 값을 enque하고 큐가 빌 때까지 하는데 방문했던건지 확인해서
//방문안한거면 dequeue해주고 방문체크하고, 그 다음 것을 enque 해놓는다.
//다음 것을 enque하는 함수를 만든다.
//graph[v]에 들어가 방문했던건지 확인하면서 enque한다.

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

//Queue related
int head = 0;
int tail = 0;
int que[NUM_VERTEX];

void enque(int v) {
	if ((tail + 1) % NUM_VERTEX == head) {
		printf("-----------Queue full-----------\n");
		return;
	}
	que[tail] = v;
	tail = (tail + 1) % NUM_VERTEX;
	return;
}

//return 1 if the queue is empty
//       0 otherwise
int isQueEmpty() {
	if (head == tail) {
		return 1;
	}
	else {
		return 0;
	}
}

//return -1 if the queue is empty
int deque() {
	int temp = -1;
	if (isQueEmpty() == 0) {
		temp = que[head];
		head = (head + 1) % NUM_VERTEX;
	}
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

void addAdjacentNonVisitedVertexToQue(int v) {
	struct node *cur = graph[v];
	while (cur != 0) {
		if (visited[cur->v] == 0) {
			enque(cur->v);
		}
		cur = cur->next;
	}
}

void doBFS(int v) {
	enque(v);
	while (isQueEmpty() == 0) {
		int k = deque();
		if (visited[k] == 0) {
			printf("BFS visited %d\n", k);
			visited[k] = 1;
			addAdjacentNonVisitedVertexToQue(k);
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

	//vertex 0에서 시작하여 BFS를 시행
	doBFS(0);
}
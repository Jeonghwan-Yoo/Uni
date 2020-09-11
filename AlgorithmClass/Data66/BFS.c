//Breadth First Search
//����Ǿ� �ִ� ��� Vertex���� ���� �湮(queue�̿�)
//������ ���ʴ�� ������.
//Enqueued array�� �湮�ߴ��� Ȯ��+ť.
//�湮�ϸ�, �������� ���� ���ϰ�, �ڽ��� dequeue�ϸ鼭 array�� üũ.
//array�� �� üũ�� �ǰ� ť�� ��� �����Ѵ�.

//queue �����ϰ�, array�� �ϳ� ����� ���´�.
//doBFS �����ϸ� ���� ���� enque�ϰ� ť�� �� ������ �ϴµ� �湮�ߴ����� Ȯ���ؼ�
//�湮���ѰŸ� dequeue���ְ� �湮üũ�ϰ�, �� ���� ���� enque �س��´�.
//���� ���� enque�ϴ� �Լ��� �����.
//graph[v]�� �� �湮�ߴ����� Ȯ���ϸ鼭 enque�Ѵ�.

#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTEX 5

struct node {
	int  v; //vertex ��ȣ
	struct node *next;
};

struct node *graph[NUM_VERTEX]; //init with null

//vertex �湮���� ǥ�� �迭
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
void addEdge(int v1, int v2, int doReverse) { //0,1�� ������ 0->1�� 1->0 ���ÿ�
	struct node *new_one = (struct node *)malloc(sizeof(struct node));
	struct node *cur = graph[v1];

	new_one->v = v2;
	new_one->next = 0;

	if (cur == 0) { //v1�� �ƹ� �͵� �پ����� �ʴ� ����
		graph[v1] = new_one;
	}
	else { //v1�� �̹� �ٸ� vertex�� �پ��ִ� ����
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

	//vertex v1�� adjacent vertex�� ����?
	showAdjacentVertex(2);

	//vertex 0���� �����Ͽ� BFS�� ����
	doBFS(0);
}
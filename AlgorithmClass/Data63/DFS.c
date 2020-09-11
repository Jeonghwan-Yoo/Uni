//Depth First Search
//Graph Searching�� �ϳ��� vertex���� �����Ͽ� Graph�� ���
//vertex�� �湮�ϴ� �˰���(�ߺ�����).
//DFS, BFS.
//�̷�ã��� ���
//�ϴ� �Ѱ����� �߰�����~
//���� ������, �������� �־��� ������ ���ƿͼ� �ٽ� ����=>������ �̿�.
//visited array�� ���� �ߺ�Ȯ��+����(���ٸ���).
//�湮�ϸ� array�� üũ�ϰ� ���ÿ� ����.
//������尡 ������ pop�ؼ� backTrack�Ѵ�.
//array�� ��� üũ�ǰ�, ������ ���� ����.

//stack�� �迭�� �����Ѵ�.
//���� doDFS�� �����ϸ� v���� push�ϰ� �湮����Ѵ�.
//������ �������� ����ϴµ� ���� ����� ���� �޴� �Լ��� �����.
//graphp[v]���� �湮���� �ʾҴ� ��尡 ������ �����Ѵ�.
//���� ��带 �޾��� �� ��� �湮�ѰŸ�, pop���ش�.
//�ƴϸ�, ����ϸ鼭 push�ϰ� �湮üũ�Ѵ�.

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

//v�� ����� vertex�� �������� �湮���� ���� vertex�� ��ȯ
//����, ���Ǹ��� vertex�� ������ -1�� ��ȯ
int findNextVertex(int v) {
	struct node *cur = graph[v];
	while (cur != 0) {
		if (visited[cur->v] == 0) {
			return cur->v;
		}
		cur = cur->next;
	}
	return -1; //v�� ����� vertex �߿� �湮���� ���� ���� ����.
}
void doDFS(int v) {
	printf("visited %d\n", v);
	//ó�� �ؾ��� �۾�.
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

	//vertex v1�� adjacent vertex�� ����?
	showAdjacentVertex(2);

	//vertex 0���� �����Ͽ� DFS�� ����
	doDFS(0);
}
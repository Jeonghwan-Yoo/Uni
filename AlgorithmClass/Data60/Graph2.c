//Graph
//�׷����� ���� ����Ǿ� �ִ� ��ü ���� ���踦 ǥ���� �� �ִ� �ڷᱸ��.
//�ִ� ��θ� ã�� �� ���. �������ִ°� �Ǵ�, �Ϲ����������ƴ���. 
//���ļ� ����(1�г����->2�г����...)
//vertex,node:����, edge:����.
//undirected:edge�� ���⼺�� ����
//directed:edge�� ���⼺�� ����.
//����ġ(weight):edge���� ����
//weighted graph:����ġ �ִ� �׷���->����ö�ִܰŸ� ã�� ��.
//adjacent vertex:������ vertex.
//degree:edge�� ����.
//indegree:������ edge�� ����.
//outdegree:������ edge�� ����.
//cycle:��θ� �̾���� ��, ��߰� ������ ���� vertex.
//complete graph:��� vertex�� adjacent�� ��. ��� ����. n(n-1)/2

//2���� �迭�� �����(vertex������ŭ).
//���� ������ 1, ������ 0.
//undirected�� �迭�� ��Ī.
//���ι����� ���� ���ι����� ����.
//vertex���������� edge�� �ʹ� ������ ������ ��ȿ������ �� �ִ�.
//->SLL�� �̿��Ѵ�.(���� �������).
//�ݴ�� edge�� �������� ���������� ������ ���� ����.
//dense graph=>2���� �迭
//sparse graph=>SLL
//v�� �ε����� ���� �������� ����.

#include <stdio.h>
#include <stdlib.h>

struct node {
	int v; //vertex ��ȣ
	struct node *next;
};

struct node *graph[4]; // init with null, SLL�� 4�� �ִٰ� ����.

void addEdge(int v1, int v2) {
	struct node *new_one = (struct node*)malloc(sizeof(struct node*));
	struct node *cur = graph[v1];
	new_one->v = v2;
	new_one->next = 0;

	if (cur == 0) { //v1�� �ƹ��͵� �پ� ���� �ʴ� ����
		graph[v1] = new_one;
		return;
	}
	else { //v1�� �̹� �ٸ� vertex�� ���� ����
		while (cur->next != 0) {
			cur = cur->next;
		}
		cur->next = new_one;
		return;
	}
}

void showAdjacentVertex(int v) {
	struct node *cur = graph[v];
	while (cur != 0) {
		printf("%d is the adjacent vertex\n", cur->v);
		cur = cur->next;
	}
}
void main() {
	addEdge(0, 1); //0->1
	addEdge(1, 0); //1->0
	addEdge(0, 2); //0->2
	addEdge(2, 0); //2->0

	//vertex v1�� adjacent vertex�� ����?
	showAdjacentVertex(0);
	return;
}
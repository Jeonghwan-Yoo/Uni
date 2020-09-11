//Minimum Spanning Tree(Kruskal �˰���)
//�׷����� ��� vertex�� �ּ� edge�� weight�� ������ �׷���
//�� cycle�� �߻����� �ʰ� ����(�迭�� ����)0.
//���� ���� edge�� ����ؼ� ���ذ�.
//�����ִ� ���� ������ ����.

//edge��=vertex��-1
//edge�� ���� ��� �̾Ƴ���, ���������� ����.
//���ʴ�� ���ϵ� ����Ŭ����� �ǳʶڴ�.

//Kruskal�˰���
//Edge���� ������� �Ѵ�.
//weight�� ������������.
//vertex-1���� edge�� ���Ե� ������ �ݺ�.
//cycle�� ���ϸ鼭(�迭�� ����).
//�迭�� ù��° col���� �� vertex
//�ι�° col���� �� vertex
//edge�� ���� ������ �ι�° col���� ���� vertex�� �����Ѵ�. (D��E�� �����ϰ� �Ǹ� D,D)
//������ �ٸ��� ������� ������ cycle�̴�.

//struct edge���� ����
//vertex���� ����ִ� �迭����.
//edge�迭�鿡 ���� �� ����
//struct edge�� swap�ؾ��ؼ� �Լ� �����,
//doMST�����.�迭�� ���� ���� ���� �� ������ְ�, edge=vertex-1�� �Ǹ� �����Ѵ�.
//�迭�� �������ֱ� ����, ���� ����� �ִ� ������ �־� ���´�.

//�ּ� ������� ��� ���� ���� ����, ��Ÿ� ���� ��

#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTEX 5
#define NUM_EDGES 8
struct node {
	int  v; //vertex ��ȣ
	int weight;
	struct node *next;
};

struct edge {
	int from;
	int to;
	int w;
};

struct edge edges[NUM_EDGES];

struct node *graph[NUM_VERTEX]; //init with null

/*------------ cycle detection array -----------*/
int cycle_detection[NUM_VERTEX] = { 0,1,2,3,4 };

/*------------ vertex �湮���� ǥ�� �迭---------*/
//if visited[i]==1, visited
int visited[NUM_VERTEX] = { 0 };

/*------------ Queue related -------------------*/
int head = 0;
int tail = 0;
int que[NUM_VERTEX];

/*------------ Stack related --------------------*/
int stack[NUM_VERTEX];
int top = -1;

/*------------ cycle detection function ---------*/
void putThemIntoSameGroup(int v1, int v2) {
	int g1 = cycle_detection[v1];
	int g2 = cycle_detection[v2];

	int smaller, bigger;

	if (g1 > g2) {
		bigger = g1;
		smaller = g2;
	}
	else {
		bigger = g2;
		smaller = g1;
	}
	{
		int i;
		//���ĺ��̳� ���� ���� vertex ������� ������.
		for (i = 0;i < NUM_VERTEX;i++) {
			if (cycle_detection[i] == bigger) {
				cycle_detection[i] = smaller;
			}
		}
	}
}

//if doReverse==1, 1->0
//otherwise, nothing
void addEdge(int v1, int v2, int w, int doReverse) { //0,1�� ������ 0->1�� 1->0 ���ÿ�
	struct node *new_one = (struct node *)malloc(sizeof(struct node));
	struct node *cur = graph[v1];

	new_one->v = v2;
	new_one->next = 0;
	new_one->weight = w;

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
		addEdge(v2, v1, w, 0);
	}
	return;
}

void swap_edge(int e1, int e2) {
	struct edge temp;
	temp = edges[e1];
	edges[e1] = edges[e2];
	edges[e2] = temp;
}

void sortEdges() {
	//��� edge�� edges�迭�� �߰�
	//ex
	//f     w     t
	//0-----5-----1
	//1-----3-----4
	//1-----6-----5
	int i;
	int edges_index = 0;
	for (i = 0;i < NUM_VERTEX;i++) {
		struct node *cur = graph[i];
		while (cur != 0) {
			edges[edges_index].from = i;
			edges[edges_index].to = cur->v;
			edges[edges_index].w = cur->weight;
			edges_index++;
			cur = cur->next;
		}
	}
	//������������ ���� by bubble sort
	{
		int x, y;
		for (y = 0;y < NUM_EDGES;y++) {
			for (x = 0;x < NUM_EDGES - 1 - y;x++) {
				if (edges[x].w > edges[x + 1].w) {
					swap_edge(x, x + 1);
				}
			}
		}
	}
}

void doMST() {
	int i;
	int mst_edges = 0;
	for (i = 0;i < NUM_EDGES;i++) {
		if (cycle_detection[edges[i].from] != cycle_detection[edges[i].to]) {
			printf("MST edge %d --- %d (%d) \n", edges[i].from, edges[i].to, edges[i].w);
			mst_edges++;
			if (mst_edges == NUM_VERTEX - 1) {
				return;
			}
			putThemIntoSameGroup(edges[i].from, edges[i].to);
		}
	}
}

void main() {
	addEdge(0, 1, 1, 0);
	addEdge(0, 2, 3, 0);
	addEdge(0, 4, 5, 0);
	addEdge(1, 2, 2, 0);
	addEdge(1, 4, 4, 0);
	addEdge(2, 4, 6, 0);
	addEdge(2, 3, 7, 0);
	addEdge(3, 4, 8, 0);

	sortEdges();

	doMST();
}
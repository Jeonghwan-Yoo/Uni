//Dijkstra
//�ϳ��� vertex�κ��� ����
//�ִ� �Ÿ��� vertex�� �ϳ��� �߰�
//��� vertex�� ���� �ִ� �Ÿ��� ã�� ������ �ݺ�

//ǥ���ʿ���.
//ù��° ���� vertex.
//�ι�° ���� K �ִܰŸ��� ã�Ҵ��� False or True.
//����° ���� D ó������ vertex������ �� �Ÿ�
//�׹�° ���� p previous/ vertex���� �ٷ����� � vertex������.
//�ʱ�ȭ�� K=All F,  D=All infinity, p=All empty.
//�ƹ��뼭�� ���� ����.
//�� ������ ���� T, 0, empty.
//�� ���� ����� D�� p�� ǥ���� �� ��ü ǥ���� ���� ���� �ſ� T.
//�� T���� �� ���� ���� D�� p�� ǥ���� �� ��ü���� ���� �����ſ� T.
//�ݺ��ϸ鼭, D�� p�� �����Ǵ��� Ȯ���Ѵ�. (T�� �̹� ��)
//���� ���� Ȯ���ؼ� ���󰡸� �ִ� ��θ� �� �� �ִ�.

//�ʱ�ȭ->F�̸鼭, �������� ������� ã�� �Լ�->ã�� �� ������ Tǥ��, update->�ݺ� �� �� ã���� display.

//����������̼�, ����ö ���

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

struct dijkstra {
	int found; //K, �ִܰŸ��� �˷����°�? 1=yes 0=no
	int distance;
	int prev_vertex;
};

struct dijkstra dtable[NUM_VERTEX];

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

//�ִܰŸ��� �˷����� ���� vertex�߿��� distance�� ���� ª�� vertex�� ��ȯ
//returns -1 if ��� vertex�� �ִܰŸ��� �˷����� ���
int findDijkstraNextVertex() {
	int i;
	int smallest_distance = 99999;
	int smallest_vertex = -1;
	//���� ���̺���� �߿� D�� �ּҰ��� ã�´�.
	for (i = 0;i < NUM_VERTEX;i++) {
		if (dtable[i].found == 0 && (dtable[i].distance < smallest_distance)) {
			smallest_vertex = i;
			smallest_distance = dtable[i].distance;
		}
	}
	return smallest_vertex;
}

void showDTable() {
	int i;
	for (i = 0;i < NUM_VERTEX;i++) {
		printf("%d: %d %d %d\n", i, dtable[i].found, dtable[i].distance, dtable[i].prev_vertex);
	}
}

void updateDTable(int v) {
	struct node *cur = graph[v];
	//cur->v�� �ᱹ ���� ���.
	while (cur != 0) {
		//�ִܰŸ��� �˷����� �ʾҰ�,
		//���� �˷��� �Ÿ�����, v�� ���� ���, �� ������, dtable�� ������Ʈ�Ѵ�.
		if (dtable[cur->v].found == 0 && (dtable[cur->v].distance > dtable[v].distance + cur->weight)) {
			dtable[cur->v].distance = dtable[v].distance + cur->weight;
			dtable[cur->v].prev_vertex = v;
		}
		cur = cur->next;
	}
}

void doDijkstra(int v) {
	//ó�� ��.
	int next_vertex = -1;
	dtable[v].distance = 0;
	while ((next_vertex = findDijkstraNextVertex()) != -1) {
		dtable[next_vertex].found = 1; //�ִܰŸ��� ã�Ҵٰ� ǥ��.
		updateDTable(next_vertex);
	}
	showDTable();
}

void initDTable() {
	int i;
	for (i = 0;i < NUM_VERTEX;i++) {
		dtable[i].found = 0;
		dtable[i].distance = 99999;
		dtable[i].prev_vertex = -1;
	}
}

void main() {
	addEdge(0, 1, 1, 1);
	addEdge(0, 2, 3, 1);
	addEdge(0, 4, 5, 1);
	addEdge(1, 2, 2, 1);
	addEdge(1, 4, 4, 1);
	addEdge(2, 4, 6, 1);
	addEdge(2, 3, 7, 1);
	addEdge(3, 4, 8, 1);

	sortEdges();

	initDTable();

	doDijkstra(0);
}
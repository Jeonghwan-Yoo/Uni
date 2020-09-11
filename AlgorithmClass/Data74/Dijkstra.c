//Dijkstra
//하나의 vertex로부터 시작
//최단 거리의 vertex를 하나씩 추가
//모든 vertex에 대한 최단 거리를 찾을 때까지 반복

//표가필요함.
//첫번째 열은 vertex.
//두번째 열은 K 최단거리를 찾았는지 False or True.
//세번째 열은 D 처음부터 vertex까지의 총 거리
//네번째 열은 p previous/ vertex가기 바로직전 어떤 vertex였는지.
//초기화는 K=All F,  D=All infinity, p=All empty.
//아무대서나 먼저 시작.
//그 시작한 곳에 T, 0, empty.
//그 다음 노드의 D와 p를 표시한 후 전체 표에서 가장 작은 거에 T.
//그 T에서 그 다음 노드와 D와 p를 표시한 후 전체에서 가장 작은거에 T.
//반복하면서, D와 p가 수정되는지 확인한다. (T는 이미 끝)
//직전 것을 확인해서 따라가면 최단 경로를 알 수 있다.

//초기화->F이면서, 가장작은 다음노드 찾는 함수->찾을 수 있으면 T표시, update->반복 후 다 찾으면 display.

//차량내비게이션, 지하철 등등

#include <stdio.h>
#include <stdlib.h>

#define NUM_VERTEX 5
#define NUM_EDGES 8

struct node {
	int  v; //vertex 번호
	int weight;
	struct node *next;
};

struct edge {
	int from;
	int to;
	int w;
};

struct dijkstra {
	int found; //K, 최단거리가 알려졌는가? 1=yes 0=no
	int distance;
	int prev_vertex;
};

struct dijkstra dtable[NUM_VERTEX];

struct edge edges[NUM_EDGES];

struct node *graph[NUM_VERTEX]; //init with null

/*------------ cycle detection array -----------*/
int cycle_detection[NUM_VERTEX] = { 0,1,2,3,4 };

/*------------ vertex 방문여부 표시 배열---------*/
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
void addEdge(int v1, int v2, int w, int doReverse) { //0,1을 넣으면 0->1과 1->0 동시에
	struct node *new_one = (struct node *)malloc(sizeof(struct node));
	struct node *cur = graph[v1];

	new_one->v = v2;
	new_one->next = 0;
	new_one->weight = w;

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
	//모든 edge를 edges배열에 추가
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
	//오름차순으로 정렬 by bubble sort
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

//최단거리가 알려지지 않은 vertex중에서 distance가 가장 짧은 vertex를 반환
//returns -1 if 모든 vertex의 최단거리가 알려졌을 경우
int findDijkstraNextVertex() {
	int i;
	int smallest_distance = 99999;
	int smallest_vertex = -1;
	//현재 테이블만든거 중에 D의 최소값을 찾는다.
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
	//cur->v는 결국 다음 노드.
	while (cur != 0) {
		//최단거리가 알려지지 않았고,
		//기존 알려진 거리보다, v를 통할 경우, 더 가까우면, dtable을 업데이트한다.
		if (dtable[cur->v].found == 0 && (dtable[cur->v].distance > dtable[v].distance + cur->weight)) {
			dtable[cur->v].distance = dtable[v].distance + cur->weight;
			dtable[cur->v].prev_vertex = v;
		}
		cur = cur->next;
	}
}

void doDijkstra(int v) {
	//처음 값.
	int next_vertex = -1;
	dtable[v].distance = 0;
	while ((next_vertex = findDijkstraNextVertex()) != -1) {
		dtable[next_vertex].found = 1; //최단거리를 찾았다고 표시.
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
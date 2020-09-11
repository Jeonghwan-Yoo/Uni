//Minimum Spanning Tree(Kruskal 알고리즘)
//그래프의 모든 vertex를 최소 edge의 weight로 연결한 그래프
//단 cycle이 발생하지 않게 주의(배열을 만듦)0.
//가장 작은 edge만 계속해서 더해감.
//갈수있는 길이 있으면 무시.

//edge수=vertex수-1
//edge를 따로 모두 뽑아내고, 작은순으로 정렬.
//차례대로 더하되 사이클생기면 건너뛴다.

//Kruskal알고리즘
//Edge만을 대상으로 한다.
//weight의 오름차순으로.
//vertex-1개의 edge가 포함될 때까지 반복.
//cycle을 피하면서(배열을 만듦).
//배열은 첫번째 col에는 각 vertex
//두번째 col에도 각 vertex
//edge를 더할 때마다 두번째 col에다 앞의 vertex를 복사한다. (D와E를 연결하게 되면 D,D)
//집안이 다르면 상관없고 같으면 cycle이다.

//struct edge새로 생성
//vertex값이 들어있는 배열생성.
//edge배열들에 저장 후 정렬
//struct edge를 swap해야해서 함수 만들고,
//doMST만든다.배열의 값이 같지 않을 때 출력해주고, edge=vertex-1이 되면 종료한다.
//배열도 정렬해주기 위해, 작은 값들어 있는 값으로 넣어 놓는다.

//최소 비용으로 모든 도시 도로 연결, 통신망 연결 등

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
		//알파벳이나 숫자 적은 vertex 순서대로 맞춰줌.
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
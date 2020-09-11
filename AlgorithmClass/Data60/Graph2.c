//Graph
//그래프는 서로 연결되어 있는 객체 간의 관계를 표현할 수 있는 자료구조.
//최단 경로를 찾을 때 사용. 인접되있는거 판단, 일방통행인지아닌지. 
//선후수 과목(1학년과목->2학년과목...)
//vertex,node:정점, edge:간선.
//undirected:edge의 방향성이 없음
//directed:edge의 방향성이 있음.
//가중치(weight):edge위의 숫자
//weighted graph:가중치 있는 그래프->지하철최단거리 찾을 때.
//adjacent vertex:인접한 vertex.
//degree:edge의 개수.
//indegree:들어오는 edge의 개수.
//outdegree:나가는 edge의 개수.
//cycle:경로를 이어봤을 때, 출발과 도착이 같은 vertex.
//complete graph:모든 vertex가 adjacent할 때. 모두 연결. n(n-1)/2

//2차원 배열을 만든다(vertex개수만큼).
//길이 있으면 1, 없으면 0.
//undirected면 배열이 대칭.
//세로방향이 시작 가로방향이 도착.
//vertex개수에비해 edge가 너무 적으면 공간이 비효율적일 수 있다.
//->SLL을 이용한다.(숫자 순서대로).
//반대로 edge가 많아지면 복잡해지고 공간도 많이 차지.
//dense graph=>2차원 배열
//sparse graph=>SLL
//v를 인덱스와 값을 착각하지 말것.

#include <stdio.h>
#include <stdlib.h>

struct node {
	int v; //vertex 번호
	struct node *next;
};

struct node *graph[4]; // init with null, SLL이 4개 있다고 생각.

void addEdge(int v1, int v2) {
	struct node *new_one = (struct node*)malloc(sizeof(struct node*));
	struct node *cur = graph[v1];
	new_one->v = v2;
	new_one->next = 0;

	if (cur == 0) { //v1에 아무것도 붙어 있지 않는 상태
		graph[v1] = new_one;
		return;
	}
	else { //v1에 이미 다른 vertex가 붙은 상태
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

	//vertex v1의 adjacent vertex는 누구?
	showAdjacentVertex(0);
	return;
}
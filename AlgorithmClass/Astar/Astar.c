//Astar 알고리즘
//Dijkstra 알고리즘의 개선(더빨리)
//최단경로를 찾기 위한 방향을 지정할 수 있다.
//즉, 가능성이 더 높은 곳을 먼저 탐색.
//가능성이 더 높지만 말도 안되게 돌아가게 만들어져 있으면 Dijkstra가 더빠를수도 있다.
//Dijkstra는 현재 위치로부터 모든 방향을 대상으로 최단 경로를 탐색(원형을 그려가며)
//A*는 특정방향을 먼저 시도하고, 타원모양을 그린다.

//Dijkstra
//1. 각 장소에 해당하는 값을 초기화. 종료는 not-found, 최단거리는 무한대, 직전노드는 없음
//2. 출발지에서 직접적으로 연결된 장소들에 대해서는 최단거리를 기입하고, 직전노드에 출발지를 기입한다.
//3. 최단경로가 not-found이면서 최단거리가 가장 짧은 장소를 선택하여 새경로노드로 설정하고,
//그 장소의 종료를 found로 바꾼다.
//4. 최단경로가 not-found인 모든 장소들에 대해서, 아래 조건이 만족하는지 판단.
//if(장소의 '최단거리'>새경로노드의 '최단거리'+새경로노드의 그 장소까지 거리)이면,
//장소까지의 새로운 경로를 찾은 것이다. 그장소에 대해서
//4.1 '최단거리'=새경로노드의 '최단거리'+새경로노드에서 그 장소까지 거리
//4.2 직전노드=새경로노드
//5. 목적지 장소의 종료가 not-found라면 3단계로 복귀한다.

//A*는 가중최단거리가 추가된다.
//3단계에서 최단거리가 최소인 장소를 찾는 것이 아니라 가중최단거리가 최소인곳을 찾는다.
//가중최단거리는 모든 장소를 고려하는 대신에 특정 방향에 있는 장소를 먼저 고려하도록 하는 역할.
//1. 동일
//2. 동일
//3. 각 장소의 가중최단거리를 f(장소)로 계산해서 넣고, 최단경로가 not-found이면서
//가중최단거리가 가장 짧은 장소를 선택하여 새경로노드로 설정하고, 그 장소의 종료를 found로 바꾼다.
//4. 최단경로가 not-found인 모든 장소들에 대해서, 아래 조건이 만족하는지 판단한다.
//if(장소의 '최단거리'>새경로노드의 '최단거리'+새경로노드에서 그 장소까지 거리)
//이면 장소까지의 새로운 경로를 찾은 것이다. 그 장소에 대해서
//4.1 '최단거리'=새경로노드의 '최단거리'+새경로노드에서 그 장소
//4.2 직전노드=새경로노드
//5. 목적지 장소의 종료가 not-found이면 3단계로 복귀.

//탐색방향성에 정해진 것은 없다. 이것은 같은 최단경로를 가진 장소가 여러 개 있다면,
//목적지 쪽에 더 가까운 장소를 먼저 선택하게 하는 효과를 가진다.

//연결관계는 49x49이고, 인접하면 1.
//장소들 undiredted graph 이웃끼리 양방향

#include <stdio.h>
#include <limits.h>
#include <cstdlib>
#include <Windows.h>

#define TRUE 1
#define FLASE 0
#define DELAY_MILISEC 1000
//ASTAR를 comment-out하면 Dijkstra
#define ASTAR
#define GRID_LEN 7
#define SZ GRID_LEN*GRID_LEN //2차원 배열로 구현할 때 크기.

int graph[SZ][SZ]; //vertex관계도 49x49
int startLocSeq; //출발지 좌표
int destLocSeq; //도착지 좌표
//시각적 효과를 위해 출발지, 목적지 등 문자로 표시.
char map[GRID_LEN][GRID_LEN]; //지도7x7

struct astar_info {
	int found; //최단경로를 찾았는지.
	int shortestDist; //출발지부터의 최단 거리.
	int previousLoc; //최단거리일 때 그 전노드.
};

struct astar_info astar_table[SZ]; //모든 위치들에 대한 최단경로 관련 정보.
//지도를 초기화하기 위한 함수.
void init_map() {
	//지도상의 모든 위치에 문자 "."로 초기화.
	for (int i = 0;i < GRID_LEN;i++) {
		for (int j = 0;j < GRID_LEN;j++) {
			map[i][j] = '.'; 
		}
	}
	map[startLocSeq / GRID_LEN][startLocSeq%GRID_LEN] = '@'; //출발
	map[destLocSeq / GRID_LEN][destLocSeq%GRID_LEN] = '$'; //도착
}
//지도를 화면 상에 출력하기 위한 함수.
void display_map() {
	//2차원 지도를 1개 문자 단위로 화면에 출력한다.
	for (int i = 0;i < GRID_LEN;i++) {
		for (int j = 0;j < GRID_LEN;j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------\n");
}
//이웃하면 graph[i][j]=1,
int isNeighbor(int x, int y) {
	int x1 = x / GRID_LEN;
	int x2 = x % GRID_LEN;

	int y1 = y / GRID_LEN;
	int y2 = y % GRID_LEN;

	//y가 x의 위에 있는지 확인
	if (x2 == y2 && (y1 - 1) == x1) {
		return 1;
	}

	//y가 x의 아래에 있는지 확인
	if (x2 == y2 && (y1 + 1) == x1) {
		return 1;
	}

	//y가 x의 좌측에 있는지 확인
	if (x1 == y1 && (y2 - 1) == x2) {
		return 1;
	}

	//y가 x의 우측에 있는지 확인
	if (x1 == y1 && (y2 + 1) == x2) {
		return 1;
	}
	return 0;
}

//2차원 지도에 해당하는 그래프를 표현하는 배열변수 graph에
//vertex칸에 edge정보를 입력하기 위해
void init_graph() {
	int i, j;
	for (i = 0;i < SZ;i++) {
		for (j = 0;j < SZ;j++) {
			graph[i][j] = isNeighbor(i, j);
		}
	}
}

//위치는 1차원으로 구분하기 때문에.
//2차원에서 1차원으로 변환
//(0,0)->GRID_LEN*0+0=0;
int calcSeqNum(int x, int y) {
	return (GRID_LEN*x + y);
}

//astar_table은 출발지에서 다른 모든 위치들로 가는 최단경로에 관한 정보.
//astar_table초기화
void init_astar_table(void) {
	for (int i = 0;i < SZ;i++) { //모든 요소들에 대해서.
		//출발지 자신에 대한 것은 처리할 필요 없다.
		if (i == startLocSeq) {
			astar_table[i].found = TRUE;
			continue;
		}
		//초기화 과정이므로 false.
		astar_table[i].found = FALSE;
		//출발지의 이웃위치들에 대해서는 한칸 이동할 수 있다.
		//그래서 shortestDist=1로 설정.
		//직전 노드는 출발지.
		if (isNeighbor(startLocSeq, i) == TRUE) {
			astar_table[i].shortestDist = 1;
			astar_table[i].previousLoc = startLocSeq;
		}
		//인접하지 않은 위치들에 대해서는 
		//무한대와 직전노드 -1.
		else {
			astar_table[i].shortestDist = -999;
			astar_table[i].previousLoc = -1;
		}
	}
}

//두 장소 간의 거리를 계산하는 함수이다.
//a=(x1,y1)과 b=(x2,y2)의 거리를 계산한다.
int calcEuclideanDistance(int a, int b) {
	int x1 = a / GRID_LEN;
	int y1 = a % GRID_LEN;
	int x2 = b / GRID_LEN;
	int y2 = b % GRID_LEN;
	return ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

//astar_table에서 가장 짧은 최단경로를 갖는 장소들을 찾아 반환한다.
//가중치가 고려된 최단경로를 선정한다.
int findSmallestWeightedDist(void) {
	int smallestIdx = -1; //가장 짧은 거리를 가진 장소.
	int smallestDist = INT_MAX; //가장 짧은 거리
	//모든 장소들에 대해서 검사.
	for (int i = 0;i < SZ;i++) {
		//아직까지 최단경로가 발견되지 않은 좌표들에 대해서만 계산한다.
		if (astar_table[i].found == FALSE && astar_table[i].shortestDist > 0) {
#ifdef ASTAR
			//장소에 대한 가중최단거리를 계산한다.
			//여기서는 목적지와의 거리가 가까울수록 가중최단거리가 작아지기 때문에,
			//목적지 방향의 장소가 선정될 가능성이 높아진다.
			int weightedDist = astar_table[i].shortestDist + calcEuclideanDistance(destLocSeq, i) * 10;
#else
			int weightedDist = astar_table[i].shortestDist;
#endif
			if (weightedDist < smallestDist) {
				smallestIdx = i;
				smallestDist = weightedDist;
			}
		}
	}
	return smallestIdx;
}

int main() {
	startLocSeq = calcSeqNum(3, 3); //출발위치
	destLocSeq = calcSeqNum(GRID_LEN - 1, GRID_LEN - 1); //도착위치

	init_map();
	display_map();
	//시작하기 전에 2초간 잠시 멈추고, 지도를 보여준다.
	Sleep(2000);
	//그래프를 2차원 배열로 구성하고, 각종 정보들을 초기화.
	init_graph();
	init_astar_table();

	int loc;
	//모든 장소들의 최단경로가 결정되면 -1을 반환하므로 그때까지 반복.
	//그렇지 않은 경우 loc은 최단경로가 결정.
	while ((loc = findSmallestWeightedDist()) != -1) {
		//새로 최단경로를 찾은 위치에 대해서 update한다.
		//최단경로가 결정.
		astar_table[loc].found = TRUE;
		//결정된 곳의 위치를 X로 표시.
		map[loc / GRID_LEN][loc%GRID_LEN] = 'X';
		//진행을 보여주기위해 지우고 업데이트시킨다.
		system("cls"); //화면을 지운다.
		display_map();
		Sleep(DELAY_MILISEC); //잠시정지(너무 빨리 지워지는 것을 방지)

		if (loc == destLocSeq) //목적지에 도달했으면 정지
		{
			break;
		}
		//update astar_table
		for (int i = 0;i < SZ;i++) {
			//최단경로가 알려지지 않은 위치들에 대해서,
			//그리고 새로 발견된 경로와 연결되는 위치들에 대해서
			//더 빠르게 갈 수 있는 경로를 확인해 본다.
			if (astar_table[i].found == FALSE && graph[loc][i] == 1) {
				//새로 찾은 경로를 거쳐가는 것이 빠르거나
				//아직까지 경로가 알려져 있지 않은 경우에
				if (astar_table[loc].shortestDist + 1 < astar_table[i].shortestDist || astar_table[i].shortestDist < 0) {
					astar_table[i].shortestDist = astar_table[loc].shortestDist + 1;
					astar_table[i].previousLoc = loc;
				}
			}
		}
	}

}
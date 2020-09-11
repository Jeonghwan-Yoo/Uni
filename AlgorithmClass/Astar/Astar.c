//Astar �˰���
//Dijkstra �˰����� ����(������)
//�ִܰ�θ� ã�� ���� ������ ������ �� �ִ�.
//��, ���ɼ��� �� ���� ���� ���� Ž��.
//���ɼ��� �� ������ ���� �ȵǰ� ���ư��� ������� ������ Dijkstra�� ���������� �ִ�.
//Dijkstra�� ���� ��ġ�κ��� ��� ������ ������� �ִ� ��θ� Ž��(������ �׷�����)
//A*�� Ư�������� ���� �õ��ϰ�, Ÿ������� �׸���.

//Dijkstra
//1. �� ��ҿ� �ش��ϴ� ���� �ʱ�ȭ. ����� not-found, �ִܰŸ��� ���Ѵ�, �������� ����
//2. ��������� ���������� ����� ��ҵ鿡 ���ؼ��� �ִܰŸ��� �����ϰ�, ������忡 ������� �����Ѵ�.
//3. �ִܰ�ΰ� not-found�̸鼭 �ִܰŸ��� ���� ª�� ��Ҹ� �����Ͽ� ����γ��� �����ϰ�,
//�� ����� ���Ḧ found�� �ٲ۴�.
//4. �ִܰ�ΰ� not-found�� ��� ��ҵ鿡 ���ؼ�, �Ʒ� ������ �����ϴ��� �Ǵ�.
//if(����� '�ִܰŸ�'>����γ���� '�ִܰŸ�'+����γ���� �� ��ұ��� �Ÿ�)�̸�,
//��ұ����� ���ο� ��θ� ã�� ���̴�. ����ҿ� ���ؼ�
//4.1 '�ִܰŸ�'=����γ���� '�ִܰŸ�'+����γ�忡�� �� ��ұ��� �Ÿ�
//4.2 �������=����γ��
//5. ������ ����� ���ᰡ not-found��� 3�ܰ�� �����Ѵ�.

//A*�� �����ִܰŸ��� �߰��ȴ�.
//3�ܰ迡�� �ִܰŸ��� �ּ��� ��Ҹ� ã�� ���� �ƴ϶� �����ִܰŸ��� �ּ��ΰ��� ã�´�.
//�����ִܰŸ��� ��� ��Ҹ� ����ϴ� ��ſ� Ư�� ���⿡ �ִ� ��Ҹ� ���� ����ϵ��� �ϴ� ����.
//1. ����
//2. ����
//3. �� ����� �����ִܰŸ��� f(���)�� ����ؼ� �ְ�, �ִܰ�ΰ� not-found�̸鼭
//�����ִܰŸ��� ���� ª�� ��Ҹ� �����Ͽ� ����γ��� �����ϰ�, �� ����� ���Ḧ found�� �ٲ۴�.
//4. �ִܰ�ΰ� not-found�� ��� ��ҵ鿡 ���ؼ�, �Ʒ� ������ �����ϴ��� �Ǵ��Ѵ�.
//if(����� '�ִܰŸ�'>����γ���� '�ִܰŸ�'+����γ�忡�� �� ��ұ��� �Ÿ�)
//�̸� ��ұ����� ���ο� ��θ� ã�� ���̴�. �� ��ҿ� ���ؼ�
//4.1 '�ִܰŸ�'=����γ���� '�ִܰŸ�'+����γ�忡�� �� ���
//4.2 �������=����γ��
//5. ������ ����� ���ᰡ not-found�̸� 3�ܰ�� ����.

//Ž�����⼺�� ������ ���� ����. �̰��� ���� �ִܰ�θ� ���� ��Ұ� ���� �� �ִٸ�,
//������ �ʿ� �� ����� ��Ҹ� ���� �����ϰ� �ϴ� ȿ���� ������.

//�������� 49x49�̰�, �����ϸ� 1.
//��ҵ� undiredted graph �̿����� �����

#include <stdio.h>
#include <limits.h>
#include <cstdlib>
#include <Windows.h>

#define TRUE 1
#define FLASE 0
#define DELAY_MILISEC 1000
//ASTAR�� comment-out�ϸ� Dijkstra
#define ASTAR
#define GRID_LEN 7
#define SZ GRID_LEN*GRID_LEN //2���� �迭�� ������ �� ũ��.

int graph[SZ][SZ]; //vertex���赵 49x49
int startLocSeq; //����� ��ǥ
int destLocSeq; //������ ��ǥ
//�ð��� ȿ���� ���� �����, ������ �� ���ڷ� ǥ��.
char map[GRID_LEN][GRID_LEN]; //����7x7

struct astar_info {
	int found; //�ִܰ�θ� ã�Ҵ���.
	int shortestDist; //����������� �ִ� �Ÿ�.
	int previousLoc; //�ִܰŸ��� �� �� �����.
};

struct astar_info astar_table[SZ]; //��� ��ġ�鿡 ���� �ִܰ�� ���� ����.
//������ �ʱ�ȭ�ϱ� ���� �Լ�.
void init_map() {
	//�������� ��� ��ġ�� ���� "."�� �ʱ�ȭ.
	for (int i = 0;i < GRID_LEN;i++) {
		for (int j = 0;j < GRID_LEN;j++) {
			map[i][j] = '.'; 
		}
	}
	map[startLocSeq / GRID_LEN][startLocSeq%GRID_LEN] = '@'; //���
	map[destLocSeq / GRID_LEN][destLocSeq%GRID_LEN] = '$'; //����
}
//������ ȭ�� �� ����ϱ� ���� �Լ�.
void display_map() {
	//2���� ������ 1�� ���� ������ ȭ�鿡 ����Ѵ�.
	for (int i = 0;i < GRID_LEN;i++) {
		for (int j = 0;j < GRID_LEN;j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------\n");
}
//�̿��ϸ� graph[i][j]=1,
int isNeighbor(int x, int y) {
	int x1 = x / GRID_LEN;
	int x2 = x % GRID_LEN;

	int y1 = y / GRID_LEN;
	int y2 = y % GRID_LEN;

	//y�� x�� ���� �ִ��� Ȯ��
	if (x2 == y2 && (y1 - 1) == x1) {
		return 1;
	}

	//y�� x�� �Ʒ��� �ִ��� Ȯ��
	if (x2 == y2 && (y1 + 1) == x1) {
		return 1;
	}

	//y�� x�� ������ �ִ��� Ȯ��
	if (x1 == y1 && (y2 - 1) == x2) {
		return 1;
	}

	//y�� x�� ������ �ִ��� Ȯ��
	if (x1 == y1 && (y2 + 1) == x2) {
		return 1;
	}
	return 0;
}

//2���� ������ �ش��ϴ� �׷����� ǥ���ϴ� �迭���� graph��
//vertexĭ�� edge������ �Է��ϱ� ����
void init_graph() {
	int i, j;
	for (i = 0;i < SZ;i++) {
		for (j = 0;j < SZ;j++) {
			graph[i][j] = isNeighbor(i, j);
		}
	}
}

//��ġ�� 1�������� �����ϱ� ������.
//2�������� 1�������� ��ȯ
//(0,0)->GRID_LEN*0+0=0;
int calcSeqNum(int x, int y) {
	return (GRID_LEN*x + y);
}

//astar_table�� ��������� �ٸ� ��� ��ġ��� ���� �ִܰ�ο� ���� ����.
//astar_table�ʱ�ȭ
void init_astar_table(void) {
	for (int i = 0;i < SZ;i++) { //��� ��ҵ鿡 ���ؼ�.
		//����� �ڽſ� ���� ���� ó���� �ʿ� ����.
		if (i == startLocSeq) {
			astar_table[i].found = TRUE;
			continue;
		}
		//�ʱ�ȭ �����̹Ƿ� false.
		astar_table[i].found = FALSE;
		//������� �̿���ġ�鿡 ���ؼ��� ��ĭ �̵��� �� �ִ�.
		//�׷��� shortestDist=1�� ����.
		//���� ���� �����.
		if (isNeighbor(startLocSeq, i) == TRUE) {
			astar_table[i].shortestDist = 1;
			astar_table[i].previousLoc = startLocSeq;
		}
		//�������� ���� ��ġ�鿡 ���ؼ��� 
		//���Ѵ�� ������� -1.
		else {
			astar_table[i].shortestDist = -999;
			astar_table[i].previousLoc = -1;
		}
	}
}

//�� ��� ���� �Ÿ��� ����ϴ� �Լ��̴�.
//a=(x1,y1)�� b=(x2,y2)�� �Ÿ��� ����Ѵ�.
int calcEuclideanDistance(int a, int b) {
	int x1 = a / GRID_LEN;
	int y1 = a % GRID_LEN;
	int x2 = b / GRID_LEN;
	int y2 = b % GRID_LEN;
	return ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

//astar_table���� ���� ª�� �ִܰ�θ� ���� ��ҵ��� ã�� ��ȯ�Ѵ�.
//����ġ�� ����� �ִܰ�θ� �����Ѵ�.
int findSmallestWeightedDist(void) {
	int smallestIdx = -1; //���� ª�� �Ÿ��� ���� ���.
	int smallestDist = INT_MAX; //���� ª�� �Ÿ�
	//��� ��ҵ鿡 ���ؼ� �˻�.
	for (int i = 0;i < SZ;i++) {
		//�������� �ִܰ�ΰ� �߰ߵ��� ���� ��ǥ�鿡 ���ؼ��� ����Ѵ�.
		if (astar_table[i].found == FALSE && astar_table[i].shortestDist > 0) {
#ifdef ASTAR
			//��ҿ� ���� �����ִܰŸ��� ����Ѵ�.
			//���⼭�� ���������� �Ÿ��� �������� �����ִܰŸ��� �۾����� ������,
			//������ ������ ��Ұ� ������ ���ɼ��� ��������.
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
	startLocSeq = calcSeqNum(3, 3); //�����ġ
	destLocSeq = calcSeqNum(GRID_LEN - 1, GRID_LEN - 1); //������ġ

	init_map();
	display_map();
	//�����ϱ� ���� 2�ʰ� ��� ���߰�, ������ �����ش�.
	Sleep(2000);
	//�׷����� 2���� �迭�� �����ϰ�, ���� �������� �ʱ�ȭ.
	init_graph();
	init_astar_table();

	int loc;
	//��� ��ҵ��� �ִܰ�ΰ� �����Ǹ� -1�� ��ȯ�ϹǷ� �׶����� �ݺ�.
	//�׷��� ���� ��� loc�� �ִܰ�ΰ� ����.
	while ((loc = findSmallestWeightedDist()) != -1) {
		//���� �ִܰ�θ� ã�� ��ġ�� ���ؼ� update�Ѵ�.
		//�ִܰ�ΰ� ����.
		astar_table[loc].found = TRUE;
		//������ ���� ��ġ�� X�� ǥ��.
		map[loc / GRID_LEN][loc%GRID_LEN] = 'X';
		//������ �����ֱ����� ����� ������Ʈ��Ų��.
		system("cls"); //ȭ���� �����.
		display_map();
		Sleep(DELAY_MILISEC); //�������(�ʹ� ���� �������� ���� ����)

		if (loc == destLocSeq) //�������� ���������� ����
		{
			break;
		}
		//update astar_table
		for (int i = 0;i < SZ;i++) {
			//�ִܰ�ΰ� �˷����� ���� ��ġ�鿡 ���ؼ�,
			//�׸��� ���� �߰ߵ� ��ο� ����Ǵ� ��ġ�鿡 ���ؼ�
			//�� ������ �� �� �ִ� ��θ� Ȯ���� ����.
			if (astar_table[i].found == FALSE && graph[loc][i] == 1) {
				//���� ã�� ��θ� ���İ��� ���� �����ų�
				//�������� ��ΰ� �˷��� ���� ���� ��쿡
				if (astar_table[loc].shortestDist + 1 < astar_table[i].shortestDist || astar_table[i].shortestDist < 0) {
					astar_table[i].shortestDist = astar_table[loc].shortestDist + 1;
					astar_table[i].previousLoc = loc;
				}
			}
		}
	}

}
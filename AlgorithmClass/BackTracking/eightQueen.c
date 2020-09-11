//backtracking
//queen의 이동범위는 대각선이나 같은선
//서로의 queen이 공격할 수 없게 각 줄에 하나씩 배열.
//하다가 안되면 포기하고 다른방법.

//init->isOK(위,아래,대각 확인)->열먼저 되는지 하나씩 확인->checkNext(행마다체크)

#include <stdio.h>
#include <string.h>
#include <math.h>

#define SZ 8

//체스판
int chess_board[SZ][SZ];

//발견한 솔루션의 개수.
int solutionCnt = 0;

//체스판을 0으로 초기화 한다.
//1은 Queen이 놓일때
void initBoard() {
	memset(chess_board, 0, sizeof(int)*SZ*SZ);

#if 0
	int i, j;
	for (i = 0;i < SZ;i++) {
		for (j = 0;j < SZ;j++) {
			chess_board[i][j] = 0;
		}
	}
#endif
}

//좌표(_r,_c)에 queen을 놓을 수 있냐?
//반환값 1:좌표(_r,_c)에 놓을 수 있다.
//      0:안돼
int isOK(int _r, int _c) {
	int i, j;
	//위쪽 방향을 검사
	for (i = 0;i < _r;i++) {
		if (chess_board[i][_c] != 0) { //벌써 queen이 있다.
			//안돼!
			return 0;
		}
	}
	//왼쪽 방향을 검사
	for (i = 0;i < _c;i++) {
		//벌써 queen이 있는지?
		if (chess_board[_r][i] != 0) {
			return 0; //안돼!
		}
	}
	//위쪽 대각선 방향을 검사
	for (i = 0;i < _r;i++) {
		for (j = 0;j < SZ;j++) { //위 오른쪽 끝까지
			//대각선 상에 있고, 거기에 queen이 놓여있느지 확인
			if ((abs(i - _r) == abs(j - _c)) && chess_board[i][j] != 0) {
				return 0;
			}
		}
	}
	//다 통과했으면 돼! 안전해~
	return 1;
}

//행 _r을 0으로 초기화한다.
void clearRow(int _r) {
	memset(&chess_board[_r][0], 0, sizeof(int)*SZ);
#if 0
	int i;
	for (i = 0;i < SZ;i++) {
		chess_board[_r][i] = 0;
	}
#endif
}

//queen이 놓인 위치들을 출력한다.
void printSolution(void) {
	solutionCnt++;
	printf("----------Solution %d---------\n", solutionCnt);
	for (int i = 0;i < SZ;i++) {
		for (int j = 0;j < SZ;j++) {
			printf("%d ", chess_board[i][j]);
		}
		printf("\n");
	}
}

//행 _r에 queen을 놓을 수 있는 위치를 찾는다.
void checkNext(int _r) {
	int i;
	//행 _r의 모든 열에 대해서
	for (i = 0;i < SZ;i++) {
		//clearRow(_r); 이전에 했던거를 지움.
		clearRow(_r);
		//좌표(_r,i)에 놓을 수 있는지 검사
		if (isOK(_r, i) == 1) {
			//좌표(_r,i)에 queen을 놓고,
			chess_board[_r][i] = 1;

			//마지막 행을 처리했는지 체크
			if (_r == (SZ - 1)) {
				printSolution();
			}
			//안됐으면 다음 줄로
			else {
				checkNext(_r + 1);
			}
		}
	}
}
int main(void) {
	int c; //열을 나타내는 변수

	initBoard();

	for (c = 0;c < SZ;c++) {
		clearRow(0);
		//좌표(0,c)에 놓을 수 있는지 검사.
		if (isOK(0, c) == 1) {
			chess_board[0][c] = 1;
			checkNext(1);
		}
	}
	return 0;
}
//backtracking
//가로, 세로, region을 고려한다.
//그 뒤에있는 숫자도 비교해야된다.

//원본 복사본을 만든다.
//isOk(value도 포함)->위아래, 왼쪽오른쪽, 리젼을 확인한다.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ 9

void solveSudoku(int _r, int _c);

int sudoku[SZ][SZ] = {
	4,0,7,5,0,0,0,0,8,
	0,5,0,7,0,0,4,0,9,
	0,0,6,0,0,4,0,7,0,
	9,0,0,6,0,0,2,4,3,
	0,4,0,9,0,3,0,8,0,
	7,3,1,0,0,2,0,0,5,
	0,2,0,8,0,0,7,0,0,
	3,0,9,0,0,6,0,5,0,
	5,0,0,0,0,7,3,0,4
};

//원본.
int readOnlySudoku[SZ][SZ];

//해답의 개수.
int solutionCnt = 0;

//readOnlySudoku배열에 주어진 sudoku를 저장한다.
void initReadOnlySudoku(void) {
	memcpy(readOnlySudoku, sudoku, sizeof(int)*SZ*SZ);
}

//좌표(_r,_c)에 값 _value가 들어갈 수 있는지를 확인한다.
//반환값 1:들어갈 수 있다.
//      0:안돼.
int isOK(int _r, int _c, int _value) {
	//상하방향 확인(_c는 일정)
	for (int i = 0;i < SZ;i++) {
		//이미 _value값을 가진 곳이 있는지 확인, 자기자신이 아닌지 확인
		if ((sudoku[i][_c] == _value) && i != _r) {
			return 0;
		}
	}

	//좌우방향 확인
	for (int i = 0;i < SZ;i++) {
		if ((sudoku[_r][i] == _value) && i != _c) {
			return 0;
		}
	}

	//region 확인
	int region_row = _r / 3;
	int region_col = _c / 3;

	for (int i = region_row * 3;i <= region_row * 3 + 2;i++) {
		for (int j = region_col * 3;j <= region_col * 3 + 2;j++) {
			if ((sudoku[i][j] == _value) && (i != _r) && (j != _c)) {
				return 0;
			}
		}
	}

	//(_r,_c)에 _value값을 넣어도 좋다.
	return 1;
}

void printSolution() {
	solutionCnt++;

	printf("---------- Solution #%d ----------\n", solutionCnt);

	for (int i = 0;i < SZ;i++) {
		for (int j = 0;j < SZ;j++) {
			printf("%d ", sudoku[i][j]);
			if (j % 3 == 2) {
				printf(" ");
			}
		}
		printf("\n");
		if (i % 3 == 2) {
			printf("\n");
		}
	}
}

//좌표(_r,_c)다음에 방문하여 숫자를 결정할 위치를 판단.
void checkNext(int _r, int _c) {
	if (_r == (SZ - 1) && _c == (SZ - 1)) {
		printSolution();
	}
	_c++;
	if (_c == SZ) {
		_c = 0;
		_r++;
	}
	//r과c는 +1된 상태
	solveSudoku(_r, _c);
}

//좌표(_r,_c) 위치에 들어갈 숫자를 결정한다.
void solveSudoku(int _r, int _c) {
	//이미 수도쿠 문제에서 (_r,_c) 위치
	//숫자가 주어졌는지 검산.
	if (sudoku[_r][_c] > 0) {
		//다음 칸으로 이동해서 처리
		checkNext(_r, _c);
	}
	//숫자가 정해지지 않은 경우,
	else {
		//좌표(_r,_c)에 1부터 9까지 숫자를 하나씩 대입해서 체크해본다.
		for (int i = 1;i <= 9;i++) {
			memcpy(&sudoku[_r][_c], &readOnlySudoku[_r][_c],
				//전체크기에서 앞단의크기를 뺀만큼을=뒤쪽을 초기화..
				sizeof(int)*SZ*SZ - sizeof(int)*(_r*SZ + _c));
			if (isOK(_r, _c, i) == 1) {
				sudoku[_r][_c] = i;
				//다음 칸으로 이동해서 처리.
				checkNext(_r, _c);
			}
		}
	}
}

int main(void) {
	initReadOnlySudoku();

	solveSudoku(0, 0);

	return 0;
}
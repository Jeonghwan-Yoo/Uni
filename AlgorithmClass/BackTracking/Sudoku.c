//backtracking
//����, ����, region�� ����Ѵ�.
//�� �ڿ��ִ� ���ڵ� ���ؾߵȴ�.

//���� ���纻�� �����.
//isOk(value�� ����)->���Ʒ�, ���ʿ�����, ������ Ȯ���Ѵ�.


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

//����.
int readOnlySudoku[SZ][SZ];

//�ش��� ����.
int solutionCnt = 0;

//readOnlySudoku�迭�� �־��� sudoku�� �����Ѵ�.
void initReadOnlySudoku(void) {
	memcpy(readOnlySudoku, sudoku, sizeof(int)*SZ*SZ);
}

//��ǥ(_r,_c)�� �� _value�� �� �� �ִ����� Ȯ���Ѵ�.
//��ȯ�� 1:�� �� �ִ�.
//      0:�ȵ�.
int isOK(int _r, int _c, int _value) {
	//���Ϲ��� Ȯ��(_c�� ����)
	for (int i = 0;i < SZ;i++) {
		//�̹� _value���� ���� ���� �ִ��� Ȯ��, �ڱ��ڽ��� �ƴ��� Ȯ��
		if ((sudoku[i][_c] == _value) && i != _r) {
			return 0;
		}
	}

	//�¿���� Ȯ��
	for (int i = 0;i < SZ;i++) {
		if ((sudoku[_r][i] == _value) && i != _c) {
			return 0;
		}
	}

	//region Ȯ��
	int region_row = _r / 3;
	int region_col = _c / 3;

	for (int i = region_row * 3;i <= region_row * 3 + 2;i++) {
		for (int j = region_col * 3;j <= region_col * 3 + 2;j++) {
			if ((sudoku[i][j] == _value) && (i != _r) && (j != _c)) {
				return 0;
			}
		}
	}

	//(_r,_c)�� _value���� �־ ����.
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

//��ǥ(_r,_c)������ �湮�Ͽ� ���ڸ� ������ ��ġ�� �Ǵ�.
void checkNext(int _r, int _c) {
	if (_r == (SZ - 1) && _c == (SZ - 1)) {
		printSolution();
	}
	_c++;
	if (_c == SZ) {
		_c = 0;
		_r++;
	}
	//r��c�� +1�� ����
	solveSudoku(_r, _c);
}

//��ǥ(_r,_c) ��ġ�� �� ���ڸ� �����Ѵ�.
void solveSudoku(int _r, int _c) {
	//�̹� ������ �������� (_r,_c) ��ġ
	//���ڰ� �־������� �˻�.
	if (sudoku[_r][_c] > 0) {
		//���� ĭ���� �̵��ؼ� ó��
		checkNext(_r, _c);
	}
	//���ڰ� �������� ���� ���,
	else {
		//��ǥ(_r,_c)�� 1���� 9���� ���ڸ� �ϳ��� �����ؼ� üũ�غ���.
		for (int i = 1;i <= 9;i++) {
			memcpy(&sudoku[_r][_c], &readOnlySudoku[_r][_c],
				//��üũ�⿡�� �մ���ũ�⸦ ����ŭ��=������ �ʱ�ȭ..
				sizeof(int)*SZ*SZ - sizeof(int)*(_r*SZ + _c));
			if (isOK(_r, _c, i) == 1) {
				sudoku[_r][_c] = i;
				//���� ĭ���� �̵��ؼ� ó��.
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
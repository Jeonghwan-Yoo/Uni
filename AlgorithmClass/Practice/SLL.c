#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ 9

#pragma warning(disable:4996)

int count = 0;

int sudoku[SZ][SZ] = {
	4,0,7,5,0,0,0,0,0,
	0,5,0,0,0,0,4,0,9,
	0,0,0,0,0,0,0,7,0,
	0,0,0,6,0,0,2,4,3,
	0,4,0,9,0,3,0,8,0,
	0,3,1,0,0,2,0,0,5,
	0,2,0,8,0,0,7,0,0,
	3,0,9,0,0,6,0,5,0,
	0,0,0,0,0,7,3,0,0
};

int origin[SZ][SZ];

original() {
	memcpy(origin, sudoku, sizeof(int)*SZ*SZ);
}

solveSudoku(int _r, int _c);


int isOk(int _r, int _c, int v) {
	for (int i = 0;i < SZ;i++) {
		if (sudoku[i][_c] == v && i != _r) {
			return 0;
		}
	}
	for (int i = 0;i < SZ;i++) {
		if (sudoku[_r][i] == v && i != _c) {
			return 0;
		}
	}
	int region_r = _r / 3;
	int region_c = _c / 3;
	for (int i = region_r*3;i < region_r*3+3;i++) {
		for (int j = region_c * 3;j < region_c * 3 + 3;j++) {
			if(sudoku[i][j]==v&&i!=_r&&j!=_c){
				return 0;
			}
		}
	}
	return 1;
}

display() {
	count++;
	printf("\n----------%d-----------\n", count);
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

checkNext(int _r, int _c) {
	if (_r == SZ - 1 && _c == SZ - 1) {
		display();
	}
	_c++;
	if (_c == SZ) {
		_c = 0;
		_r++;
	}
	solveSudoku(_r, _c);
}

solveSudoku(int _r, int _c) {
	if (sudoku[_r][_c] > 0) {
		checkNext(_r, _c);
	}
	else {
		for (int i = 1;i < SZ + 1;i++) {
			memcpy(&sudoku[_r][_c], &origin[_r][_c], sizeof(int)*SZ*SZ - sizeof(int)*(_r*SZ + _c));
			if (isOk(_r, _c, i) == 1) {
				sudoku[_r][_c] = i;
				checkNext(_r, _c);
			}
		}
	}
}
int main() {
	original();
	solveSudoku(0, 0);
}
//Edit Distance(sometimes for DNA)
//Given String s1 and s2, need converting s1 to s2.
//Let s1 is a and s2 is aa, then we need to INSERT to convert s1 to s2. Also, distance is 1.
//Let s1 is aa and s2 is a, then we need to DELETE to convert s1 to s2. Also, distance is 1.
//Let s1 is ab and s2 is ac, then we need to SUBSTITUDE to convert s1 to s2. Also, distance is 1.
//Let s1 is aa and s2 is aa, then we need to COPY to convert s1 to s2. Also, distance is 0.
//But, we can convert s1 to s2 by other method. Thus, the smallest distance out of lots methods is Edit Distance.
//Do dynamic programming. It's like filling with data in a table. And last data would be the answer.
//We need to make a stack for following back for the processes.
//the size should be (col-1)+(row-1).
//plus boundary check, (0,0) check.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum OPERATION {
	COPY = 0, INSERT, DELETE, SUBSTITUDE, NON //0,1,2,3,4.
};
//s1--->s2
//const char* s1 = "strong";
//const char* s2 = "storm";
const char* s1 = "butterfly";
const char* s2 = "beautiful";
//create 2d array dynamically
//returns the allocated space address
int** createTable(int num_row, int num_col) { //2d array=>**
	int **rows = (int **)malloc(sizeof(int *)*num_row);
	for (int i = 0;i < num_row;i++) {
		rows[i] = (int *)malloc(sizeof(int)*num_col);
	}
	return rows;
}
//returns the minimum among _a,_b,_c
int findMinimum(int _a, int _b, int _c) {

	//return (_a < _b) ? ((_a < _c)? _a: _c ): ((_b<_c)?_b:_c); //readability is terrible.

	if (_a < _b) {
		if (_a < _c) {
			return _a;
		}
		else { //_a>_c
			return _c;
		}
	}
	else { //_a>_b
		if (_b < _c) {
			return _b;
		}
		else { //_b>_c
			return _c;
		}
	}
}

void populateTable(int** _table, const char* _s1, const char* _s2, int _num_row, int _num_col) {
	for (int i = 0;i < _num_col;i++) {
		_table[0][i] = i;
	}
	for (int i = 0;i < _num_row;i++) {
		_table[i][0] = i;
	}
	for (int r = 1;r < _num_row;r++) {
		for (int c = 1;c < _num_col;c++) {
			if (_s1[r - 1] == _s2[c - 1]) { //if last characters are same, 
				_table[r][c] = _table[r - 1][c - 1]; //diagonise number is the number.
			}
			else { //if last characters are different,
				_table[r][c] = findMinimum(_table[r - 1][c], _table[r][c - 1], _table[r - 1][c - 1]) + 1; //the smallest one add one is answer.
			}
		}
	}
}

enum OPERATION* stack = 0;
int stack_top = -1;

void createStack(int _num_row, int _num_col) {
	stack = (enum OPERATION *)malloc(sizeof(enum OPERATION)*(_num_row + _num_col - 2));
	stack_top = -1;
}

void push(enum OPERATION _operation) {
	stack_top++;
	stack[stack_top] = _operation;
}

enum OPERATION pop() {
	if (stack_top == -1) { //stack is empty
		return NON; //-999 is a special value meaing it's empty.
	}
	enum OPERATION result = stack[stack_top];
	stack_top -= 1;
	return result;
}

enum OPERATION findSmallestNeighbor(int** _table, int _r, int _c) {
	int up;
	int left;
	int diag;

	if (_r - 1 >= 0) { //something is upside
		up = _table[_r - 1][_c];
	}
	else {
		up = INT_MAX;
	}
	if (_c - 1 >= 0) { //something is leftside
		left = _table[_r][_c - 1];
	}
	else {
		left = INT_MAX;
	}
	if (_r - 1 >= 0 && _c - 1 >= 0) { //something is diagonise side
		diag = _table[_r - 1][_c - 1];
	}
	else {
		diag = INT_MAX;
	}
	//up is the smallest neighbor
	if (up <= left && up <= diag) {
		return DELETE;
	}
	if (left <= up && left <= diag) {
		return INSERT;
	}
	if (diag <= up && diag <= left) {
		if (_table[_r][_c] == diag) {
			return COPY;
		}
		else {
			return SUBSTITUDE;
		}
	}
}

void showOperationSequence(int** _table, int _num_row, int _num_col) {
	createStack(_num_row, _num_col);
	int cur_r = _num_row - 1;
	int cur_c = _num_col - 1;

	while (1) {
		if (cur_r == 0 && cur_c == 0) {
			break;
		}
		//find the smallest neighbor

		enum OPERATION result = findSmallestNeighbor(_table, cur_r, cur_c);
		switch (result) {
		case COPY:
			push(COPY);
			cur_r -= 1;
			cur_c -= 1;
			break;
		case DELETE:
			push(DELETE);
			cur_r -= 1;
			break;
		case INSERT:
			push(INSERT);
			cur_c -= 1;
			break;
		case SUBSTITUDE:
			push(SUBSTITUDE);
			cur_r -= 1;
			cur_c -= 1;
			break;
		}
		//push operation

		//update cur_r,cur_c
	}
	//pop&print until the stack becomes empty
	while (1) {
		int res = pop();
		if (res == NON) {
			break;
		}
		printf("operation %d\n", res);
	}
	return;
}
int main() {
	//this is for 2d array
	int num_row = strlen(s1) + 1; //including null
	int num_col = strlen(s2) + 1; //including cull

	int** table = createTable(num_row, num_col);

	populateTable(table, s1, s2, num_row, num_col);

	printf("Edit distance between %s and %s is %d\n", s1, s2, table[num_row - 1][num_col - 1]);
	//show what operation sequence changes s1 to s2.
	showOperationSequence(table, num_row, num_col);

	return 0;
}
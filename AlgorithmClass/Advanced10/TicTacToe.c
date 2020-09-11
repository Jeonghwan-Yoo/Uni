//Tic-tac-toe game
//originally time complexity=O(n) -> O(1)(regardless of the size of table)
//given 3x3, total=3^9
//this is 3-unit, we should convert 3-unit to decimal.
//at once, we have to calculate all the situation.=>O(1) table!!!!!
//hash=>O(1).
#include <stdio.h>

#define BD_SZ 3
int board[BD_SZ][BD_SZ];
int cnt = 0;

//function showing board.
void showBoard() {
	printf("-----------%d----------\n", cnt++);
	for (int i = 0;i < BD_SZ;i++) {
		for (int j = 0;j < BD_SZ;j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}
//filling data in (r,c) which is 0, 1 or 2.
void fillBoard(int r, int c) {
	for (int v = 0;v < 3;v++) {
		board[r][c] = v;

		if (r == BD_SZ - 1 && c == BD_SZ - 1) {
			showBoard();
			continue; //0 -> 1 -> 2.
		}

		//next location.
		int new_r = r;
		int new_c = c;

		if (new_c == BD_SZ - 1) {
			new_r += 1;
			new_c = 0;
		}
		else {
			new_c += 1;
		}
		fillBoard(new_r, new_c); //recursive function.
	}
}

//function calculating 3unit by decimal in the board
int calcDecNumber() {
	int sum = 0;
	for (int i = 0;i < BD_SZ;i++) {
		for (int j = 0;j < BD_SZ;j++) {
			sum = sum * 3 + board[i][j];
		}
	}
	return sum;
}

int main() {
	fillBoard(0, 0);
	showBoard();

	return 0;
}

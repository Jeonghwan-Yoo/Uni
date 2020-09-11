//backtracking
//queen�� �̵������� �밢���̳� ������
//������ queen�� ������ �� ���� �� �ٿ� �ϳ��� �迭.
//�ϴٰ� �ȵǸ� �����ϰ� �ٸ����.

//init->isOK(��,�Ʒ�,�밢 Ȯ��)->������ �Ǵ��� �ϳ��� Ȯ��->checkNext(�ึ��üũ)

#include <stdio.h>
#include <string.h>
#include <math.h>

#define SZ 8

//ü����
int chess_board[SZ][SZ];

//�߰��� �ַ���� ����.
int solutionCnt = 0;

//ü������ 0���� �ʱ�ȭ �Ѵ�.
//1�� Queen�� ���϶�
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

//��ǥ(_r,_c)�� queen�� ���� �� �ֳ�?
//��ȯ�� 1:��ǥ(_r,_c)�� ���� �� �ִ�.
//      0:�ȵ�
int isOK(int _r, int _c) {
	int i, j;
	//���� ������ �˻�
	for (i = 0;i < _r;i++) {
		if (chess_board[i][_c] != 0) { //���� queen�� �ִ�.
			//�ȵ�!
			return 0;
		}
	}
	//���� ������ �˻�
	for (i = 0;i < _c;i++) {
		//���� queen�� �ִ���?
		if (chess_board[_r][i] != 0) {
			return 0; //�ȵ�!
		}
	}
	//���� �밢�� ������ �˻�
	for (i = 0;i < _r;i++) {
		for (j = 0;j < SZ;j++) { //�� ������ ������
			//�밢�� �� �ְ�, �ű⿡ queen�� �����ִ��� Ȯ��
			if ((abs(i - _r) == abs(j - _c)) && chess_board[i][j] != 0) {
				return 0;
			}
		}
	}
	//�� ��������� ��! ������~
	return 1;
}

//�� _r�� 0���� �ʱ�ȭ�Ѵ�.
void clearRow(int _r) {
	memset(&chess_board[_r][0], 0, sizeof(int)*SZ);
#if 0
	int i;
	for (i = 0;i < SZ;i++) {
		chess_board[_r][i] = 0;
	}
#endif
}

//queen�� ���� ��ġ���� ����Ѵ�.
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

//�� _r�� queen�� ���� �� �ִ� ��ġ�� ã�´�.
void checkNext(int _r) {
	int i;
	//�� _r�� ��� ���� ���ؼ�
	for (i = 0;i < SZ;i++) {
		//clearRow(_r); ������ �ߴ��Ÿ� ����.
		clearRow(_r);
		//��ǥ(_r,i)�� ���� �� �ִ��� �˻�
		if (isOK(_r, i) == 1) {
			//��ǥ(_r,i)�� queen�� ����,
			chess_board[_r][i] = 1;

			//������ ���� ó���ߴ��� üũ
			if (_r == (SZ - 1)) {
				printSolution();
			}
			//�ȵ����� ���� �ٷ�
			else {
				checkNext(_r + 1);
			}
		}
	}
}
int main(void) {
	int c; //���� ��Ÿ���� ����

	initBoard();

	for (c = 0;c < SZ;c++) {
		clearRow(0);
		//��ǥ(0,c)�� ���� �� �ִ��� �˻�.
		if (isOK(0, c) == 1) {
			chess_board[0][c] = 1;
			checkNext(1);
		}
	}
	return 0;
}
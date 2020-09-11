//117에서 사용된 3차원 배열 포인터 변수 pjumsu를 사용하여 국어, 영어, 수학의 총점을 계산하고 출력하는 함수를 작성하세요.
#include <stdio.h>

void calc(int(*pjumsu)[100][3], int* ptotal);

void main(void) {
	int jumsu[10][100][3];
	int total[3] = { 0, };

	calc(jumsu, total);

	printf("모든 반의 국어 점수의 총점 : %d\n", total[0]);
	printf("모든 반의 영어 점수의 총점 : %d\n", total[1]);
	printf("모든 반의 수학 점수의 총점 : %d\n", total[2]);
}

void calc(int(*pjumsu)[100][3], int* ptotal) {
	int i, j;
	for (i = 0;i < 10;i++) {
		for (j = 0;j < 100;j++) {
			pjumsu[i][j][0] = 92; //국어점수
			pjumsu[i][j][1] = 90; //영어점수
			pjumsu[i][j][2] = 95; //수학점수
		}
	}
	for (i = 0;i < 10;i++) {
		for (j = 0;j < 100;j++) {
			ptotal[0] += pjumsu[i][j][0];
			ptotal[1] += pjumsu[i][j][1];
			ptotal[2] += pjumsu[i][j][2];
		}
	}
}
//3차원 배열을 함수에 전달하기 위해서는
//void func(int (*x)[학생수][과목수]) or void func(int x[반수][학생수][과목수])
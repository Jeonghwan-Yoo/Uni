//10개 반에 대한 학생 100명의 국어, 영어, 수학 점수를 저장할 수 있는 변수를 생성하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int i, j;
	int jumsu[10][100][3];
	int total[3] = { 0, };
	
	for (i = 0;i < 10;i++) { //10개 반
		for (j = 0;j < 100;j++) { //100명
			jumsu[i][j][0] = 92; //국어 점수
			jumsu[i][j][1] = 90; //영어 점수
			jumsu[i][j][2] = 95; //수학 점수
		}
	}
	for (i = 0;i < 10;i++) {
		for (j = 0;j < 100;j++) {
			total[0] += jumsu[i][j][0]; //국어 총점
			total[1] += jumsu[i][j][1]; //영어 총점
			total[2] += jumsu[i][j][2]; //수학 총점
		}
	}
	printf("모든 반의 국어 점수의 총점 : %d\n", total[0]);
	printf("모든 반의 영어 점수의 총점 : %d\n", total[1]);
	printf("모든 반의 수학 점수의 총점 : %d\n", total[2]);
}
//학생 100명의 국어, 영어, 수학 점수를 저장할 수 있는 변수를 생성하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int i;
	int jumsu[100][3];
	int total[3] = { 0, };

	for (i = 0;i < 100;i++) {
		jumsu[i][0] = 92; //국어 점수
		jumsu[i][1] = 90; //영어 점수
		jumsu[i][2] = 95; //수학 점수
	}

	for (i = 0;i < 100;i++) {
		total[0] += jumsu[i][0]; //국어 총점
		total[1] += jumsu[i][1]; //영어 총점
		total[2] += jumsu[i][2]; //수학 총점
	}

	printf("국어 점수의 총점 : %d\n", total[0]);
	printf("영어 점수의 총점 : %d\n", total[1]);
	printf("수학 점수의 총점 : %d\n", total[2]);
}
//int x[3]={10,20,}; 10,20,0
//int x[2][2]={1,2,3,4}; {1,2},{3,4}
//113번의 2차원 배열 변수 jumsu를 대신해서 사용할 수 있는 2차원 배열의 포인터를 사용하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int i;
	int jumsu[100][3];
	int total[3] = { 0, };
	int(*pjumsu)[3]; //2차원이라는 것을 쉽게 알게하려고.

	pjumsu = jumsu;

	for (i = 0;i < 100;i++) {
		pjumsu[i][0] = 92; //국어 점수
		pjumsu[i][1] = 90; //영어 점수
		pjumsu[i][2] = 95; //수학 점수
	}

	for (i = 0;i < 100;i++) {
		total[0] += pjumsu[i][0]; //국어 점수
		total[1] += pjumsu[i][1]; //영어 점수
		total[2] += pjumsu[i][2]; //수학 점수
	}

	printf("국어 점수의 총점 : %d\n", total[0]);
	printf("영어 점수의 총점 : %d\n", total[1]);
	printf("수학 점수의 총점 : %d\n", total[2]);
}
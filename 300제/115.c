//114에서 사용된 2차원 배열 포인터 변수 pjumsu를 사용하여 국어, 영어, 수학의 총점을 계산하고 출력하는 함수를 작성하세요.
#include <stdio.h>

void calc(int(*pjumsu)[3], int* ptotal);

void main(void) {
	int jumsu[100][3];
	int total[3] = { 0, };
	int(*pjumsu)[3];

	pjumsu = jumsu;

	calc(pjumsu, total);

	printf("국어 점수의 총점 : %d\n", total[0]);
	printf("영어 점수의 총점 : %d\n", total[1]);
	printf("수학 점수의 총점 : %d\n", total[2]);
}

void calc(int(*pjumsu)[3], int* ptotal) {
	int i;

	for (i = 0;i < 100;i++) {
		pjumsu[i][0] = 92; //국어 점수
		pjumsu[i][1] = 90; //영어 점수
		pjumsu[i][2] = 95; //수학 점수
	}

	for (i = 0;i < 100;i++) {
		ptotal[0] += pjumsu[i][0]; //국어 점수
		ptotal[1] += pjumsu[i][1]; //영어 점수
		ptotal[2] += pjumsu[i][2]; //수학 점수
	}
}
//2차원 배열을 함수에 전달하기 위해서는
//void func(int(*x)[과목수]) or void func(int x[학생수][과목수])
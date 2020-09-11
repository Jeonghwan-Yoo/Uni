//116을 3차원 배열 변수 jumsu를 대신해서 사용할 수 있는 3차원 배열의 포인터를 사용하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int i, j;
	int jumsu[10][100][3];
	int total[3] = { 0, };
	int(*pjumsu)[100][3];

	pjumsu = jumsu;

	for (i = 0;i < 10;i++) { //10개 반
		for (j = 0;j < 100;j++) { //100명
			pjumsu[i][j][0] = 92; //국어 점수
			pjumsu[i][j][1] = 90; //영어 점수
			pjumsu[i][j][2] = 95; //수학 점수
		}
	}
	for (i = 0;i < 10;i++) {
		for (j = 0;j < 100;j++) {
			total[0] += pjumsu[i][j][0];
			total[1] += pjumsu[i][j][1];
			total[2] += pjumsu[i][j][2];
		}
	}

	printf("모든 반의 국어 점수의 총점 : %d\n", total[0]);
	printf("모든 반의 영어 점수의 총점 : %d\n", total[1]);
	printf("모든 반의 수힉 점수의 총점 : %d\n", total[2]);
}
//포인터를 초기화하지 않으면 다른 메모리 영역에 존재하는 값을 바꾸게 될 지도 모릅니다.
//배열 대신에 포인터를 사용할 때는 포인터를 꼭 초기화해야 한다는 사실을 반드시 기억해야 할 것입니다.
//초기화 작업은 포인터에 다른 변수를 할당하거나 동적으로 메모리를 할당함으로써 가능해집니다.
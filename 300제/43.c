//국어, 영어, 수학의 점수를 저장할 구조체 변수를 정의하고, 총합을 구하는 성적 계산 프로그램을 작성하세요.
#include <stdio.h>

struct tagSungJuk { //하나의 틀을 만드는 것.
	int kor;
	int eng;
	int math;
};

main() {
	struct tagSungJuk SJ; //그 틀을 가진 변수선언.

	SJ.kor = 100;
	SJ.eng = 95;
	SJ.math = 99;

	printf("총합 = %d", SJ.kor + SJ.eng + SJ.math);
}
//배열은 동일한 데이터형에 대하여 여러 개를 정의하는 것이고, 구조체는 서로 다른 데이터형을 하나의 묶음으로 처리.
//클래스와 비슷한 개념.
//struct tagSungJuk SJ[100];처럼 구조체 배열 변수를 정의할 수도 있다.
//일요일은 0, 월요일은 1, 화요일은 2, 수요일은 3, 목요일은 4, 금요일은 5, 토요일은 6을 출력하는 프로그램을
//열거형을 사용하여 작성하세요.
#include <stdio.h>

enum {
	Sun=0,Mon=5,Tue,Wed,Thr=10,Fri,Sat
};

main() {
	printf("%d ", Sun); //0
	printf("%d ", Mon); //5
	printf("%d ", Tue); //6
	printf("%d ", Wed); //7
	printf("%d ", Thr); //10
	printf("%d ", Fri); //11
	printf("%d ", Sat); //12
}

//상수를 나열하는 것과 같은 효과. #define을 열거하는 거 대신.
//항상 이전 상수의 값보다 1씩 증가.
//중간 중간에 default값을 지정할 수 있다. Mon=5, Thr=10
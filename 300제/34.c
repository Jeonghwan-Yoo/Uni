//i값에 따라 분기되는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	int i = 5;

	switch (i) {
	case 1:
		printf("i는 1입니다.");
		break;
	case 2:
		printf("i는 2입니다.");
		break;
	default:
		printf("i는 %d입니다.", i);
		break;
	}
	/*
	if (i == 1) {
		printf("i는 1입니다.");
	}
	else if (i == 2) {
		printf("i는 2입니다.");
	}
	else {
		printf("i는 %d입니다.", i);
	}
	*/
}
//조건 선택문은 정수형(문자형) 값만 비교할 수 있습니다. 함수식도 가능.
//break쓰는 것을 까먹을 수 있으므로 먼저 쓰는 것을 습관화한다.
//구구단을 출력하는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	int i;
	int j;

	for (i = 1;i <= 9;i++) {
		for (j = 1;j <= 9;j++) {
			printf("%d * %d = %2d\n", i, j, i*j);
		}
	}

	for (i = 1;i <= 9;i++) {
		if (i == 5) continue; //위로 점프
		printf("%d ", i); //1 2 3 4 6 7
		if (i == 7) break; //강제 종료
	}
}

//for문이 중첩되어 있는 경우, continue문과 break문은 for문 범위에서만 적용된다.
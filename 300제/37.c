//구구단 프로그램을 작성하세요. 단, 1단, 2단~9단까지 반복되는 값을 정수형 변수 i를 사용하여 순환시키고,
//i의 값이 1~9가 아닌 1~100까지 반복되게 한 후, i의 값이 9인 경우 탈출하게 만들어 보세요.
#include <stdio.h>

main() {
	int i;
	int j;

	for (i = 1;i <= 100;i++) {
		for (j = 1;j <= 9;j++) {
			printf("%d * %d = %2d\n", i, j, i*j);
			if (i == 9 && j == 9) goto ku_ku_end; //break;
		}
		//if(i==9) break;
	}

ku_ku_end:;
}
//여러 개의 중첩된 문장을 한 번에 빠져나가고자할 때 사용.
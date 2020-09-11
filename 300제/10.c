//잘못된 문장을 작성하여 컴파일 에러를 발생시켜 보세요.
#include <stdio.h>

main() {
	//int i;
	int hap = 0;

	for (i = 1;i <= 10;i = i + 1) {
		hap = hap + i
	}
	printf("1부터 10까지의 합 : %d", hap);
}

//소스코드->컴파일러->목적코드->링커->실행 가능한 프로그램
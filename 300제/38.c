//아스키 문자를 출력하는 프로그램을 작성하세요.
#include <stdio.h>

#define ASCII_BEGIN 0
#define ASCII_END 255

main() {
	int i;

	for (i = ASCII_BEGIN;i <= ASCII_END;i++) {
		printf("ASCII 코드 (%3d), 문자 = '%c'\n", i, i); //(char)i
	}
}
//%3d는 적어도 3자리를 채우겠다. 안되면 빈공간 넘으면 더 늘어남.
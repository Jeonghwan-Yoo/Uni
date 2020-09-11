//문자형 변수 ch에 255가 저장되어 있을 때, 이 값을 비트 연산을 통하여 127로 만들어 보세요.
#include <stdio.h>

main() {
	unsigned char ch = 255, mask = 0x7F;

	printf("%d\n", ch); //255
	printf("%d\n", ch&mask); //127
	printf("%d\n", (char)~ch); //0
	printf("%d\n", ch^ch); //0
	printf("%d\n", ch >> 1); //127
	printf("%d\n", mask << 1); //254
}
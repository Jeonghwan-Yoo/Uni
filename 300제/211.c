//비트 연산을 사용하여 소문자를 대문자로 변환하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[] = "abcdefghijklmnopqrstuvwxyz";
	unsigned i, len;

	puts(string);

	len = strlen(string); //문자열의 길이

	for (i = 0;i < len;i++) {
		string[i] = string[i] & 0xDF; //0xDF는 2진수로 1101 1111
	}
	puts(string);
}
//a는 0110 0001 A는 0100 0001이므로 32만큼 차이나고 3번째 비트만 0으로 해주면 되기때문에
//1101 1111을 AND로 마스크해주면 된다.
//대문자를 소문자로 바꾸려면, 'A'|0x20처럼 하면 됩니다.
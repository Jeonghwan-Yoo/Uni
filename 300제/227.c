//문자열 "boy is man"에서 각 단어의 첫 문자를 대문자로 변환하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(void) {
	char buff[] = "boy is man", *pos = buff;

	while (pos) {
		if (isalpha(buff[0]) && pos == buff) {
			buff[0] &= 0xDF;
			pos++;
		}
		else if (pos = strpbrk(pos, " ")) { //공백 찾으면,
			*++pos &= 0xDF; //그 다음번지가 대문자여야 한다.
		}
	}
	printf(buff);
}
//else if에서 등호 한개인 이유는 pos에 대입해서 그것을 판단하기 때문.
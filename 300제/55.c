//키보드로부터 문자열을 입력받고, 문자열 중 문자 'a'의 갯수를 세어 출력하는 프로그램을 작성하세요.
#include <stdio.h> //gets()

int count(char *str);

void main(void) {
	char string[100];
	char *ret;

	ret = gets(string);

	if (ret != NULL) {
		printf("문자 'a'의 갯수는 %d개입니다.", count(string));
	}
}

int count(char *str) {
	int cnt = 0;

	while (*str != (int)NULL) {
		if (*str++ == 'a') cnt++; //*str++; cnt++;
	}
	return cnt;
}
//문자열을 읽어서 저장하기 위한 문자열 버퍼. 반환값이 있다.
//string은 배열의 첫 번째 번지를 가리키는 번지 상수이다.
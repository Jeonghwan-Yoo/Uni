//문자열을 출력하는 print() 함수 프로그램을 작성하세요.
#include <stdio.h>

int print(char* string);

main() {
	print("This is a function!");
}

int print(char* string) {
	int len = 0;

	while (*string != NULL) {
		printf("%c", *string);
		string++; //번지 값을 1 증가
		len++; //문자열의 길이를 1증가
	}
	return len; //총 문자열의 길이를 반환.
}
//줄여서 printf("%c",*string++); 이라고 쓸 수 있다.
//문자열 "(a12), (b34), (c56)"에서 알파벳만 분리하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void main(void) {
	char string[] = "(a12), (b34), (c56)";
	char* token;

	token = strtok(string, "(123456), ");

	while (token) {
		puts(token);
		token = strtok(NULL, "(123456), ");
	}
}
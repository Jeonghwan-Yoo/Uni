//"암호는 Korea입니다."에서 "Korea"를 "*****"로 교체하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void main(void) {
	char string[] = "암호는 Korea입니다.";
	char* pstr;

	pstr = strstr(string, "Korea");
	if (pstr) {
		strnset(pstr, '*', 5); //큰 따옴표하면 다른 값이 나옴.
	}
	puts(string);
}
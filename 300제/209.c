//2진수 문자열 "1010" 및 16진수 문자열 "FF"를 정수값으로 변환하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char string1[] = "1010"; //2진수
	char string2[] = "ff"; //16진수

	char* stop;
	long value;

	value = strtol(string1, &stop, 2);
	printf("2진문자열 \"%s\"을 정수로 바꾸면 %d입니다.\n", string1, value);

	value = strtol(string2, &stop, 16);
	printf("16진문자열\"%s\"을 정수로 바꾸면 %d입니다.\n", string2, value);
}

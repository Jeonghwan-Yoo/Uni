//���ڿ� "(a12), (b34), (c56)"���� ���ĺ��� �и��Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
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
//���ڿ� ���ڰ� ȥ�յ� "Cat 1 Car 2 Cow 3"�� ���� ���ڿ����� ���ڿ� ���ڸ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string = "Cat 1 Car 2 Cow 3,...";
	char buffer[100] = { 0 };
	int cnt = 0;

	while (*string) {
		if (isalnum(*string)) {
			buffer[cnt++] = *string;
		}
		string++;
	}
	puts(buffer);
}
//int isalnum(int c);
//c�� ���� ���ڰ��Դϴ�.
//���ڰ� ���� �� ��Ÿ ���ڵ��� ���ԵǾ� �ִ� ���ڿ����� ���ڿ� ���ڸ� �̾Ƴ��� ��쿡 isalnum()�� ���.
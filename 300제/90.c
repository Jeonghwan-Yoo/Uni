//���ڿ� ���ڰ� ȥ�յ� "Cat 1 Car 2 Cow 3"�� ���� ���ڿ����� ���ڸ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string = "Cat 1 Car 2 Cow 3,...";
	char buffer[100] = { 0 };
	int cnt = 0;

	while (*string) {
		if (isdigit(*string)) {
			buffer[cnt] = *string;
			cnt++;
		}
		string++;
	}
	puts(buffer);
}
//int isdigit(int c);
//c�� ���� ���ڰ��Դϴ�.
//"(02) 1111-2222"���� ���ڸ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char* string = "(02) 1111-2222";
	char buff[20] = { 0, };
	int i = 0;

	while (*string) {
		if (isdigit(*string)) {
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);
}
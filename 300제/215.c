//���ڿ� "This is a book"���� ���ڿ� "book"�� ��ġ�� ���ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	char string[] = "This is a book";
	//               012345678901234
	char* pos;

	pos = strstr(string, "book");

	if (pos) { //if(pos!=NULL)
		printf("book�� %d��°���� ã�ҽ��ϴ�.\n", pos - string);
		printf("%s\n", &string[pos - string]);
	}
}
//���� ������ �Է� �޾� ������ �������� �߶󳻴� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

#define TOKEN " "

void main(void) {
	char string[100];
	char* pos;

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");

	gets(string);

	pos = strpbrk(string, TOKEN);

	while (pos != NULL) {
		puts(pos++);

		pos = strpbrk(pos, TOKEN);
	}
}
//char* strpbrk(const char* string, const char* strCharSet);
//string�� �˻��� ���ڿ�, strCharSet�� ���� ���� �Ǵ� ���ڼ�Ʈ.
//������ ã�� ���, ������ �ִ� �ڸ��� ���� ������ ��ȯ�մϴ�.
//���� ���, ���� �迭 ���� string�� ���� ������ ��ȯ�մϴ�.
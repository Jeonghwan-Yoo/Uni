//��(NULL) ���� ���Ե� ���۸� ���ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char s1[100] = "123";
	char s2[100] = "123";

	strcpy_s(&s1[4], sizeof("abc"), "abc"); //1 2 3 \0 a b c \0
	strcpy_s(&s2[4], sizeof("efg"), "efg"); //1 2 3 \0 e f g \0
	
	if (strcmp(s1, s2) == 0) {
		puts("strcmp : ������ ���� ��ġ�մϴ�.");
	}

	if (memcmp(s1, s2, 7) == 0) {
		puts("memcmp : ������ ���� ��ġ�մϴ�.");
	}
	else {
		puts("memcmp : ������ ���� ��ġ���� �ʽ��ϴ�.");
	}
}
//int memcmp(const void* buf1, const void* buf2, unsigned int count);
//buf1, buf2�� ���� �����̸�, count�� ���� ������ ũ���Դϴ�.
//strcmp()�� 3�� ��ġ���� ���� �����ϱ� ������ 3����Ʈ�� �񱳵ǰ�, �� ���ڿ��� ���ٰ� ���ɴϴ�.
//memcmp()�Լ��� ���� 7����Ʈ�� ���ϸ� ����� �ٸ��ٴ� ���� �� �� �ֽ��ϴ�.
//strcmp�� ���ڿ�(�α���)�� ���ϰ� memcmp�� ���ۿ� ������ ���̸�ŭ ��.
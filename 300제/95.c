//���ڿ��� "1a2b3c4d5e"ó�� �����Ǿ� ���� ��, �� ���ڿ��� "a1b2c3d4e5"ó�� ��ü�ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char string1[] = "1a2b3c4d5e";
	char string2[] = "..........";

	puts(string1);
	puts(string2);

	_swab(string1, string2, sizeof(string1) - 1);
	puts(string1);
	puts(string2);
}
//void swab(char* src,char* dest, int count);
//src�� ���� ���ڿ�, dest�� �ٲ���� ���ڰ� ����� ������ ������.
//count�� �ٲ���� �� ������ ��
//���ڿ��� 2����Ʈ�� �߶� �յڷ� ��ü�մϴ�. sizeof(string1)�� NULL�� ������ 11�� �˴ϴ�.
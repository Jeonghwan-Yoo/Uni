//�� ���� �ܾ �Է¹޾�, �� �ܾ �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string1[100];
	char string2[100];

	printf("ù ��° �ܾ �Է��ϼ���!\n");
	gets(string1);

	printf("�� ��° �ܾ �Է��ϼ���!\n");
	gets(string2);

	strcat_s(string1, sizeof(string1),string2);

	puts(string1);
}
//string1�� string2�� �����մϴ�.
//char* strcat(char* dest, const char* src);
//dest ���۴� src���ڿ��� �߰��� ��ŭ�� ����� ���۰� �־�� �Ѵ�.
//strncat():���ڿ� ���դ��� ����������, ���� ���ڿ����� ������ ���� ���ڿ��� �������� �߰��Ǵ� ������ ������ ������ �� �ִ�.
//char* strncat(char* dest,const char* src,unsigned int count);
//���ڿ� ���ڰ� ȥ�յ� "Cat 1 Car 2 Cow 3"�� ���� ���ڿ����� ���ĺ� ���ڸ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string = "Cat 1 Car 2 Cow 3,...";
	char buffer[100] = { 0, }; //��� ������ ���� �η� �ʱ�ȭ
	int cnt = 0;

	while (*string) {
		if (isalpha(*string)) {
			buffer[cnt++] = *string;
		}
		string++;
	}
	puts(buffer);
}
//int isalpha(int c);
//c�� ���� ���ڰ��Դϴ�.
//string�� ���ڿ� ����� ����Ű���� �ʱ�ȭ����������, string�� ī��Ű�� ������ �ٸ� ���� ������ �� �����ϴ�.
//�빮�ڿ� �ҹ��� ������ �ִ� ��� 1�� ��ȯ�ϰ� �ƴϸ� 0�� ��ȯ.
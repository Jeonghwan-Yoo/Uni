//���ڿ� "This is Korea!"���� �ҹ��ڸ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string = "This is Korea!";
	char buffer[100] = { 0 };
	int cnt = 0;

	while (*string) {
		if (islower(*string)) {
			buffer[cnt++] = *string;
		}
		string++;
	}
	puts(buffer);
}
//int islower(int c);
//c�� ���� ���ڰ��Դϴ�.
//��ҹ��ڸ� ���н� isupper(65); �Ǵ� islower(97)ó�� ���ڰ����� ���� ���� �ֽ��ϴ�.
//if(*string>='a'&&*string<='z') ...
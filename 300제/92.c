//���ڿ� "This is Korea!"���� �빮�ڸ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string="This is Korea!";
	char buffer[100] = { 0 };
	int cnt = 0;

	while (*string) {
		if (isupper(*string)) {
			buffer[cnt++] = *string;
		}
		string++;
	}
	puts(buffer);
}
//int isupper(int c);
//c�� ���� ���ڰ��Դϴ�.
//�ѱ� �� ���ڴ� ��ҹ��ڸ� ������ �� �����ϴ�. isupper()�� ������� �ʰ� �빮������ �˻��Ϸ���
//if(*string>='A'&&*string<='Z') ...
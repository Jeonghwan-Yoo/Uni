//"���ѹα� Korea"���� �ѱ۸� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	unsigned char* string = "���ѹα� Korea";
	unsigned char buff[20] = { 0, };
	int i = 0;

	while (*string) {
		if (*string > 127) {
			buff[i++] = *string;
		}
		string++;
	}
	puts(buff);
}
//�ѱ��� �����ڿ� �޸�, �ƽ�Ű ���� 127���� ū 2����Ʈ�� ����մϴ�. ��� �׷��ȹ��ڰ� ���� ���� �ֽ��ϴ�.
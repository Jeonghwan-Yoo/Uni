//�޸𸮸� �ΰ����� ä��� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[50] = "�Ƹ��ٿ� �츮���� ���ѹα�";

	puts(string);

	memset(string, (int)NULL, sizeof(string));

	puts(string);

	memset(string, '*', sizeof(string) - 1);

	puts(string);
}
//void* memset(void* dest, int fillChar, unsigned int count);
//dest�� �ʱ�ȭ�� ����, fillChar�� �ʱ�ȭ�� ���� count�� dest�� �� ����Ʈ�� ���ڸ� ä�����.
//memset()�� ����ü������ �ٸ� ������ ���� 0���� �ʱ�ȭ�� �� ���.
//struct tagPoint pt;
//memset(&pt,0,sizeof(pt));
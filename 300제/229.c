//���ڿ��� �ʱ�ȭ�Ǵ� ���۸� �����ϰ�, �� ���۸� ���� �Ҵ����� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable:4996)

void main(void) {
	char buff[] = "���ڿ� �����ϱ�";
	char* dup;

	dup = strdup(buff);
	if (dup) {
		strcpy(buff, "�ٸ� ���ڿ�");
		puts(buff);
		puts(dup);
		free(dup);
	}
}
//�������Ѱ��� �ּҸ� �����Ѱ� �ƴϴ�.
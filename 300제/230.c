//100����Ʈ ���� 10000���� �Ҵ��ϰ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#include <malloc.h>

void main(void) {
	char* pbuf;

	pbuf = malloc(100 * 10000);

	if (pbuf) {
		memset(pbuf, 0, 100 * 10000);
		strcpy_s(&pbuf[0], sizeof("����� ��õ�� ��"), "����� ��õ�� ��");
		puts(&pbuf[0]);
		free(pbuf);
	}
}
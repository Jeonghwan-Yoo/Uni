//�޸𸮸� 100MB �Ҵ��ϰ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#pragma warning(disable:4996)

#define MEGA_BYTE 1048576

void main(void) {
	char* pbuf;

	pbuf = malloc(100 * MEGA_BYTE);

	if (pbuf) {
		memset(pbuf, 0, 100 * MEGA_BYTE);

		strcpy(&pbuf[0], "����� ��õ�� ��");
		puts(&pbuf[0]);

		strcpy(&pbuf[104857500], "�λ�� ������ ������");
		puts(&pbuf[104857500]);

		free(pbuf);
	}
}
//malloc�� �ʱ⿡ ������ ����� ä���� �ֽ��ϴ�.
//�׸���, �޸� ����� ù ��° ����Ʈ�� �ּ� ���� ��ȯ.
//1024����Ʈ ������ �޸𸮸� �Ҵ��ϰ� ����ϴ� ���� ����.
//���ڿ��� �Է¹ް�, �Է� ���� ���ڿ� �߿� "sky"�� �ִ��� �˻��ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

#define SKY "sky"

void main(void) {
	char string[100];
	char* ret;

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("���ڿ� �߿� sky�� ���ԵǾ� ������, ���α׷��� ����˴ϴ�.");

	do {
		gets(string);

		ret = strstr(string, SKY);

		if (ret == NULL) {
			puts("���ڿ� �߿� sky�� �����ϴ�.");
		}
		else {
			printf("%d ��ġ���� sky ���ڿ��� ã�ҽ��ϴ�.", ret - string);
			break;
		}
	} while (1);
}
//char* strstr(const char* string, const char* strCharSet);
//strCharSet�� �˻��� ���� �Ǵ� ���ڿ�. �˻� ���� ���� ��ġ�� ������ ��(����)�� ��ȯ�ϸ� ���н� NULL ��ȯ.
//ã�� ��ġ�� ���� �޸��� ������ ��ȯ�ϴµ�, ��ȯ���� �׻� ���� �迭 ���� string�� ����Ű�� �������� ũ�ų� �����ϴ�.
//�׷��� ret-string�� �̿�.
//���� ���� �� ���� ���������̼� �̿�.
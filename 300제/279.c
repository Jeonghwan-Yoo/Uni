//"12345678"�� ��Ʈ ���� XOR�� ����Ͽ� ��ȣȭ�ϰ� ��ȣȭ�ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

#define SECRETKEY "!@#$%^&*()_+=-"

void main(void) {
	int i;
	char string[] = "1234567890";

	puts(string);

	for (i = 0;i < strlen(string);i++) {
		string[i] ^= SECRETKEY[i];
	}

	puts(string);

	for (i = 0;i < strlen(string);i++) {
		string[i] ^= SECRETKEY[i];
	}
	puts(string);
}
//��ȣȭ:���� �� �޽����� �ٸ� ����� ������ �� ���� ���� �ڵ�� �����ϴ� ��
//��ȣȭ:��ȣȭ�� ���� �� �޽����� ������ ���·� �����ϴ� ��.
//��Ʈ�����ڴ� ������ ���� ���� �������� ��Ʈ�� �ٷ� �� �ְ� ���ݴϴ�.
//��Ʈ�����ڴ� �������� char, int ,long�������� ��� ����.
//C���α׷����� �ý��� �ϵ��� �����ٷ�� ��쿡 ���� ���� ���.
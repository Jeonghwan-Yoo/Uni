//���� ������ �Է¹޾� �������� �����Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdio.h>

#define TOKEN " "

void main(void) {
	char string[100];
	char* token;

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");

	gets(string);

	token = strtok(string, TOKEN);

	while (token != NULL) {
		puts(token);

		token = strtok(NULL, TOKEN);
	}
}
//char* strtok(char* strToken, const char* strDelimit);
//strToken�� ���� ���ڿ� �̸� strDelimit�� ���й��� �Ǵ� ���ڼ�Ʈ�Դϴ�.
//������ ã�� ���, ������ �ִ� �ڸ��� NULL�� ���� �� ���ڿ��� ���� ������ ��ȯ�ϰ�,
//���� ���, ���� �迭 ���� string�� ���� ������ ��ȯ�մϴ�.
//strtok()�Լ��� ���������� ������ �˻��� ��ġ�� �����ϰ� �ֽ��ϴ�. �׷��Ƿ� string�� �ƴ� NULL�� �Ѱ��ָ�,
//�˻��� ���� ��ġ���� �ڵ����� �˻��մϴ�.
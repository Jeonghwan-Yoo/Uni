//3���� ���ڷε� ���ڿ��� �Է¹޾� �ջ��Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int count; //3ȸ�� ī��Ʈ�ϱ� ���� ����
	int total = 0; //���� �������� �ջ��ϱ� ���� ����
	char string[100];

	for (count = 1;count <= 3;count++) {
		printf("%d��° ���ڿ��� �Է��� �� EnterŰ�� ��������.\n", count);

		gets(string);

		total += atoi(string);

		printf("�Է� �� = %d, �� �� = %d\n", atoi(string), total);
	}
	printf("���� ���ڿ��� �� ���� %d�Դϴ�.\n", total);
}
//int atoi(const char* string);
//string�� ���ڷ� ��ȯ�� ���ڿ� �����Դϴ�.
//��ȯ ������ ���ڿ��� ����, ��, ��ȣ �׸��� ���ڻ��Դϴ�.
//�������� �������ϴ�.
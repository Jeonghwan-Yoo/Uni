//���� ������ �Է¹޾�, �Է¹��� ���ڿ��� ��� �빮�ڷ� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[100];

	puts("���ڿ��� �Է��� �� EnterŰ�� ġ����!");
	puts("�ƹ� ���ڵ� �Է����� ������ ���α׷��� ����˴ϴ�!");

	do {
		gets(string);

		if (strlen(string) == 0) break;

		_strupr_s(string,sizeof(string));
		puts(string);
	} while (1);
}
//char* strupr(char* string);
//string�� �빮�ڷ� ��ȯ�� ���� �����Դϴ�. ��, �ݵ�� ���ڿ� �����̰ų� ���ڿ� ���۸� ����Ű�� �����Ϳ��� �Ѵ�.
//���� ���ڿ� ��� ���� string�� ����Ѵٸ� �޸� ������ �߻��Ǹ鼭 ������ �����.
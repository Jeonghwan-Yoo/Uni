//���ڿ� "1.234E-10"�� ���� ������ ������ ���ڿ��� ���ڷ� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char* string = "1.234E-10";
	char* stop;
	double value;

	value = strtod(string, &stop);

	printf("%d���� ���ڰ� ��ȯ�Ǿ����ϴ�.\n", stop - string);
	printf("���ڿ�[%s]�� ���ڷ� ��ȯ�ϸ� %E�Դϴ�.\n", string, value);
}
//double strtod(conset char* string, char**stop);
//string�� ������ ���Ե� ���ڿ��̸�, stop�� ��ȯ�� �Ǵٰ� ������ ��ġ�� ������ ���Դϴ�.
//16���� ���ڿ��� 10������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char* string = "0xFF";
	char* stop;
	int radix;
	long value;

	radix = 16;

	value = strtol(string, &stop, radix);

	printf("%d���� ���ڰ� ��ȯ�Ǿ����ϴ�.\n", stop - string);
	printf("16���� %s�� ���ڷ� ��ȯ�ϸ� %ld�Դϴ�.\n", string, value);
}
//long strtol(const char* string, char** stop, int radix);
//���(radix)�� �� ������ �⺻�� �Ǵ� ���Դϴ�.
//stop�� ���ڿ��� ���ڷ� ��ȯ�ϴٰ� ������ ��ġ�� �����ϱ� ���� ������ �����Դϴ�. �� ���� ����Ͽ� ���ڿ���
//���ڷ� ��ȯ�� ���̸� Ȯ���� �� �ֽ��ϴ�.
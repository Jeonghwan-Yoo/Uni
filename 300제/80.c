//2���� ���ڿ��� 10������ ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char* string = "11000";
	char* stop;
	int radix;
	unsigned long value;

	radix = 2;

	value = strtoul(string, &stop, radix);

	printf("%d���� ���ڰ� ��ȯ�Ǿ����ϴ�.\n", stop - string);
	printf("2���� %s�� ���ڷ� ��ȯ�ϸ� %u�Դϴ�.\n", string, value);
}
//unsigned long strtoul(const char* string, char** stop, int radix);
//���� ��ȯ���� unsigned long���̶�� ���� �ٸ���.
//stop�� ���ڿ��� ���ڷ� ��ȯ�ϴٰ� ������ ��ġ�� �����ϱ� ���� ������ �����Դϴ�. 
//�� ���� ����Ͽ� ���ڿ��� ���ڷ� ��ȯ�� ���̸� Ȯ���� �� �ֽ��ϴ�.
//���ڿ� "This is a string $$$"���� "~!@#$%^&*()_+={}[]:;'<>./?" ���� �ϳ��� ���Ե� ���ڸ� ã�� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char* string = "This is a string $$$";
	char* strCharSet = "~!@#$%^&*()_+={}[]:;'<>./?";
	unsigned int pos;

	pos = strcspn(string, strCharSet);

	puts("0         1         2         3");
	puts("0123456789012345678901234567890");
	puts(string);
	puts(strCharSet);

	printf("%d ��ġ���� ��ġ�Ǵ� ù ���ڸ� �߰��Ͽ����ϴ�.\n", pos);
}
//unsigned int strcspn(const char* string, const char* strCharSet);
//string�� �˻��� ���ڿ�, strCharSet�� �˻��� ���ڵ��� ��Ʈ(���ڿ��� �ƴ�)
//���� ���ڼ�Ʈ �߿��� �ϳ��� ���ڶ� ��ġ�Ѵٸ� �� ��ġ�� ��ȯ�Ͽ� �ָ�, ��ġ�Ǵ� ���ڰ� ������ ���ڿ��� ���̰� ��ȯ.
//��ġ���� �ʴ� ù ���ڸ� �˻��Ϸ��� strspn() �̿�.
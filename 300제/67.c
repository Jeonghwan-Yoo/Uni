//���ڿ� "this is a very good!"���� "abcdefghijklmnopqrstuvwxyz " ���� �ϳ��� ���Ե��� �ʴ� ù ��° ������ ��ġ��
//ã�� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char* string = "this is a very good!";
	char* strCharSet = "abcdefghijklmnopqrstuvwxyz "; //����:���� ����
	unsigned int pos;

	pos = strspn(string, strCharSet);
	
	puts("0         1         2         3");
	puts("0123456789012345678901234567890");
	puts(string);
	puts(strCharSet);

	printf("%d ��ġ���� ��ġ���� �ʴ� ���ڸ� �߰��Ͽ����ϴ�.\n", pos);
}
//unsigned int strspn(const char* string, const char* strCharSet);
//string�� �˻��� ���ڿ�, strCharSet�� �˻��� ���ڵ��� ��Ʈ.
//���� ���ڼ�Ʈ �߿��� �ϳ��� ���ڶ� ��ġ���� �ʴ´ٸ� �� ��ġ�� ��ȯ�Ͽ� �ָ�,
//��� ���ڰ� ��ġ�Ǹ� ���ڿ��� ���̰� ��ȯ�˴ϴ�.
//strchr():���ڿ� ������ ó������ ��Ÿ���� ������ ���ڸ� ã���ϴ�.
//strrchr():���ڿ����� ���������� ��Ÿ���� ������ ���ڸ� ã�´ٴ� ���� �����ϸ� strchr()�� �����մϴ�.
//strcspn():� ���ڿ��� ���ԵǾ� �ִ� ���ڵ��� �ٸ� ���ڿ����� ó������ ��Ÿ������ġ�� ã���ϴ�.
//strspn():���Ե��� �ʴ� ���ڸ� ã���ϴ�.
//strpbrk():strcepn()�� ����ϰ� �� ���ڿ��� ���ԵǾ� �ִ� � ���ڰ� �ٸ� ���ڿ����� ó������
//��Ÿ���� ��ġ�� ã���ϴ�. �׷��� �� �Լ��� �˻� �������� �� ���ڸ� ���Խ�Ű�� �ʴ´ٴ� ���� �ٸ��ϴ�.
//strstr():� ���ڿ� ������ �� ���ڿ��� ó������ ��Ÿ���� ��ġ�� ã��, ���ڿ� ������ �������� ���ڵ��� �ƴ϶�,
//��ü ���ڿ��� ã���ϴ�.
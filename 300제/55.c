//Ű����κ��� ���ڿ��� �Է¹ް�, ���ڿ� �� ���� 'a'�� ������ ���� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h> //gets()

int count(char *str);

void main(void) {
	char string[100];
	char *ret;

	ret = gets(string);

	if (ret != NULL) {
		printf("���� 'a'�� ������ %d���Դϴ�.", count(string));
	}
}

int count(char *str) {
	int cnt = 0;

	while (*str != (int)NULL) {
		if (*str++ == 'a') cnt++; //*str++; cnt++;
	}
	return cnt;
}
//���ڿ��� �о �����ϱ� ���� ���ڿ� ����. ��ȯ���� �ִ�.
//string�� �迭�� ù ��° ������ ����Ű�� ���� ����̴�.
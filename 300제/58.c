//"���ѹα�"�̶�� ���ڿ��� �����ϴ� �Լ� My_strcpy�� �ۼ��ϼ���.
#include <stdio.h>

#define KOREA "���ѹα�"

char* My_strcpy(char* dest, const char* src);
char* My_strncpy(char* dest, const char* src, int count);

void main(void) {
	char string[100];

	My_strcpy(string, KOREA);
	My_strncpy(string, KOREA,6);

	puts(string); //���ѹα��� ���
}

char* My_strcpy(char* dest, const char* src) {
	char* ret = dest;
	//��� ���ڿ��� ���̰� 0�̸� dest�� NULL�� ����.
	if (dest == (int)NULL || src == (int)NULL) {
		if (*dest != (int)NULL) *dest = (int)NULL;
		return NULL;
	}
	do {
		*dest++ = *src;
		
	} while (*src++ != (int)NULL);
	return ret;
}
//*dest++=*src++;�� �ϰԵǸ� �������� dest�� null�� ���� ���� ����.
//c������ ���ڿ��� ó���ϴ� ��� ������ ���ڿ��� ���� ������ �� �����ϴ�.
//�޸𸮿��� ���� ���ڿ��� ���� ���ڿ��� �޸� �������� �����ؾ� �մϴ�.
//�����Լ�:strcpy(), strncpy(), strdup()
//strcpy():��ü ���ڿ��� �ٸ� �޸� �������� �����մϴ�.
//strncpy():��ü ���ڿ��� �ٸ� �޸� ������ �����ϰ�, ������ ������ ������ ������ �� �ֽ��ϴ�.
//strdup():malloc()�Լ��� ȣ���Ͽ� ���� ���ڿ��� �����ϱ� ���� �޸� ������ �Ҵ��Ѵ�.

char* My_strncpy(char* dest, const char* src, int count) {
	if (dest == (int)NULL || src == (int)NULL) {
		if (*dest != (int)NULL) {
			*dest = (int)NULL;
		}
		return NULL;
	}
	while (~(*src != NULL)&&(count--!=0)) {
		*dest++ = *src++;
	}
	*dest = NULL;
}

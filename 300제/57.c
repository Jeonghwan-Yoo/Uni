//"���ѹα�"�̶�� ���ڿ��� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

#define KOREA "���ѹα�"

void main(void) {
	char *string1;
	char string2[100];

	strcpy_s(string1, sizeof(KOREA),KOREA); //���� �� ���� �߻�
	strcpy_s(string2, sizeof(KOREA),KOREA);
	strcpy_s(string2, sizeof("��"),"��");
}

//��ȯ���� ������ �������̴�.
//src�� const�� �ְ� dest�� const�� ����.
//dest�� �Ѱ��ִ� ���ڴ� ���ڿ� ����� �� �� �����ϴ�. dest�� �Ѱ��ִ� ������ ������ ���� strcpy()���ο��� ����Ǳ� ����.
//�׷���, ���ڿ� ����� ����Ű�� ������ ������ �� ����� �� ����.
//dest�� �Ѱ��� �� �ִ� ���� ���� �迭 ���Դϴ�.
//���࿡, ������ ������ ������ �����ϰ�, �� ������ ������ ���� �迭 ������ ����Ű�� dest�� �����ϴ�.
//dest�� �Ѱ��ִ� ������ strcpy() �Լ� ���ο��� ������ �� �ִ���, �������� ����.
//src�� ��� �Ѱ��� �� ������, �ʱ�ȭ���� �ʴ� ������ ������ ����� �� ����. ������ �ʱ�ȭ �ؾ��Ѵ�.
//�κ������� �����Ϸ��� int strncpy(char *string1, const char *string2, unsigned int count);
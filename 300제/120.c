//119���� ���� ad ������ ����ϴ� �����͸� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct tagAddress {
	char name[30]; //�̸�
	char phone[20]; //��ȭ
	char address[100]; //�ּ�
};

void main(void) {
	struct tagAddress ad;
	struct tagAddress *pad;

	pad = &ad;

	strcpy((*pad).name, "ȫ�浿");
	strcpy((*pad).phone, "02-1234-5678");
	strcpy((*pad).address, "����� ��õ�� �񵿾���Ʈ 13����");

	printf("�̸� : %s\n", pad->name);
	printf("��ȭ : %s\n", pad->phone);
	printf("�ּ� : %s\n", pad->address);
}
//����ü�� �Ϲ� ����ó�� ���Ǳ� ������ ���� ���������ڸ� �ݵ�� ����ؾ� �մϴ�.
//*�� .���� �켱������ ���� ������ ��ȣ�� �����־�� �մϴ�.
//(*pad).name���ٴ� pad->name�� �� ���� ���ȴ�.
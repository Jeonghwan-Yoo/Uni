//�ּҷϿ� ���Ǵ� �̸�, ��ȭ��ȣ, �ּҸ� ����ü�� ����Ͽ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct tagAddress {
	char name[30]; //�̸�
	char phone[20]; //��ȭ
	char address[100]; //�ּҤ�
}; //�߰�ȣ �ڿ� �����ݷ��� ����� ���߸��� ������

void main(void) {
	struct tagAddress ad;

	strcpy(ad.name, "ȫ�浿");
	strcpy(ad.phone, "02-1234-5678");
	strcpy(ad.address, "����� ��õ�� �񵿾���Ʈ 13����");

	printf("�̸� : %s\n", ad.name);
	printf("��ȭ : %s\n", ad.phone);
	printf("�ּ� : %s\n", ad.address);
}
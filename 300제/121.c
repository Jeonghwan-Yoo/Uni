//120���� ���� ����ü ������ pad�� ����Ͽ� �ּҷ��� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void print(struct tagAddress *pad);

struct tagAddress {
	char name[30]; //�̸�
	char phone[20]; //��ȭ
	char address[100]; //�ּ�
};

void main(void) {
	struct tagAddress ad;

	strcpy(ad.name, "ȫ�浿");
	strcpy(ad.phone, "02-1234-5678");
	strcpy(ad.address, "����� ��õ�� �񵿾���Ʈ 13����");

	print(&ad);
}

void print(struct tagAddress *pad) {
	printf("�̸� : %s\n", pad->name);
	printf("��ȭ : %s\n", pad->phone);
	printf("�ּ� : %s\n", pad->address);
}
//�����͸� ����Ͽ� ������, ����, ������ ����� ���� ��� ������ �������� �ʵ��� �սô�. �����Ϳ����� ������ ���˴ϴ�.
//�������� ���� �����ǰų� ���ҵ� ������ 1�̳� ������ ����ŭ ��ȭ�ϴ� ���� �ƴ϶�, �����Ͱ� ����Ű�� �������� ũ�⸸ŭ
//���� �����ǰų� ���ҵȴٴ� ���� ���� �ʵ��� �սô�.
//�迭�� ���Ǵ� ���� ��, ������ ����� ������Ű�ų� ���ҽ�Ű�� �ʵ��� �սô�.
//�����Ϳ� �迭�� ���� �ּҸ� �Ҵ��ϰ� ���� ������ ������ ����մϴ�.
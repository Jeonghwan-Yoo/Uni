//123���� ���� ����ü ������ pad�� ����Ͽ� �ּҷ��� ����ϴ� �Լ��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct tagAddress {
	char name[30]; //�̸�
	char phone[20]; //��ȭ
	char address[100]; //�ּ�
};

void print(struct tagAddress *pad);

void main(void) {
	struct tagAddress ad[3];
	int i;

	for (i = 0;i < 3;i++) {
		sprintf(ad[i].name, "ȫ�浿 %d", i);
		strcpy(ad[i].phone, "02-1234-5678");
		strcpy(ad[i].address, "����� ��õ�� �񵿾���Ʈ 13����");
	}

	print(ad);
}

void print(struct tagAddress *pad) {
	int i;

	for (i = 0;i < 3;i++) {
		printf("�̸� : %s\n", pad[i].name);
		printf("��ȭ : %s\n", pad[i].phone);
		printf("�ּ� : %s\n", pad[i].address);
	}
}
//����ü �����͸� ������� �ʰ� ����ü ������ ���� �����Ѵٸ�, �������� ���޿� ���� �� �� �ð��� �ɸ����̸�,
//�迭�� �����Ѵٸ� �� �ð��� �� ���� �þ ���Դϴ�.
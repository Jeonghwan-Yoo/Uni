//����ü �迭�� ����Ͽ� 119���� ���� �ּҷ��� 3�� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

struct tagAddress {
	char name[30]; //�̸�
	char phone[20]; //��ȭ
	char address[100]; //�ּ�
};

void main(void) {
	struct tagAddress ad[3];
	int i;

	for (i = 0;i < 3;i++) {
		sprintf(ad[i].name, "ȫ�浿 %d", i);
		strcpy(ad[i].phone, "02-1234-5678");
		strcpy(ad[i].address, "����� ��õ�� �񵿾���Ʈ 13����");
	}

	for (i = 0;i < 3;i++) {
		printf("�̸� : %s\n", ad[i].name);
		printf("��ȭ : %s\n", ad[i].phone);
		printf("�ּ� : %s\n", ad[i].address);
	}
}
//����ü �迭�� �Ϲ� �迭�� ���� ���.
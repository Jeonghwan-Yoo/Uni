//i���� ���� �б�Ǵ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

main() {
	int i = 5;

	switch (i) {
	case 1:
		printf("i�� 1�Դϴ�.");
		break;
	case 2:
		printf("i�� 2�Դϴ�.");
		break;
	default:
		printf("i�� %d�Դϴ�.", i);
		break;
	}
	/*
	if (i == 1) {
		printf("i�� 1�Դϴ�.");
	}
	else if (i == 2) {
		printf("i�� 2�Դϴ�.");
	}
	else {
		printf("i�� %d�Դϴ�.", i);
	}
	*/
}
//���� ���ù��� ������(������) ���� ���� �� �ֽ��ϴ�. �Լ��ĵ� ����.
//break���� ���� ����� �� �����Ƿ� ���� ���� ���� ����ȭ�Ѵ�.
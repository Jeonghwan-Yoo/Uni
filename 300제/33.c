//�������� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

main() {
	int i;
	int j;

	for (i = 1;i <= 9;i++) {
		for (j = 1;j <= 9;j++) {
			printf("%d * %d = %2d\n", i, j, i*j);
		}
	}

	for (i = 1;i <= 9;i++) {
		if (i == 5) continue; //���� ����
		printf("%d ", i); //1 2 3 4 6 7
		if (i == 7) break; //���� ����
	}
}

//for���� ��ø�Ǿ� �ִ� ���, continue���� break���� for�� ���������� ����ȴ�.
//������ �߻���Ű�� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void main(void) {
	int i;

	srand((unsigned)time(NULL)); //���� �߻��⸦ �ʱ�ȭ
	
	for (i = 0;i < 5;i++) {
		printf("���� %d : %d\n", i, rand());
	}
}
//void srand(unsigned int seed); int rand(void);
//seed�� ������ �ʱⰪ�̸�, time(NULL)�� ����մϴ�.
//rand()������0~32767������ ��

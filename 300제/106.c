//������������ ������ ������ �����ϰ�, ������ ũ�⸦ ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	char *p_char;
	short *p_short;
	int *p_int;
	long *p_long;
	float *p_float;
	double *p_double;

	printf("�������� ũ�� : %d ����Ʈ\n", sizeof(char));
	printf("�������� ũ�� : %d ����Ʈ\n", sizeof(short));
	printf("�������� ũ�� : %d ����Ʈ\n", sizeof(int));
	printf("�������� ũ�� : %d ����Ʈ\n", sizeof(long));
	printf("�Ǽ����� ũ�� : %d ����Ʈ\n", sizeof(float));
	printf("�Ǽ����� ũ�� : %d ����Ʈ\n", sizeof(double));

	printf("������ �������� ũ�� : %d ����Ʈ\n", sizeof(p_char));
	printf("������ �������� ũ�� : %d ����Ʈ\n", sizeof(p_short));
	printf("������ �������� ũ�� : %d ����Ʈ\n", sizeof(p_int));
	printf("������ �������� ũ�� : %d ����Ʈ\n", sizeof(p_long));
	printf("�Ǽ��� �������� ũ�� : %d ����Ʈ\n", sizeof(p_float));
	printf("�Ǽ��� �������� ũ�� : %d ����Ʈ\n", sizeof(p_double));
}
//�Ϲ� ������ ���Ǵ� ������ ������ �°� �����ϰ� ����մϴ�.
//������ ������ �Ϲ� ������ ����Ǿ� �ִ� �޸� ������ �����ϱ� ������, ������ ������ ������� ������ 4����Ʈ.
//������ ������ char*, int* ���� ����ϴ� ������ �װͿ� ���� ���� ���꿡 ���� ������ �����ϱ� ���ؼ��Դϴ�.
//�������� ���� ������ �ַ� �迭 �������� ����ϸ�, ���� �����ڸ� ������ ������ ����,
//char*�� �����ʹ� 1, short*���� 2, int*���� 4, double*���� 8����Ʈ ���� �Ǵ� ���� �մϴ�.
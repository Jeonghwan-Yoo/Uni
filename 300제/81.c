//"21", "1004.5" �� �Ҽ����� ���Ե� ���ڿ��� �Ǽ��� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	char* string1 = "2.1�� 1.0���� Ů�ϴ�.";
	char* string2 = "1004.5�� õ��.�� �Դϴ�.";
	char* string3 = "2005�⵵ �Դϴ�.";
	char* string4 = "������ 6�� 9���Դϴ�.";
	double t1, t2, t3, t4;

	puts(string1);
	puts(string2);
	puts(string3);
	puts(string4);

	t1 = atof(string1);
	t2 = atof(string2);
	t3 = atof(string3);
	t4 = atof(string4);

	printf("���ڿ��� ���ڷ� ��ȯ�� �� : %.1f, %.1f, %.1f, %.1f\n", t1, t2, t3, t4);
	printf("�� ���� %.2f�Դϴ�.\n", t1 + t2 + t3 + t4);
}
//double atof(const char* string);
//string�� �Ҽ����� �����ϰ� �ִ� ���ڿ��Դϴ�.
//��ȯ ������ ���ڿ��� ����, ��, ��ȣ, ����, �Ҽ��� �׸��� ����(d,D,e,E)�Դϴ�.
//��ȯ�Ǵ� ���� ���� ��� 0.0�� ��ȯ�մϴ�.
//atof()�� �ִ� 100�ڸ��� ���ڿ��� ���ڷ� ��ȯ�� �� �ֽ��ϴ�.
//������ �����Ϳ� �Ǽ��� �������� ���� ��� ������ �� �ִ� �����͸� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	int i;
	double d = 3.14;

	int *pi;
	double *pd;
	void *pv;

	pi = &i;
	printf("���� �� i:%d\n", *(int*)pi);
	pd = &d;
	printf("�Ǽ� �� d:%f\n", *(double*)pd);
	pi = &d; //warning?
	printf("�Ǽ� �� d:%f\n", *(double*)pi);
	pv = &i;
	printf("���� �� i:%d\n", *(int*)pv);
	pv = &d;
	printf("�Ǽ� �� d:%f\n", *(double*)pv);
}
//void �����ʹ� ��� ���������� ������ �� �ִ� �ְ�� ������ �������Դϴ�.
//�� ������ �ƴ� ���� ���� ���� �����͸� ���޹ް��� �� �� ���.
//�ݵ�� � ������������ ���ǵ��� ĳ��Ʈ �����ڸ� ����Ͽ� �����ؾ� �մϴ�.

//������ ���� x, y�� �� �ٿ� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

main() {
	int x = 1, y = 2, max;

	max = (x > y ? x : y);
	
	printf("max=%d, x=%d, y=%d", max, x, y);
}
//��ǥ �����ڴ� for������ ���Ǹ�, ���� ���� ���� �ʱ�ȭ�� �� �ִ�.
//for(i=0,j=5;i<j;i++,j--)
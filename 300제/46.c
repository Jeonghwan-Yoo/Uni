//c++ ���� ���Ǵ� bool���������� �����ϰ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

#define true 1
#define false 0

typedef int bool;

main() {
	bool bCondition;

	bCondition = true;

	if (bCondition == true) {
		printf("���ǽ��� true�Դϴ�.");
	}
}
//typedef�� ���ο� ���������� ����� ��쿡 ���.
/*
typedef struct{
	int kor;
	int eng;
	int math;
} SungJuk;

SungJuk SJ; //struct�� ������� �ʾƵ� �ȴ�.
*/
//API(Application Programming Interface):���ø����̼��� �����ϱ� ���� �Լ��� ����.
//Windows API:�������� ���α׷��� ��������ؼ� ���Ǵ� ��. ���� typedef int INT; ���� �̿��Ѵ�.
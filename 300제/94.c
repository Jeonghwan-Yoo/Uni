//���ڿ� "This is Korea!\t\n"���� ����, �ǹ���, ���๮���� ���� ��� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <ctype.h>

void main(void) {
	char* string = "This is Korea!\t\n";
	int cnt = 0;

	while (*string) {
		if (isspace(*string)) {
			cnt++;
		}
		string++;
	}
	printf("����, �� �׸��� ���๮���� ���� %d�Դϴ�", cnt);
}
//int isspace(int c);
//c�� ���� ���ڰ��Դϴ�.
//isacii():�ƽ�Ű ��������
//iscntrl():���������
//isgraph():������ �����ϰ� �μ� ������ ��������
//isprint():������ �����ϰ� �μ� ������ ��������
//ispunct():����������
//isxdigit():16���� ��������
//isspace()�� �ʿ���� ���ڸ� �����Ϸ� �� �� �����մϴ�.
//if(*string==' '||*string=='\t'||*string=='\n'||*string=='r') ...
//������, ������, �Ǽ���, ���ڿ��� ������ �����ϰ�, �� ������ ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void main(void) {
	char cValue = 'a';
	int iValue = 1234567;
	long lValue = 7890123;
	float fValue = 3.141592;
	double dValue = 3.141592;
	char* string = "korea";
	char buffer[100];

	sprintf_s(buffer, sizeof(buffer), "char ���� %c", cValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "int ���� %d", iValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "long ���� %ld", lValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "float ���� %f", fValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "double ���� %e", dValue);
	puts(buffer);

	sprintf_s(buffer, sizeof(buffer), "char* ���� %s", string);
	puts(buffer);
}
//int sprintf(char* buffer, const char* format [,argument]...);
//buffer�� ����ȭ�� ���ڿ��� ����� ����, format�� printf()�Լ��� ������ ����ȭ ���ڿ�.
//���ۿ� ����ȭ�� ���ڿ��� ������ �� ����Ѵٴ� ���� �ٸ���.
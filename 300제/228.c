//"��ȣ�� Korea�Դϴ�."���� "Korea"�� "*****"�� ��ü�ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void main(void) {
	char string[] = "��ȣ�� Korea�Դϴ�.";
	char* pstr;

	pstr = strstr(string, "Korea");
	if (pstr) {
		strnset(pstr, '*', 5); //ū ����ǥ�ϸ� �ٸ� ���� ����.
	}
	puts(string);
}
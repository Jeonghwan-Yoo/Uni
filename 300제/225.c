//" .;;abc;;. "���� �¿��� " .;"���ڵ��� �߶󳻴� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	//               012345678901     
	char string[] = " .;;abc;;. ";
	char* sep = " .;;";
	int nIndex1, nIndex2;

	nIndex1 = strspn(string, sep); //4
	nIndex2 = strcspn(&string[nIndex1], sep); //7
	(&string[nIndex1])[nIndex2] = 0; //c���� ;���� null;
	printf("%s\n", &string[nIndex1]);
}
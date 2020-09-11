//" .;;abc;;. "에서 좌우의 " .;"문자들을 잘라내는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	//               012345678901     
	char string[] = " .;;abc;;. ";
	char* sep = " .;;";
	int nIndex1, nIndex2;

	nIndex1 = strspn(string, sep); //4
	nIndex2 = strcspn(&string[nIndex1], sep); //7
	(&string[nIndex1])[nIndex2] = 0; //c다음 ;부터 null;
	printf("%s\n", &string[nIndex1]);
}
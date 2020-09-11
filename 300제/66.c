//문자열 "This is a string $$$"에서 "~!@#$%^&*()_+={}[]:;'<>./?" 중의 하나가 포함된 문자를 찾는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char* string = "This is a string $$$";
	char* strCharSet = "~!@#$%^&*()_+={}[]:;'<>./?";
	unsigned int pos;

	pos = strcspn(string, strCharSet);

	puts("0         1         2         3");
	puts("0123456789012345678901234567890");
	puts(string);
	puts(strCharSet);

	printf("%d 위치에서 일치되는 첫 문자를 발견하였습니다.\n", pos);
}
//unsigned int strcspn(const char* string, const char* strCharSet);
//string은 검색될 문자열, strCharSet은 검색할 문자들의 세트(문자열이 아님)
//만약 문자세트 중에서 하나의 문자라도 일치한다면 그 위치를 반환하여 주며, 일치되는 문자가 없으면 문자열의 길이가 반환.
//일치되지 않는 첫 문자를 검색하려면 strspn() 이용.
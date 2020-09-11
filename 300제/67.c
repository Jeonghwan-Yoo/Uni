//문자열 "this is a very good!"에서 "abcdefghijklmnopqrstuvwxyz " 중의 하나가 포함되지 않는 첫 번째 문자의 위치를
//찾는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char* string = "this is a very good!";
	char* strCharSet = "abcdefghijklmnopqrstuvwxyz "; //주의:공백 포함
	unsigned int pos;

	pos = strspn(string, strCharSet);
	
	puts("0         1         2         3");
	puts("0123456789012345678901234567890");
	puts(string);
	puts(strCharSet);

	printf("%d 위치에서 일치되지 않는 문자를 발견하였습니다.\n", pos);
}
//unsigned int strspn(const char* string, const char* strCharSet);
//string은 검색될 문자열, strCharSet은 검색할 문자들의 세트.
//만약 문자세트 중에서 하나의 문자라도 일치하지 않는다면 그 위치를 반환하여 주며,
//모든 문자가 일치되면 문자열의 길이가 반환됩니다.
//strchr():문자열 내에서 처음으로 나타나는 지정된 문자를 찾습니다.
//strrchr():문자열에서 마지막으로 나타나는 지정된 문자를 찾는다는 것을 제외하면 strchr()과 동일합니다.
//strcspn():어떤 문자열이 포함되어 있는 문자들이 다른 문자열에서 처음으로 나타나는위치를 찾습니다.
//strspn():포함되지 않는 문자를 찾습니다.
//strpbrk():strcepn()과 비슷하게 한 문자열에 포함되어 있는 어떤 문자가 다른 문자열에서 처음으로
//나타나는 위치를 찾습니다. 그러나 이 함수는 검색 과정에서 널 문자를 포함시키지 않는다는 점이 다릅니다.
//strstr():어떤 문자열 내에서 한 문자열이 처음으로 나타나는 위치를 찾고, 문자열 내에서 개별적인 문자들이 아니라,
//전체 문자열을 찾습니다.
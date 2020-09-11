//문자열 "This is a book"에서 문자열 "book"의 위치를 구하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	char string[] = "This is a book";
	//               012345678901234
	char* pos;

	pos = strstr(string, "book");

	if (pos) { //if(pos!=NULL)
		printf("book을 %d번째에서 찾았습니다.\n", pos - string);
		printf("%s\n", &string[pos - string]);
	}
}
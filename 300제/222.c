//"사자 3마리, 코끼리 5마리, 사슴 4마리"에서 숫자가 시작되는 첫 위치를 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[] = "사자 3마리, 코끼리 5마리, 사슴 4마리";
	//               01234567890123456789012345678901234
	char* find = "0123456789";
	int index;

	index = strcspn(string, find);

	printf("%d 위치에서 일치되는 첫 숫자를 발견하였습니다.\n", index);
}
//일치하는 문자가 없을 경우 문자열의 길이가 반환됩니다.
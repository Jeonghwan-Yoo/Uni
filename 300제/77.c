//3개의 숫자로된 문자열을 입력받아 합산하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <stdlib.h>

void main(void) {
	int count; //3회를 카운트하기 위한 변수
	int total = 0; //읽은 정수값을 합산하기 위한 변수
	char string[100];

	for (count = 1;count <= 3;count++) {
		printf("%d번째 문자열을 입력한 후 Enter키를 누르세요.\n", count);

		gets(string);

		total += atoi(string);

		printf("입력 값 = %d, 총 합 = %d\n", atoi(string), total);
	}
	printf("읽은 문자열의 총 합은 %d입니다.\n", total);
}
//int atoi(const char* string);
//string은 숫자로 변환될 문자열 버퍼입니다.
//변환 가능한 문자열은 공백, 탭, 기호 그리고 숫자뿐입니다.
//나머지는 버려집니다.
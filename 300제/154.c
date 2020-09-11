//파일을 읽거나 쓸 때 에러 발생 유무를 확인하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int ch;

	fopen_s(&fp, "file4.txt", "r");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		while (!feof(fp)) {
			ch = fgetc(fp);
			if (ferror(fp)) {
				puts("파일을 읽는 중에 에러가 발생하였습니다.");
			}
			printf("읽은 문자 : %c\n", ch);
		}
		fclose(fp);
	}
}
//int ferror(FILE* stream);
//파일을 읽거나 쓸 때 에러가 발생하였는지의 여부를 확인하기 위해 사용합니다.
//에러가 있는 경우 0이 아닌 값을 반환합니다.
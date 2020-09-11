//137에서 지정한 문자를 읽어서 화면에 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int ch;

	fopen_s(&fp, "file.txt", "r");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		ch = fgetc(fp);
		printf("읽은 문자 : %c\n", ch);
		fclose(fp);
	}
}
//int fgetc(FILE* stream);
//steam은 개방된 파일의 포인터입니다.
//만약 문자를 읽지 못했다면, ch의 값은 EOF(-1)가 반환됩니다.
//파일이 다른 프로그램에 의해 잠겨져 있는 경우 정상적으로 개방될 수 없습니다.
//그런 경우에는 _access()함수를 사용하여 파일을 사용할 수 있는지 여부를 확인해야 합니다.
/*
#include <stdio.h>
#include <io.h>

void main(void){
	char* path="file.txt";
	if(_access(path,6)!=0){
		printf("파일을 읽거나 쓸 수 없습니다.");
	}
}
*/
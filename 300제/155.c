//file_name.txt파일을 개방하여 한 개의 문자를 읽는 프로그램을 자성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int ch;

	fopen_s(&fp, "file_name.txt", "r");

	if (fp == NULL) {
		puts("파일 개방 에러");
	}
	else {
		ch = fgetc(fp);
		if (ferror(fp)) {
			perror("파일 읽기 에러");
		}
		fclose(fp);
	}
}
//void perror(const char* string);
//perror()함수는 파일 개방이 실패된 주 원인에 대하여 출력 메시지를 보여줍니다.
//strerror도 비슷합니다.
//perror는 내부적으로 error라는 시스템 전역변수의 값에 대하여 _sys_errlist배열의 포인터를 참조하여 에러를 출력해 줍니다.
//이 값을 직접 참조하려면,
/*
extern int errno;
extern char* _sys_errlist[];
*/
//perror는 에러를 처리하기 위해서 어떤 동작을 수행하지는 않습니다.
//처리하기 위해서는 프로그램을 종료하는 것과 같은 동작을 수행하도록 지시하는 내용을 직접해야합니다.
//프로그램이 수행하는 동작은 errno의 값과 에러의 특성을 확인하여 결정됩니다.
//전역 변수 errno를 사용하기 위해 errno.h가 필요하진 않습니다.
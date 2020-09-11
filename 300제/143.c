//file.txt파일에 문자열을 저장하고, 파일 버퍼를 비우는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file3.txt", "w+");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		fputs("대한민국", fp);
		fflush(fp);
		fclose(fp);
	}
}
//int fflush(FILE* stream);
//데이터는 파일에 저장되기 전에 임시 버퍼에 기록이 되는데, 만약 순간적으로 정전 등이 발생한다면 버퍼의 내용이
//파일에 기록되지 않습니다. 그래서, 파일 버퍼를 일정 크기만큼 채우지 않고, 즉기 파일에 저장하기 위해 사용하는 것이 fflush이다.
//fflush는 표준입출력(stdin,stdout)에서 입출력 버퍼를 비울때도 사용합니다.
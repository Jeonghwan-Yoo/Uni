//file.txt를 생성하고 "fclose() 함수"를 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file5.txt", "w+");

	fputs("fclose() 함수",fp);
	fclose(fp);
}
//int fclose(FILE* stream);
//반드시 닫아야 되고, 현재 실행중인 프로그램이 개방한 여러 개의 파일을 한 번에 모두 닫으려면 fcloseall() 사용.
//C드라이브에 위치한 file.txt파일을 file_1.txt로 변경하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	char* oldname = "file.txt";
	char* newname = "file_1.txt";

	if (rename(oldname, newname) != 0) {
		perror("파일명 변경 에러");
	}
	else {
		puts("파일명을 성공적으로 변경하였습니다!");
	}
}
//int rename(const char* oldname, const char* newname);
//oldname은 원래 파일명, newname은 새로 변경할 파일명.
//변경하려는 파일이 존재하지 않거나 사용중인 경우, 파일의 이름을 변경할 수 없습니다.
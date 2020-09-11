//158에서 변경된 file_1.txt파일을 삭제하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	char* filename = "file_1.txt";

	if (remove(filename)) {
		perror("파일 삭제 에러");
	}
	else {
		puts("파일을 성공적으로 삭제하였습니다!");
	}
}
//int remove(const char* path);
//path는 삭제할 파일의 경로 및 이름
//파일이 없거나 사용중인 경우 또는 읽기 전용 파일은 삭제할 수 없습니다.
//233에서 생성한 file.txt를 c:\temp 디렉터리로 이동하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	char* filename = "file6.txt";
	char* movefile = "c:\\temp\\file6.txt";

	if (rename(filename, movefile) != 0) {
		perror("파일 이동 에러");
	}
	else {
		puts("파일이 이동되었습니다.");
	}
}
//이동경로뿐만 아니라 저장경로도 바꿀 수 있다.
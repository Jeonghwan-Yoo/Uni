//파일이 해당 경로에 존재하는지 검사하는 프로그램을 작성하세요.
#include <stdio.h>
#include <io.h>

void main(void) {
	char* path = "file.txt";

	if (_access(path, 0) == 0){
		puts("해당 경로에 파일이 존재합니다.");
	}
}
//int _access(const char* path, int mode);
//path는 검사할 파일의 경로 및 이름이며, mode는 검색할 방법을 지정
//0:파일 및 디렉터리가 존재하는지 검사하는 경우
//2:파일을 쓰기 위해 개방할 수 있는지 검사하는 경우
//4:파일을 읽기 위해 개방할 수 있는지 검사하는 경우
//6:파일을 읽기 및 쓰기 위해 개방할 수 있는지 검사하는 경우
//반환값이 0이 아니면 파일은 존재하지 않는 것.
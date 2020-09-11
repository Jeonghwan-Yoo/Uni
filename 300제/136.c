//C드라이브의 루트 폴더에 "file.txt"라는 파일을 생성하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* file;
	//file=fopen("file.txt","w+");
	fopen_s(&file, "file.txt", "w+");
	if (file == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		puts("파일이 정상적으로 생성되었습니다.");
		fclose(file);
	}
}
//FILE* fopen(const char* filename, const char* mode);
//filename은 생성 또는 개방할 파일의 이름이며, mode는 filename을 어떤 방법으로 개방할 것인지를 지정
//생성은 "w+", 읽기위해서는 "r" 
//파일의 경로를 표시할 떄는 \\으로 한다. 왜냐하면, 역슬래시가 문자열에서 문자 상수 기능을 하는 특별한 기호이기 때문이다.
//성공적으로 생성하면 file에 반환되는 핸들값은 NULL이 아니며, 실패시 NULL 반환
//파일 사용시에는 반드시 열기와 닫기(fclose)을 사용해야합니다.
//안하면, 내부적으로 사용되었던 메모리가 해제되지 않기 때문에 운영체제에 문제가 생길 수도 있습니다.
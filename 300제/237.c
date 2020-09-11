//파일에 '@', 0x00, 0x01, 0x03, 0x61을 저장하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	char buff[5];

	fopen_s(&fp, "file8.bin", "w+b");

	buff[0] = '@';
	buff[1] = 0; //NULL
	buff[2] = 0x01;
	buff[3] = 0x03;
	buff[4] = 0x61;

	if (fp != NULL) {
		fwrite(buff, 1, 5, fp);
		fclose(fp);
	}
}
//이진모드란, NULL값을 포함한 데이터를 읽고 쓰기 위한 모드입니다. 
//텍스트 모드는 NULL값을 파일에 쓸 수 없으며, 읽을 수도 없습니다.
//"r/rt","rb"는 파일을 읽을 수만 있으며, 파일이 존재하지 않는 경우에 개방은 실패
//"r+/r+t", "r+b"는 파일을 읽고/쓰고/추가할 수 있으며, 파일이 존재하지 않는 경우에 개방은 실패
//"w/wt", "wb"는 파일을 쓰고/추가할 수 있으며, 파일 존재하지 않는 경우에 개방은 실패됩니다.
//"w+/w+t", "w+b"는 파일을 읽고/쓰고/추가할 수 있으며, 파일이 존재하지 않는 경ㅇ우에 파일을 새로 생성하며,
//이미 파일이 있는 경우에는 파일의 내용을 모두 삭제한 후 개방합니다.
//"a/at", "ab"는 파일을 추가만 할 수 있으며, 파일이 존재하지 않는 경우에 파일을 새로 생성합니다.
//"a+/a+t", "a+b"는 파일을 읽고/추가만 할 수 있으며, 파일이 존재하지 않는 경우에 파일을 새로 생성합니다.
//a:추가 w:쓰기+추가 r:읽기 b:이진 t:텍스트
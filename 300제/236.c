//235에서 저장한 "우리강산"을 읽어서 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	char buff[100] = { 0, };
	int len;

	fopen_s(&fp, "file7.txt", "r");

	if (fp != NULL) {
		while (!feof(fp)) {
			len = fread(buff, 1, 9, fp);
			if (ferror(fp) || len < 9) break;
			printf("read : %d, %s", len, buff);
		}
		fclose(fp);
	}
}
//size_t fread(void* buffer, size_t size, size_t count, FILE* stream);
//buffer는 읽혀질 데이터를 저장할 버퍼, size는 블록의 크기, count는 블록의 갯수, stream은 개방된 파일의 포인터.
//한 번에 읽을 바이트 수는 size*count입니다.
//파일을 읽는 중 에러가 발생하거나, 읽은 크기가 9보다 작으면 익기를 멈춥니다.
//"rt"인 경우에 fread()는 0x0D, 0x0A를 자동으로 개행문자로 변환해서 읽으면 fwrite() 또한 그렇습니다.
//"rb"인 경우에 fread()는 0x0D, 0x0A를 개행문자가 아닌 일반 문자로 인식합니다.
//"rb"는 바이너리 모드로 파일을 개방하는 것이며, 개행문자 간의 자동 변환은 일어나지 않습니다.
//fread()도 항상 3번째 매개 변수의 값을 반환
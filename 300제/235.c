//c:\file.txt 파일에 fwrite() 함수를 사용하여 "우리강산"을 세 줄 저장하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	char* string = "우리강산\n";

	fopen_s(&fp, "file7.txt", "w+");

	if (fp != NULL) {
		fwrite(string, 1, strlen(string), fp);
		fwrite(string, 1, strlen(string), fp);
		fwrite(string, 1, strlen(string), fp);
		fclose(fp);
	}
}
//fputs()와 다른 점은 바이너리 모드로 파일을 개방시 NULL값을 쓸 수 있다는 것입니다.
//size_t wrtie(const void* buffer, size_t size, size_t count, FILE* stream);
//buffer는 쓰여질 데이터, size는 블록의 크기, count는 블록의 개수, stream은 개방된 파일의 포인터.
//한번에 쓸 바이트 수는 size*count.
//fwrite() 함수는 주로 이진 파일을 처리할 때 많이 사용됩니다. 또한, 블록 단위의 데이터를 쓰고자 할 때 유용한 함수입니다.
//fwrite()함수는 항상 3번째 매개 변수의 값을 반환합니다.
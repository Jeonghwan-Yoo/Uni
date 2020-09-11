//148에서 작성된 file.txt파일의 길이를 구하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file4.txt", "r");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		fseek(fp, 0L, SEEK_END);
		printf("파일의 길이 : %d\n", ftell(fp)); //5
		fclose(fp);
	}
}
//파일의 길이를 구하기 위해서는 맨끝으로 이동후 ftell하면 된다.
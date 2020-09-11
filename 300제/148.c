//파일명 "file.txt"를 생성하고 "abcde"를 출력하세요. 그리고 파일 포인터를 그 만큼 감소하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;

	fopen_s(&fp, "file4.txt", "w+");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		fputs("abcde", fp);
		printf("파일의 포인터의 위치 : %d\n", ftell(fp)); //5
		fseek(fp, -2L, SEEK_CUR);
		printf("파일의 포인터의 위치 : %d\n", ftell(fp)); //3
		fclose(fp);
	}
}
//fseek함수를 사용시 현재의 개방 모드가 추가모드("a")라면 fseek함수를 사용한 위치는 이동될 수 없습니다.
//이동되지 않기 때문에, 항상 파일의 끝에만 추가됩니다.
//"a+"(추가 및 읽기)로 개방된 파일에 대하여 fseek함수를 사용 시 파일을 읽기 위해 fseek를 사용할 수는 있지만 쓸수는 없습니다.
//즉, 추가모드가 있으면 파일의 끝에만 쓸 수 있다.
//SEEK_SET=0, SEEK_CUR=1, SEEK_END=2
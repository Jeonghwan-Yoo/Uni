//파일을 읽다가 파일의 끝인지, 아닌지 검사하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	FILE* fp;
	int ch;

	fopen_s(&fp, "file4.txt", "r");

	if (fp == NULL) {
		puts("파일을 생성할 수 없습니다.");
	}
	else {
		while (!feof(fp)) {
			ch = fgetc(fp);
			printf("읽은 문자 : %c\n", ch);
		}
		fclose(fp);
	}
}
//int feof(FILE* stream);
//*stream은 파일을 열 때 fopen()이 돌려주는 FILE포인터입니다.
//feof()는 파일 stream의 마지막에 도달하지 않았다면 0을 돌려주고 도달하면 0이 아닌 값을 돌려줍니다.
//파일의 끝에 도달했다는 것을 확인하면, 더 이상 읽을 데이터가 없으므로 읽기를 멈추어야 합니다.
//파일 포인터는 fgetc, fputc, fgets, fputs, fprintf, fscanf함수를 사용할 때마다 자동으로 증가합니다.
//마지막에는 읽은 문자가 없는데, 이것은 fgetc()함수가 파일 끝을 만났기 때문에 아무 문자도 읽혀지지 않았기 때문입니다.
/*
while(!feof(fp)){
	ch=fgetc(fp);
	if(feof(fp)) break;
	printf("읽은 문자 : %c\n", ch);
}
*/
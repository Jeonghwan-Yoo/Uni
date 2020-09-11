//년/월/일 시:분:초를 파일에 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>
#pragma warning(disable:4996)

void main(void) {
	FILE* fp;
	char buff[200];
	time_t now;
	struct tm t;

	fopen_s(&fp, "file11.txt", "w+");

	if (fp == NULL) {
		perror("파일 쓰기 개방 에러");
		_fcloseall();
		return;
	}

	now = time(NULL); //세계 표준시
	t = *localtime(&now); //한국 표준시로 변환.
	sprintf(buff, "%d/%d/%d %d:%d:%d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);

	fputs(buff, fp);
	fcloseall();

	puts(buff);
	puts("시간을 file11.txt에 저장하였습니다.");
}
//시간 구할 때는 두가지 방법
//1. now=time(NULL);
//2. time(&now);
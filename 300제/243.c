//242에서 사용한 파일에서 "대한민국"을 "한국"으로 교체하여 저장하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable:4996)

void main(void) {
	FILE* fpR, *fpW;
	char buff[200];
	char *pbuf, *dup;
	int len, pos1, pos2;

	fopen_s(&fpR, "file10.txt", "r");

	if (fpR == NULL) {
		perror("파일 읽기 개방 에러");
		return;
	}
	
	fopen_s(&fpW, "file_change.txt", "w+");

	if (fpW == NULL) {
		perror("파일 쓰기 개방 에러");
		fcloseall();
		return;
	}
	while (!feof(fpR)) {
		fgets(buff, 200, fpR);

		pbuf = strstr(buff, "대한민국");

		if (pbuf) {
			len = strlen(buff); //읽은 문자열의 길이
			pos1 = pbuf - buff; //대한민국이 검색된 위치

			dup = strdup(buff); //버퍼 문자열을 하나 더 생성.
			strnset(&buff[pos1], 0, len - pos1); //대한민국을 0으로 채웁니다.
			strcat(buff, "한국"); //한국을 추가합니다
			
			pos1 = pbuf - buff + strlen("대한민국"); //대한민국 이후의 위치를 계산합니다.
			pos2 = pbuf - buff + strlen("한국"); //대한민국 이전의 위치에 한국을 추가한 후의 위치를 계산합니다.

			strcpy(&buff[pos2], &dup[pos1]); //한국이 추가된 버퍼에 대한민국 이후의 문자열을 복사합니다.
			free(dup); //메모리 해제.
		}
		if (!feof(fpR)) fputs(buff, fpW);
	}
	fcloseall();
	puts("대한민국을 한국으로 모두 교체하였습니다.");
}
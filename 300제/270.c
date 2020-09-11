//269에서 작성된 addrlist.txt 파일을 읽어들여 출력하는 프로그램을 작성하세요.
#include <stdio.h> //printf, fopen, fwrite, fclose

#define ADDRFILE "addrlist.txt"

typedef struct tagLinkedList {
	char name[30]; //이름
	char tel[30]; //전화
	char addr[100]; //주소

	struct tagLinkedList *prev;
	struct tagLinkedList *next;
}ADDR;

void main(void) {
	ADDR addr;
	FILE *fp;

	fopen_s(&fp, ADDRFILE, "rb");

	if (fp == NULL) {
		perror("파일 개방 에러");
		return;
	}

	while (!feof(fp)) {
		fread(&addr, 1, sizeof(ADDR), fp);
		if (ferror(fp)) {
			fclose(fp);
			perror("파일 읽기 에러");
			return;
		}
		if (feof(fp)) break;

		printf("이름 : %s\n", addr.name);
		printf("전화 : %s\n", addr.tel);
		printf("주소 : %s\n", addr.addr);
	}
	fclose(fp);
}
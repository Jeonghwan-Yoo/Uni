//269에서 생성한 addrlist.txt 파일의 주소 데이터를 이중 링크드 리스트로 읽고, 주소를 수정하는 프로그램을 작성하세요.
#include <stdio.h> //printf, puts, fopen, frwite, fclose, getchar
#include <malloc.h> //malloc, free
#include <string.h> //strcpy, strstr
#pragma warning(disable:4996)

#define ADDRFILE "addrlist.txt"

typedef struct tagLinkedList {
	char name[30]; //이름
	char tel[30]; //전화
	char addr[100]; //주소

	struct tagLinkedList *prev;
	struct tagLinkedList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;
ADDR *g_pFind;

int add_list(const ADDR *addr) {
	ADDR *plocal;

	//g_pAddrHead가 초기화되지 않은 경우, 한 번만 실행됩니다.
	if (g_pAddrHead == NULL) {
		g_pAddrHead = malloc(sizeof(ADDR)); //ADDR 구조체 할당
		if (g_pAddrHead == NULL) {
			return 0;
		}

		g_pAddrHead->prev = NULL; //처음에는 반드시 NULL로 초기화
		g_pAddrHead->next = NULL; //처음에는 반드시 NULL로 초기화
	}
	else { //g_pAddrHead가 초기화된 후 계속 실행됩니다.
		plocal = malloc(sizeof(ADDR)); //ADDR 구조체 할당

		if (plocal == NULL) {
			return 0;
		}

		g_pAddrHead->next = plocal; //다음 리스트를 지정
		plocal->prev = g_pAddrHead; //이전 리스트를 지정
		g_pAddrHead = plocal; //현재 리스트로 plocal을 지정
		g_pAddrHead->next = NULL; //다음 리스트를 NULL로 지정
	}
	strcpy(g_pAddrHead->name, addr->name);
	strcpy(g_pAddrHead->tel, addr->tel);
	strcpy(g_pAddrHead->addr, addr->addr);

	return 1;
}
void get_addrlist(void) {
	ADDR addr;
	FILE *fp;

	fp = fopen(ADDRFILE, "rb");

	if (fp == NULL) {
		perror("파일 개방 에러");
		return;
	}
	while (!feof(fp)) {
		fread(&addr, sizeof(ADDR), 1, fp);

		if (ferror(fp)) {
			fclose(fp);
			perror("파일 읽기 에러");
			return;
		}
		if (feof(fp)) break;

		if (add_list(&addr) == 0) {
			printf("주소 데이터를 링크드 리스트에 추가할 수 없습니다.\n");
		}
	}
	fclose(fp);
}
void SetHeadPosition(void) {
	if (g_pAddrHead == NULL) return;

	while(g_pAddrHead->prev) {
		g_pAddrHead = g_pAddrHead->prev;
	}
}
int find_list(const char *name) {
	ADDR *plocal;

	SetHeadPosition(); //g_pAddrHead를 첫 주소 데이터를 가리키도록 지정

	plocal = g_pAddrHead;

	while (plocal) {
		if (strstr(plocal->name, name)) { //이름을 검색
			puts(plocal->name);
			puts(plocal->tel);
			printf("%s\n\n", plocal->addr);
			g_pFind = plocal;
			return 1;
		}
		plocal = plocal->next;
	}
	printf("\n%s을  찾을 수 없습니다.\n\n", name);

	return 0;
}
void remove_list(void) {
	ADDR *plocal;
	FILE *fp;

	if (g_pAddrHead == NULL) return;

	fp = fopen(ADDRFILE, "w+b");

	if (fp == NULL) {
		perror("파일 개방 에러");
	}

	SetHeadPosition();

	//한 개씩 메모리 해제
	while (g_pAddrHead) {
		plocal = g_pAddrHead->next;

		if (fp) fwrite(g_pAddrHead, 1, sizeof(ADDR), fp);

		free(g_pAddrHead);

		g_pAddrHead = plocal;
	}

	g_pAddrHead = NULL; //재사용하기 위한 초기화

	if (fp) fclose(fp);
}
void main(void) {
	char name[30], addr[100];
	int ch;

	get_addrlist();

	puts("검색할 이름을 입력하세요");

	while (1) {
		printf("이름 : ");
		gets(name);
		if (strlen(name) == 0) break;
		if (find_list(name) == 1) {
			printf("%s의 주소를 수정하시겠습니까 (y/n)?", name);
			ch = getchar();
			while (getchar() != '\n'); //fflush(stdin)과 같은기능 보안에서 밀림.
			if (ch == 'Y' || ch == 'y') {
				puts("수정할 주소를 입력하세요");
				printf("주소 : ");
				gets(addr);
				strcpy(g_pFind->addr, addr);
			}
		}
	}
	remove_list();
}
//269에서 생성한 addrlist.txt 파일의 주소 데이터를 이중 링크드 리스트로 읽고, 주소를 삭제하는 프로그램을 작성하세요.
#include <stdio.h> //printf, puts, fopen, fwrite, fclose, getchar
#include <malloc.h> //malloc, free
#include <string.h> //strcpy, strstr
#pragma warning(disable:4996)

#define ADDRFILE "addrlist.txt"

typedef struct tagLinkedList {
	char name[30];
	char tel[30];
	char addr[100];

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

	while (g_pAddrHead->prev) {
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
	}
	printf("\n%s을 찾을 수 없습니다.\n\n", name);
	return 0;
}

void delete_list(void) {
	ADDR *plocal;

	if (g_pFind->prev == NULL) {
		if (g_pFind->next == NULL) { //1개
			free(g_pFind);
			g_pAddrHead = NULL;
		}
		else { //맨 앞
			plocal = g_pFind->next;
			free(g_pFind);
			plocal->prev = NULL;
			g_pAddrHead = plocal;
		}
	}
	else if (g_pFind->next == NULL) { //맨 뒤
		plocal = g_pFind->prev;
		free(g_pFind);
		plocal->next = NULL;
		g_pAddrHead = plocal;
	}
	else { //중간
		plocal = g_pFind->prev;
		plocal->next = g_pFind->next;

		plocal = g_pFind->next;
		plocal->prev = g_pFind->prev;

		free(g_pFind);
		g_pAddrHead = plocal;
	}
	printf("검색된 주소 데이터를 삭제하였습니다.\n\n");
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
	char name[30];
	int ch;

	get_addrlist();

	puts("삭제할 이름을 입력하세요.");

	while (1) {
		printf("삭제할 이름 : ");
		gets(name);
		if (strlen(name) == 0) break;
		if (find_list(name) == 1) {
			printf("%s를 삭제하시겠습니까(y/n)?", name);
			ch = getchar();
			while (getchar() != '\n');
			if (ch == 'Y' || ch == 'y') {
				delete_list();
			}
		}
	}
	remove_list();
}
//주소 데이터를 삭제한 링크드 리스트의 주소 데이터를 파일에 저장합니다.
//삭제하려면
//첫 링크를 삭제하기 위해서 헤드 포인터가 링크드 리스트에서 두 번째 링크를 가리키도록 설정.
//마지막 링크를 삭제하기 위해서 마지막 바로 앞의 링크의 next포인터를 NULL로 설정.
//삭제되는 바로 앞 링크의 next 포인터를 삭제되는 바로 다음 링크를 가리키도록 설정.
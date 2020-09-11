//주소 데이터를 입력받는 프로그램을 작서앟고, 입력된 데이터를 파일로 저장하십시오.
#include <stdio.h> //printf,puts,fopen,fwrite, fclose
#include <malloc.h> //malloc, free
#include <string.h> //strcpy
#pragma warning(disable:4996)

typedef struct tagLinkedList {
	char name[30]; //이름
	char tel[30]; //전화
	char addr[100]; //주소

	struct tagLinkedList *prev;
	struct tagLinkedList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;

int add_list(ADDR *addr) {
	ADDR *plocal;
	FILE *fp;

	fp = fopen("addrlist.txt", "a+b");
	if (fp == NULL) {
		perror("파일 개방 에러");
		return 0;
	}

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

	fwrite(addr, 1, sizeof(ADDR), fp);

	fclose(fp);

	return 1;
}

void print_list(void) {
	int count = 1;
	ADDR *plocal;

	if (g_pAddrHead == NULL) return;

	plocal = g_pAddrHead;

	//plocal 리스트의 맨 처음으로 이동
	while (plocal->prev) {
		plocal = plocal->prev;
	}
	//한 개씩 출력
	while (plocal) {
		printf("No. %d\n", count++);
		puts(plocal->name);
		puts(plocal->tel);
		printf("%s\n\n", plocal->addr);

		plocal = plocal->next;
	}
}

void remove_list(void) {
	ADDR *plocal;

	if (g_pAddrHead == NULL) return;

	//PA를 리스트의 맨 처음으로 이동
	while (g_pAddrHead->prev) {
		g_pAddrHead = g_pAddrHead -> prev;
	}

	//한 개씩 메모리 해제
	while (g_pAddrHead) {
		plocal = g_pAddrHead->next;
		free(g_pAddrHead);
		g_pAddrHead = plocal;
	}

	g_pAddrHead = NULL; //재사용을 하기 위한 초기화
}

void main(void) {
	ADDR addr;
	puts("추가할 주소 데이터를 입력하세요.");
	puts("프로그램을 종료하려면 엔터키를 치십시오.");

	while (1) {
		memset(&addr, 0, sizeof(ADDR));

		printf("이름 : ");
		gets(addr.name);

		if (strlen(addr.name) == 0) break;

		printf("전화 : ");
		gets(addr.tel);

		printf("주소 : ");
		gets(addr.addr);

		if (add_list(&addr)) {
			printf("\n주소록에 데이터가 추가되었습니다.\n\n");
		}
	}
	print_list();
	remove_list();
}
//링크드 리스트의 시작부분에 링크 추가하기
//1. malloc()을 사용하여 메모리 공간을 할당하며 구조체형 변수를 생성합니다.
//2. 새로운 링크의 next 포인터를 헤드 포인터의 현재 값으로 설정합니다.
//이 값은 링크드 리스트가 비어 있다면 NULL이 될 것이고, 그렇지 않다면 현재 첫 번째 링크의 주소가 될 것입니다.
//3. 헤드 포인터가 새로운 요소를 가리키게 됩니다.
//링크드 리스트의 마지막에 링크 추가하기
//헤드 포인터에서 시작하고 마지막 링크를 찾을 때까지 링크드 리스트를 통해 차례대로 진행해야 합니다. 마지막링크를 발견하면
//1. malloc()을 사용하여 메로리 공간을 할당하며 구조체형 변수를 생성합니다.
//2. 마지막 링크의 next 포인터가 새로운 링크를 가리키게 설정합니다. 새로운 링크의 주소는 malloc()에 의해 복귀됩니다.
//3. 새로운 링크가 링크드 리스트에서 마지막 항목이라는 것을 표시하기 위해 새로운 링크의 next 포인터를 NULL로 설정합니다.
//순환 이중 링크드 리스트는 맨 처음 prev가 맨 뒤의 리스트 값을 가지며, 맨 뒤의 next는 맨처음 리스트의 값을 가집니다.
//가장 중요한 점은
//링크드 리스트의 크기는 프로그램이 실행되는 동안 증가하거나 감소할 수 있고, 미리 정의할 필요가 없습니다.
//링크드 리스트는 어느 곳에든지 새로운 링크를 쉽게 추가하고, 기존의 링크를 삭제할 수 있으므로 정렬된 순서로 유지하기 쉽다.
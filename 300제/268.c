//5명의 이름, 전화번호 그리고 주소를 저장하고 출력하는 프로그램을 이중 링크드 리스트를 사용하여 작성하세요.
#include <stdio.h> //printf, puts
#include <malloc.h> //malloc, free
#include <string.h> //strcpy
#pragma warning(disable:4996)

int add_list(char *name, char *tel, char *addr);
void print_list(void);
void remove_list(void);

typedef struct tagLinkedList {
	char name[30]; //이름
	char tel[30]; //전화번호
	char addr[100]; //주소

	struct tagLinkedList *prev;
	struct tagLinkedList *next;
}ADDR;

ADDR *g_pAddrHead = NULL;

void main(void) {
	add_list("홍길동", "1111", "서울특별시 종로구");
	add_list("홍길순", "2222", "서울특별시 강서구");
	add_list("Mr.Kim", "3333", "서울특별시 구로구");
	add_list("김C", "4444", "서울특별시 강동구");
	add_list("최C", "5555", "대전광역시 동구");

	print_list();
	remove_list();
}

int add_list(char *name, char *tel, char *addr) {
	ADDR *plocal;

	//g_pAddrHead가 초기화되지 않은 경우, 한 번만 실행됩니ㅏㄷ.
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

		g_pAddrHead->next = plocal; //다음 리스트를 지정.
		plocal->prev = g_pAddrHead; //이전 리스트를 지정.
		g_pAddrHead = plocal; //현재 리스트로 plocal을 지정
		g_pAddrHead->next = NULL; //다음 리스트를 NULL로 지정
	}

	strcpy(g_pAddrHead->name, name); //새로 할당된 구조체에 이름 복사
	strcpy(g_pAddrHead->tel, tel); //새로 할당된 구조체에 전화 복사
	strcpy(g_pAddrHead->addr, addr); //새로 할당된 구조체에 주소 복사
}

void print_list(void) {
	int count = 1;
	ADDR *plocal;

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

	//PA를 리스트의 맨 처음으로 이동
	while (g_pAddrHead->prev) {
		g_pAddrHead = g_pAddrHead->prev;
	}

	//한 개씩 메모리 해제
	while (g_pAddrHead) {
		plocal = g_pAddrHead->next;

		free(g_pAddrHead);
		
		g_pAddrHead = plocal;
	}
	g_pAddrHead = NULL; //재사용을 하기 위한 초기화.
}
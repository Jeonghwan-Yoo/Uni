//5명의 이름, 전화번호 그리고 주소를 저장하고 출력하는 프로그램을 단일 링크드 리스트를 사용하여 작성하세요.
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

int add_list(char *name, char* tel, char *addr) {
	ADDR *plocal, *pn = g_pAddrHead; //pn은 링크드 리스트의 마지막 데이터를 찾기 위해 사용됩니다.

	//g_pAddrHead가 초기화되지 않은 경우, 한 번만 실행됩니다.
	if (g_pAddrHead == NULL) {
		g_pAddrHead = malloc(sizeof(ADDR)); //구조체 할당

		if (g_pAddrHead == NULL) {
			return 0;
		}

		g_pAddrHead->next = NULL; //처음에는 반드시 NULL로 초기화
		plocal = g_pAddrHead;
	}
	else {
		plocal = malloc(sizeof(ADDR)); //ADDR 구조체 할당

		if (plocal == NULL) {
			return 0;
		}
		while (pn->next) {
			pn = pn->next; //첫 데이터에서 마지막 데이터로 가는 코드.
		}
		pn->next = plocal; //다음 리스트를 지정
		plocal->next = NULL; //다음 리스트를 NULL로 지정
	}

	strcpy(plocal->name, name); //새로 할당된 구조체에 이름 복사.
	strcpy(plocal->tel, tel); //새로 할당된 구조체에 전화 복사.
	strcpy(plocal->addr, addr); //새로 할당된 구조체에 주소 복사.

	return 1;
}

void print_list(void) {
	int count = 1;
	ADDR *plist;

	plist = g_pAddrHead;

	//한 개씩 출력
	while (plist) {
		printf("No. %d\n", count++);
		puts(plist->name);
		puts(plist->tel);
		printf("%s\n\n", plist->addr);

		plist = plist->next;
	}
}

void remove_list(void) {
	ADDR *plocal;

	//한 개씩 메모리 해제
	while (g_pAddrHead) {
		plocal = g_pAddrHead->next; //g_pAddrHead가 가리키는 다음주소 데이터의 값을 미리 plocal에 저장.

		free(g_pAddrHead); //g_pAddrHead가 가리키는 주소 데이터를 해제.

		g_pAddrHead = plocal; //g_pAddrHead->next 값을 다시 받아옵니다.
	}
}
//링크드 리스트는 데이터 부분과 링크부분으로 구성되며, 데이터의 저장/검색/삭제 등이 용이한 자료의 저장 방법.
//각각의 링크는 다음 데이터가 저장된 번지를 가리키고 있습니다.

//Hashing
//기존에는
//문자열를 저장할 때 인덱스가 정해져있으면 특정 문자열을 찾으려면 처음부터 해야된다.
//정렬이 되있더라도 쉽지 않다.
//하지만, Hashing으로 한번에 찾을 수 있다.
//배열에 넣을 때 아예 계산을 해서 배열에 집어넣는다.
//사용자가 지정하기 나름이다.
//글자수를 해당 인덱스에 저장할 수도 있다.
//알파벳마다 숫자를 부여해서 인덱스에 저장할 수도 있다.
//잘못 만들면 2개가 들어갈지도 모르니 주의.

//chaining.
//잘되면 각칸마다 1:1 매칭될 수도있지만 거의 불가능하다.
//가끔 한칸에 복수개가 들어갈 수 있는데
//그것을 처리하기 위한 방법=>SLL.
//처음것은 그냥 넣고 겹치게 되면 SLL.
//탐색할 때는 chain을 따라가 찾는다.

//hashing은 hashing function이 있어야 한다.
//chaining은 복수개 있을 때 SLL로 방지.
//bucket(index와 같은 의미)
//collision은 한곳에 2개가 들어간 경우. -> chaining.
//lineaer probing은 collision이 발생했을 때, 그 다음칸이 비어있을 때 채워넣는다.
//즉, collision->chainig or linear probing.
//loading density은 현재 채워진 수/전체 수.
//loading density가 낮으면 collision이 적지만 공간 낭비가 많다.
//높으면 collision 확률이 높아지지만 효율적으로 이용 중이다.

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct student {
	char name[20];
	int stno;
	unsigned short age;
	struct student *next;
};

typedef struct student STUDENT;

#define HASHTABLE_SZ 30
STUDENT *hashTable[HASHTABLE_SZ];

int hashFunction(char *str) {
	//문자값을 모두 더한다.
	int sum = 0;
	int len = strlen(str);
	int i;
	for (i = 0;i < len;i++) {
		sum += str[i];
	}
	//%HASHTABLE_SZ
	return (sum%HASHTABLE_SZ);
}

void addToHashTable(char *name, int stno, unsigned short age) {
	STUDENT *cur = (STUDENT*)malloc(sizeof(STUDENT));
	int idx;
	strcpy_s(cur->name, sizeof(name)*3 , name);
	cur->stno = stno;
	cur->age = age;
	cur->next = 0;
	idx = hashFunction(name); //나머지 값이 인덱스

	if (hashTable[idx] == 0) {
		hashTable[idx] = cur;
		return;
	}
	else { //collision
		STUDENT *temp = hashTable[idx];
		while (temp->next != 0) {
			temp = temp->next;
		}
		temp->next = cur;
		return;
	}
}

void searchInTheHash(char *name) {
	STUDENT *cur;
	//찾고
	int idx;
	idx = hashFunction(name);

	cur = hashTable[idx];

	if (cur == 0) {
		return;
	}
	else {
		while (strcmp(cur->name, name) != 0) {
			cur = cur->next;
			if (cur == 0) {
				return;
			}
		}
	}
	//데이터를 출력
	printf("%s %d %d\n", cur->name, cur->stno, cur->age);
}

void main(void) {
	addToHashTable((char*)"박철수", 200, 19);
	addToHashTable((char*)"김철수", 201, 20);
	addToHashTable((char*)"이철수", 202, 19);
	addToHashTable((char*)"오철수", 203, 18);
	addToHashTable((char*)"송철수", 204, 19);

	searchInTheHash((char*)"이철수");
	searchInTheHash((char*)"송철수");
}
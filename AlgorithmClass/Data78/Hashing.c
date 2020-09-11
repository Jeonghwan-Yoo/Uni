//Hashing
//��������
//���ڿ��� ������ �� �ε����� ������������ Ư�� ���ڿ��� ã������ ó������ �ؾߵȴ�.
//������ ���ִ��� ���� �ʴ�.
//������, Hashing���� �ѹ��� ã�� �� �ִ�.
//�迭�� ���� �� �ƿ� ����� �ؼ� �迭�� ����ִ´�.
//����ڰ� �����ϱ� �����̴�.
//���ڼ��� �ش� �ε����� ������ ���� �ִ�.
//���ĺ����� ���ڸ� �ο��ؼ� �ε����� ������ ���� �ִ�.
//�߸� ����� 2���� ������ �𸣴� ����.

//chaining.
//�ߵǸ� ��ĭ���� 1:1 ��Ī�� ���������� ���� �Ұ����ϴ�.
//���� ��ĭ�� �������� �� �� �ִµ�
//�װ��� ó���ϱ� ���� ���=>SLL.
//ó������ �׳� �ְ� ��ġ�� �Ǹ� SLL.
//Ž���� ���� chain�� ���� ã�´�.

//hashing�� hashing function�� �־�� �Ѵ�.
//chaining�� ������ ���� �� SLL�� ����.
//bucket(index�� ���� �ǹ�)
//collision�� �Ѱ��� 2���� �� ���. -> chaining.
//lineaer probing�� collision�� �߻����� ��, �� ����ĭ�� ������� �� ä���ִ´�.
//��, collision->chainig or linear probing.
//loading density�� ���� ä���� ��/��ü ��.
//loading density�� ������ collision�� ������ ���� ���� ����.
//������ collision Ȯ���� ���������� ȿ�������� �̿� ���̴�.

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
	//���ڰ��� ��� ���Ѵ�.
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
	idx = hashFunction(name); //������ ���� �ε���

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
	//ã��
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
	//�����͸� ���
	printf("%s %d %d\n", cur->name, cur->stno, cur->age);
}

void main(void) {
	addToHashTable((char*)"��ö��", 200, 19);
	addToHashTable((char*)"��ö��", 201, 20);
	addToHashTable((char*)"��ö��", 202, 19);
	addToHashTable((char*)"��ö��", 203, 18);
	addToHashTable((char*)"��ö��", 204, 19);

	searchInTheHash((char*)"��ö��");
	searchInTheHash((char*)"��ö��");
}
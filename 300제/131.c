//������ ������ �迭�� 3�� �����ϰ�, �� ���� �Լ��� ���� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>

void print(char** ppanimal);

void main(void) {
	char* animal[3];

	animal[0] = "ȣ����";
	animal[1] = "����";
	animal[2] = "�䳢";

	print(animal);
}

void print(char** ppanimal) {
	puts(ppanimal[0]);
	puts(ppanimal[1]);
	puts(ppanimal[2]);
}
//��� ������ ��� ���α׷��� ������ �� ������, ���� ������ �߻��� ���ɼ��� ���� �����ϴ�.
//�������� �����ʹ� �ַ� ������ ������ �迭�� �ٷ� �� ���� ����մϴ�.
//API(Application Progamming Interface)�� ���� ����ϰ� �ִ� �ü������ ���� ���α׷��� ����� ���� ���̺귯��.
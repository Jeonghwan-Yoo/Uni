//��Ʈ ������ ����Ͽ� �ҹ��ڸ� �빮�ڷ� ��ȯ�ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>

void main(void) {
	char string[] = "abcdefghijklmnopqrstuvwxyz";
	unsigned i, len;

	puts(string);

	len = strlen(string); //���ڿ��� ����

	for (i = 0;i < len;i++) {
		string[i] = string[i] & 0xDF; //0xDF�� 2������ 1101 1111
	}
	puts(string);
}
//a�� 0110 0001 A�� 0100 0001�̹Ƿ� 32��ŭ ���̳��� 3��° ��Ʈ�� 0���� ���ָ� �Ǳ⶧����
//1101 1111�� AND�� ����ũ���ָ� �ȴ�.
//�빮�ڸ� �ҹ��ڷ� �ٲٷ���, 'A'|0x20ó�� �ϸ� �˴ϴ�.
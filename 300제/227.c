//���ڿ� "boy is man"���� �� �ܾ��� ù ���ڸ� �빮�ڷ� ��ȯ�Ͽ� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(void) {
	char buff[] = "boy is man", *pos = buff;

	while (pos) {
		if (isalpha(buff[0]) && pos == buff) {
			buff[0] &= 0xDF;
			pos++;
		}
		else if (pos = strpbrk(pos, " ")) { //���� ã����,
			*++pos &= 0xDF; //�� ���������� �빮�ڿ��� �Ѵ�.
		}
	}
	printf(buff);
}
//else if���� ��ȣ �Ѱ��� ������ pos�� �����ؼ� �װ��� �Ǵ��ϱ� ����.
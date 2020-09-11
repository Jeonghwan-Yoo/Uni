//memmove() �Լ��� ���� �����ϴ� My_memmove() �Լ��� ����� ������.
#include <stdio.h>
#include <stdlib.h>

char s[20] = "1234567890";

void* My_memmove(void* dst, const void* src, unsigned int count);

void main(void) {
	puts(s);
	My_memmove(s + 4, s + 2, 6);
	puts(s);
}

void* My_memmove(void* dst, const void* src, unsigned int count) {
	void* ret = dst;

	//�Ȱ�ġ�°��(ī�ǵ� ���� ��ġ�� ���̰ų�, ī���� �ͺ��� �ָ�������) 
	if (dst <= src||(char*)dst>=(char*)src+count) {
		while (count--) {
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	//��ġ�°��
	else {
		dst = (char*)dst + count-1; //index�� 0������ �����̹Ƿ�.
		src = (char*)src + count-1;

		while (count--) {
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;
		}
	}

	return ret;
}
//dst�� src�� ������ ���������� Ȯ���ϰ� �������� �ڿ������� �����Ѵ�.
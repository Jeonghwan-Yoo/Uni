#include <stdio.h>

int a[6]; //length of this array is 6.

int main(void) {
	for (int i = 0;i < 6;i++) {
		printf("a[%d]'s address is %0x\n", i, &a[i]); //0x is for Hexadecimal. x���ϸ� 0x���� 16����.
	}
	return 0;
}
#include <stdio.h>

char a[6];

int main(void) {
	for (int i = 0;i < 6;i++) {
		printf("a[%d]'s address is %d\n", i, &a[i]);
	}
	return 0;
}
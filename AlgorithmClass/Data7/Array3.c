#include <stdio.h>

#define SZ 2
char a[SZ][SZ][SZ]; //3d array.

int main(void) {
	for (int i = 0;i < SZ;i++) {
		for (int j = 0;j < SZ;j++) {
			for (int k = 0;k < SZ;k++) {
				printf("a[%d][%d][%d]'s address is %d\n", i, j, k, &a[i][j][k]); //the difference of address is only one from character type.
			}
		}
	}
	return 0;
}
//정수형 변수 i,j,k를 정의하고 각각을 1,2,7로 초기화하세요. 그리고 i의 값이 1이고 j의 값이 2일 때, k의 값이 3인
//경우와 k의 값이 4인 경우, 그리고 k의 값이 5인 경우에 따라 각각 i,j,k를 출력하고, k의 값이 3,4,5가 아닌 경우
//i,j,k의 값을 출력하는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	int i = 1;
	int j = 2;
	int k = 7;

	if (i == 1) {
		if (j == 2) {
			if (k == 3) {
				printf("i=1, j=2, k=3입니다.");
			}
			else if(k==4) {
				printf("i=1, j=2, k=4입니다.");
			}
			else if (k == 5) {
				printf("i=1, j=2, k=5입니다.");
			}
			else {
				printf("i=1, j=2, k=%d입니다.",k);
			}
		}
	}
}
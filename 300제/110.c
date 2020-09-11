//문자열 "koxea"를 1차원 배열에 저장하고, 배열의 3번째 값을 'r'로 바꾸어 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	char one[10] = "Koxea";

	puts(one);
	one[2] = 'r';
	puts(one);

	printf("one[0]=%3d, %c\n", one[0], one[0]);
	printf("one[1]=%3d, %c\n", one[1], one[1]);
	printf("one[2]=%3d, %c\n", one[2], one[2]);
	printf("one[3]=%3d, %c\n", one[3], one[3]);
	printf("one[4]=%3d, %c\n", one[4], one[4]);
	printf("one[5]=%3d, %c\n", one[5], one[5]);
}
//문자열의 끝임을 나타내기 위해서 자동으로 널이 삽입.
//char one[]="Koxea"; 처럼 문자열로 초기화할 때는 배열 요소를 생략하는 경우가 많습니다. 자동으로 6이됩니다.(5+널)
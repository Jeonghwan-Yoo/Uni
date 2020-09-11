//void형 포인터를 사용하여 다양한 배열을 복사하는 프로그램을 작성하세요.
#include <stdio.h>

void array_copy(void* dest, const void* src, int size);

void main(void) {
	char array1[100] = "array of char";
	char array2[100] = { 0, };
	int array3[5] = { 1,2,3,4,5 };
	int array4[5] = { 0, };

	printf("array1 : [%s]\n", array1);
	printf("array2 : [%s]\n", array2);
	printf("array3 : [%d]\n", array3[0]);
	printf("array4 : [%d]\n", array4[0]);

	array_copy(array2, array1, sizeof(array1));
	array_copy(array4, array3, sizeof(array3));

	printf("array1 : [%s]\n", array1);
	printf("array2 : [%s]\n", array2);
	printf("array3 : [%d]\n", array3[4]);
	printf("array4 : [%d]\n", array4[4]);
}

void array_copy(void*dest, const void* src, int size) {
	while (size--) {
		*(char*)dest = *(char*)src;
		((char*)dest)++; //아래 것과 같은 의미.
		src = (char*)src + 1;
	}
}
//버퍼를 1바이트씩 복사해야 하므로 (char*)이다.
//void형 포인터는 모든 데이터형의 포인터를 모두 대입받을 수 있는 반면, 포인터를 사용하려고 할 때는 반드시
//사용하려는 포인터의 데이터형으로 캐스팅해 주어야 합니다.
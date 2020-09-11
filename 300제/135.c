//프로그램 실행 시 main() 함수에서 인수로 넘어온 값을 출력하는 프로그램을 작성하세요.
#include <stdio.h>

int main(int argc, int *argv[]) {
	int i;

	printf("인수의 수:%d\n", argc);

	for (i = 0;i < argc;i++) {
		printf("argv[%d]:%s\n", i, argv[i]);
	}
}
//main함수는 반환값을 지정할 수 있으면 명령행에서 문자열을 설정하여 프로그램을 실행할 수 있습니다.
//135.exe abc 123하면 인수가 main함수에 전달됩니다. 공백으로 분리해야 합니다.
//argc는 총 전달된 인수의 수입니다.
//MFC(Microsoft Foundation Class Library)로 Windows API 함수들은 C++클래스를 사용하여, 강력한 프로그래밍을 할 수 있게.
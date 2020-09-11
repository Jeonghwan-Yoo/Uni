//scanf()함수를 사용하여 모든 데이터형의 값을 읽는 프로그램을 작성하세요.
#include <stdio.h>
#pragma warning(disable:4996)

#define scan(d,x,y) printf(#d "형(%"#x")을 입력하세요\n"); \
					scanf(#x, &y); \
					printf("scanf %"#x":"#x"\n\n", y); //하지만 왜 %가 쓰이는지는 의문

void main(void) {
	char ch = 0;
	short int si = 0;
	int i = 0;
	int o8 = 0;
	int x16 = 0;
	unsigned ui = 0;
	long l = 0;
	float f = 0;
	char s[100] = { 0, };

	scan(char, %c, ch);
	scan(short, %hd, si);
	scan(int, %d, i);
	scan(unsigned, %u, ui);
	scan(long, %d, l);
	scan(8진수, %o, o8);
	scan(16진수, %x, x16);
	scan(고정소수점, %f, f);
	scan(문자열, %s, s);

	scanf("%4d %3d", &i, &o8);
	printf("%d, %d\n", i, o8);
}
//매크로 함수가 여러 줄에 걸쳐 사용될 때는 행계속 문자(\)를 사용해야 합니다.
//%[*][width][{h|l|I64|L}]type
//%*를 사용하면, 입력값 하나를 무시하고 건너 뛸 수 있습니다.
//Executables:운영체제에 의해 동작되는 프로그램
//Libraries:다른 프로그램이 만들어질 때 연결되도록 제작된 코드
//Dynamic Linked Libraries(DLL):프로그램이 실행되고 있을 때 연결될 수 있도록 제작된 코드
//Controls:다른 프로그램의 생성에 관여할 수 있도록 제작된 코드
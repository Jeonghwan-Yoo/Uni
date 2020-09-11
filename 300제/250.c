//2007년 크리스마스의 요일을 구하는 프로그램을 작성하세요.
#include <stdio.h>
#include <time.h>

void main(void) {
	struct tm christmas = { 0,0,0,25,12 - 1,2007 - 1900 };
	char *wday[] = { "일","월","화","수","목","금","토" };
	char buff[100];

	mktime(&christmas);

	strftime(buff, sizeof(buff), "2007년 12월 25일은 %A입니다.", &christmas);

	puts(buff);
	printf("2007년 12월 25일은 %s요일입니다.\n", wday[christmas.tm_wday]);
}
//.NET은 자바에 대항하기 위해 낸 제품. 모두 인터넷에 연결하겠다는 목적. MS에서 만듦.
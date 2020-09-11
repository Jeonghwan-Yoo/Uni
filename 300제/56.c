//"대한민국", "여름", "겨울"에 해당하는 문자열을 정의하고, 그 문자열을 출력하는 프로그램을 작성하세요.
#include <stdio.h>

#define KOREA "대한민국"
#define SUMMER "여름"

void main(void) {
	const char* winter = "겨울";

	puts(KOREA);
	puts(SUMMER);
	puts(winter);
}
//넘겨 받는 문자열이나 값을 변화시키지 않기를 바란다면 const 키워드 사용.
//문자 배열을 참조하면 바꿀 수 있음.
//자동으로 다음 줄로 개행됩니다.
//문자열을 출력하는 print() 함수를 putch() 함수를 사용하여 작성하세요.
#include <stdio.h>
#include <conio.h>

int print(char* string);

void main(void) {
	print("This is a putch function!");
}

int print(char* string) {
	int len = 0;

	while (*string != (char)NULL) {
		_putch(*string);
		string++;
		len++;
	}

	//현재 출력되고 있는 줄을 다음 줄의 첫 번째로 이동
	_putch('\r'); //캐리지 리턴
	_putch('\n'); //라인 피드

	return len;
}
//캐리지 리턴(CR):커서를 맨 앞으로
//라인피드(LF):다음 줄로 이동.
//윈도우에서는 CR LF를 둘다 써야 되고 리눅스는 LF만 써도된다. 그래서, 리눅스에서 쓴글이 깨져보일때는 CR이 없이 작성해서 그렇다.
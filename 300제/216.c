//문자열 "a12, b34, c56"을 콤마와 공백으로 분리하여 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void main(void) {
	char string[] = "a12, b34, c56";
	char* token;

	token = strtok(string, ", "); //문자열 ", "에 공백 포함
	
	while (token) {
		puts(token);
		token = strtok(NULL, ", ");
	}
}
//strtok는 최초 호출시 넘겨받은 포인터를 정적변수에 저장하고 있다가,
//이후 NULL로 인자가 들어왔을 경우, 이전 호출시 저장된 정적변수의 값을 이용해
//parsing을 진행하는 방식으로 동작합니다.
//내부에 정적메모리나 변수를 참조하는 방식은 쓰레드안정성이 보장되지 않아 멀티
//쓰레드를 이용해서 프로그램을 작성할 경우 사용하면 안된다.
//문자열형 변수 str을 정의하고, "대한민국"을 저장하는 프로그램을 작성하세요.
#include <stdio.h>

main() {
	char str[] = "대한민국"; //문자열 변수
	char *j = "I love Korea"; //문자열 상수
	
	printf("문자열형 변수 str의 값은 %s\n", str);
	printf("문자열형 변수 j의 값은 %s\n", j);
}
//하나의 문자는 한 바이트의 메모리를 사용하며, 모든 문자열의 끝은 항상 널(아스키값 0)로 종료합니다.
//변수 i를 정의하고 사용하지 않을 때 발생하는 C4101 경고 에러를 발생시키지 않도록 하는 프로그램을 작성하세요.
#include <stdio.h>

#pragma warning(disable:4101)

void main(void) {
	int i;
}
//컴파일 시 메시지를 표시하고 싶을 때
//#pragma message("COUNT가 선언되었습니다.")
//구조체를 몇 바이트 단위로 정렬할 지 컴파일에게 알립니다.
//구조체는 1,2,4,8,16바이트 단위로 정렬될 수 있습니다.
//#pragma pack(1):1바이트 단위 정렬
//#pragma pack(4):4바이트 단위 정렬
//#pragma pack(8):8바이트 단위 정렬
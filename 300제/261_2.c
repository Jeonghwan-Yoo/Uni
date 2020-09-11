//"Tue Aug 31 01:48:33 2005"와 같은 시간을 변환하려면 다음과 같이 하세요.
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

void main(void) {
	char *day[] = { "Sun","Mon","Tue","Wed","Thr","Fri","Sat" };
	char *month[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	char date[] = "Tue Aug 31 01:48:33 2005";
	//             0123456789012345678901234
	struct tm t = { 0, };
	int i;
	t.tm_year = atoi(&date[20]) - 1900;
	date[19] = 0;
	t.tm_sec = atoi(&date[17]);
	date[16] = 0;
	t.tm_min = atoi(&date[14]);
	date[13] = 0;
	t.tm_hour = atoi(&date[11]);
	date[10] = 0;
	t.tm_mday = atoi(&date[8]);
	date[7] = 0;
	for (i = 0;i < 12;i++) {
		if (stricmp(&date[4], month[i]) == 0) {
			t.tm_mon = i;
			break;
		}
	}
	mktime(&t);
	printf("struct tm 변환 후 날짜 : %4d-%02d-%02d %02d:%02d:%02d\n",
		t.tm_year + 1900, t.tm_mon + 1, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec);
}
//stricmp는 대소문자 구분안함.
//키보드로부터 3개의 정수값을 읽은 후, 합을 출력하는 프로그램을 작성하세요.
#include <stdio.h>

void main(void) {
	int count; //3회를 카운트하기 위한 변수
	int tmp; //정수값을 읽을 임시 변수
	int total = 0; //읽은 정수값을 합산하기 위한 변수

	for (count = 1;count <= 3;count++) {
		printf("%d번째 정수값을 입력한 후 Enter키를 누르세요.\n", count);

		scanf_s("%d", &tmp);

		total += tmp;

		printf("입력 값 = %d, 총 합 = %d\n", tmp, total);
	}

	printf("읽은 정수의 총 합은 %d입니다.\n", total);
}
//정수값을 입력 후 Enter키를 반드시 눌러야 합니다. tmp변수는 값이 아닌 번지를 넘겨주어야 한다. 문자값을 입력하면 음수값 반환.
//음수값인 경우, fflush(stdin); 을 사용하여 입력 버퍼를 지워주는 것이 좋습니다.
//세 개를 한 번에 하려면 scanf("%d %d %d",&tmp1,&tmp2,&tmp3);
//scanf()는 그 크기를 자동으로 맞춰주지 않습니다. 음수로 오버플로우 될 수 있다.
/* 숫자를 입력하지 않고 문자를 입력하였을 경우 i=0이 되고, scanf_s가 0을 계속 다시읽어서 무한루프에 빠진다.
int i=0;
do{
	scanf("%d",&i);
	printf("%d",i);
}while(i==0);
*/
//입력되는 내용을 받아들이는 방법을 결정하기 위해 문자열을 사용하게 됩니다. %s를 포함시켜야 합니다.
//문자열은 공백이 아닌 첫 번째 문자에서부터 시작됩니다. 
//%s를 포함시키면 입력은 빈칸, 탭, 새로운 줄문자와 같은 공백이 입력될 때, 끝나고 공백은 문자열에 포함되지 않습니다.
//%ns를 포함시키면 scanf()는 n개의 문자가 입력되거나 또는 공백이 입력될 때까지 문자열을 읽어들입니다. n은 문자의 개수.
//문자열에 하나 이상의 %s를 포함시키면 하나의 scanf()를 사용하여 여러 개의 문자열을 입력할 수도 있습니다.
/*
char s1[100],s2[100],s3[100];
scanf("%s%s%s",s1,s2,s3);
에서 January February March를 입력하면 s1은 January s2는 February s3는 March가 할당
scanf("%3s%3s%3s",s1,s2,s3);
에서 September를 입력하면 s1은 Sep s2는 tem s3는 ber가 할당.
입력 개수가 적으면 계속 대기하고, 많아서 필요없는 문자열은 키보드 버퍼 내에 남아있게 되고, 나중에 읽을 때 읽어진다.
*/
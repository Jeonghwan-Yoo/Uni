//100명의 로그인을 인증하는 서버 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>
#include <ctype.h> //isspace때문에.

#define USERFILE "userid.txt" //ID와 암호 저장.
#define WINSOCK_VERSION MAKEWORD(2,2)

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

typedef struct tagIDList {
	char uid[9];
	char pwd[9];
}IDLIST;

IDLIST id[100];

void getid(void) {
	FILE *fp;
	int i, j;
	char buff[100];

	fp = fopen(USERFILE, "r");

	for (i = 0;i < 100;i++) {
		fgets(buff, 20, fp); 
		strncpy(id[i].uid, &buff[0], 8); //사용자 id를 복사합니다. 최대 길이 8바이트.
		strncpy(id[i].pwd, &buff[8], 8);

		for (j = 7;j >= 0;j--) { //공백 제거.
			if (isspace(id[i].uid[j])) id[i].uid[j] = 0;
			if (isspace(id[i].pwd[j])) id[i].pwd[j] = 0;
		}
	}
	fclose(fp);
}
void main(void) {
	WSADATA wsaData;
	SOCKET s, cs; //소켓 디스크립터
	struct sockaddr_in sin; //소켓 구조체
	struct sockaddr_in cli_addr;
	char data[1000];
	int size = sizeof(cli_addr);
	int ret, i;
	IDLIST login; //사용자 인증에 사용될 구조체

	getid();  //사용자 인증 파일을 읽어서 IDLIST에 넣습니다.

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0) {
		printf("WSAStartup 실패, 에러 코드 = %d\n", WSAGetLastError());
		return;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET) {
		printf("소켓 생성 실패, 에러 코드 : %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	sin.sin_family = AF_INET; //AF_INET 체계임을 명시
	sin.sin_port = htons(12345); //12345번 포트를 사용
	sin.sin_addr.s_addr = htonl(ADDR_ANY);

	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR) {
		printf("바인드 실패, 에러 코드 = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (listen(s, SOMAXCONN) != 0) {
		printf("리슨 모드 설정 실패, 에러 코드 = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("인증 서버를 시작합니다...");

	while (1) {
		cs = accept(s, (struct sockaddr*)&cli_addr, &size);

		if (cs == INVALID_SOCKET) {
			printf("접속 중인 실패, 에러 코드 = %d\n", WSAGetLastError());
			closesocket(s);
			WSACleanup();
			return;
		}

		memset(data, 0, sizeof(data));
		ret = recv(cs, data, 1000, 0);

		if (ret == SOCKET_ERROR) {
			printf("수신 실패, 에러 코드 = %u\n", WSAGetLastError());
			closesocket(cs);
			closesocket(s);
			WSACleanup();
			return;
		}

		memset(&login, 0, sizeof(login));
		strncpy(login.uid, &data[0], 8); //인증정보를 login구조체에 복사합니다.
		strncpy(login.pwd, &data[8], 8);

		for (i = 7;i >= 0;i--) { //사용자 ID와 암호의 오른쪽 공백을 제거.
			if (isspace(login.uid[i])) login.uid[i] = 0;
			if (isspace(login.pwd[i])) login.pwd[i] = 0;
		}

		for (i = 0;i < 100;i++) { //인증.
			if (strcmp(login.uid, id[i].uid) == 0) {
				if (strcmp(login.pwd, id[i].pwd) == 0) {
					printf("%s 사용자가 접속하였습니다.\n", login.uid);
					send(cs, "1", 1, 0); //인증 성공.
					break;
				}
				else {
					printf("%s %s\n", id[i].uid, id[i].pwd);
					printf("%s 사용자의 암호가 정확하지 않습니다.\n", login.uid);
					send(cs, "2", 1, 0); //암호 틀림.
					break;
				}

			}
		}

		if (i == 100) {
			printf("등록되지 않은 사용자가 로그인을 시도하였습니다.\n");
			printf("사용자 ID:%s\n", login.uid);
			send(cs, "3", 1, 0); //틀림.
		}

		closesocket(cs);
	}

	if (closesocket(cs) != 0 || closesocket(s) != 0) {
		printf("소켓 제거 실패, 에러 코드 = %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WASCleanup 실패, 에러 코드 = %u\n", WSAGetLastError());
		return;
	}
}
//OSI(Open Systems Interconnection) 7계층 참조 모델은 기종이 서로 다른 컴퓨터간의 정보 교환을 원활히 하기 위해
//국제 표준화기구 ISO에서 제정한 것으로, 네트워크를 이루고 있는 구성 요소들을 계층적으로 나누고 표준을 정한것.
//7:애플리케이션:사용자 프로그램에서 네트워크를 이용하기 위한 프로그래밍 인터페이스 정의
//6:프리젠테이션:애플리케이션 계층으로부터 받은 데이터를 인코딩하여 네트워크로 전송
//5:세션:애플리케이션 간에 가상 연결 생성
//4:전송:신뢰할 수 있는 데이터 통신 진행
//3:네트워크:논리적 주소를 사용하여 LAN 상에 각 노드에 접근
//2:데이터링크:물리적 주소를 사용하여 물리적 네트워크 이용
//1:물리:컨넥터, 케이블 등을 정의.
//일반적으로 인증 서버는 파일이 아닌 데이터베이스로부터 인증.
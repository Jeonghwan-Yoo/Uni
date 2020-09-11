//TCP/IP를 사용하여 채팅 서버 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>
#include <conio.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	WSADATA wsaData;
	SOCKET s, cs; //소켓 디스크립터
	struct sockaddr_in sin; //소켓 구조체
	struct sockaddr_in cli_addr;
	int size = sizeof(cli_addr);
	char buff[1000], data[1000];
	int nTimeOut = 200;
	char ID[100];
	int ret;

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

	sin.sin_family = AF_INET; //AF_INET 체계임을 명일
	sin.sin_port = htons(10000); //10000번 포트를 사용
	sin.sin_addr.s_addr = htonl(ADDR_ANY); //모든 클라이언트로부터 접속 허용

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

	puts("채팅 서버를 시작합니다...");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size);

	if (cs == INVALID_SOCKET) {
		printf("접속 승인 실패, 에러 코드 = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	printf("채팅에 사용할 별명을 입력하세요 : ");
	gets(ID);
	printf("메시지를 입력하고 엔터키를 치세요.");

	size = sizeof(int);
	setsockopt(cs, SOL_SOCKET, SO_RCVTIMEO, (char*)&nTimeOut, size); //recv() 타임아웃 시간을 200ms로 설정합니다.

	while (1) {
		if (kbhit()) { //키보드가 눌려졌는지 검사합니다.
			gets(buff);
			if (strcmp(buff, "END") == 0) {
				send(s, "END", 3, 0);
				break;
			}
			sprintf(data, "%s:%s", ID, buff);

			if (send(cs, data, strlen(data), 0) < strlen(data)) {
				printf("전송 실패, 에러 코드 = %u\n", WSAGetLastError());
				closesocket(cs);
				closesocket(s);
				WSACleanup();
				return;
			}

			memset(data, 0, sizeof(data)); //버퍼를 비웁니다.

			ret = recv(cs, data, 1000, 0); //채팅 메시지를 수신하기 위해 0.2초간 대기합니다.

			if (ret == 0 || WSAGetLastError() == WSAETIMEDOUT) continue; 
			//수신받은 길이가 0이거나, 0.2초가 지난 타임아웃이면 while계속 실행.

			if (ret == SOCKET_ERROR) {
				printf("수신 실패, 에러 코드 = %u\n", WSAGetLastError());
				closesocket(cs);
				closesocket(s);
				WSACleanup();
				return;
			}

			puts(data);
		}

		if (closesocket(cs) != 0 || closesocket(s) != 0) {
			printf("소켓 제거 실패, 에러 코드 = %u\n", WSAGetLastError());
			WSACleanup();
			return;
		}

		if (WSACleanup() != 0) {
			printf("WSACleanup 실패, 에러 코드 = %n\n", WSAGetLastError());
			return;
		}
	}
}
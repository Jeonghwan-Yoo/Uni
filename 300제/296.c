//TCP/IP를 사용하여 채팅 클라이언트 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>
#include <conio.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	WSADATA wsaData;
	SOCKET s; //소켓 디스크립터
	struct sockaddr_in sin; //소켓 구조체
	int size;
	int nTimeOut = 200;
	char buff[1000], data[1000];
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

	puts("채팅 클라이언트를 시작합니다...");

	sin.sin_family = AF_INET; //주소 체계 설정
	sin.sin_addr.s_addr = inet_addr("127.0.0.1"); //접속 주소 설정
	sin.sin_port = htons(10000); //포트 번호 설정

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
		printf("접속 실패, 에러 코드 = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	size = sizeof(int);
	setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char*)&nTimeOut, size);

	printf("채팅에 사용할 별명을 입력하세요 : ");
	gets(ID);
	puts("메시지를 입력하고 엔터키를 치세요.");

	while (1) {
		if (kbhit()) {
			gets(buff);
			if (strcmp(buff, "END") == 0) {
				send(s, "END", 3, 0);
				break;
			}

			sprintf(data, "%s:%s", ID, buff);

			if (send(s, data, strlen(data), 0) < strlen(data)) {
				printf("전송 실패, 에러 코드 = %u\n", WSAGetLastError());
				closesocket(s);
				WSACleanup();
				return;
			}

			memset(data, 0, sizeof(data));
			ret = recv(s, data, 1000, 0);

			if (ret == 0 || WSAGetLastError() == WSAETIMEDOUT) continue;

			if (ret == SOCKET_ERROR) {
				printf("수신 실패, 에러 코드 = %u\n", WSAGetLastError());
				closesocket(s);
				WSACleanup();
				return;
			}

			puts(data);

			if (strcmp(data, "END") == 0) break;
		}
		if (closesocket(s) != 0) {
			printf("소켓 제거 실패, 에러 코드 = %u\n", WSAGetLastError());
			WSACleanup();
			return;
		}

		if (WSACleanup() != 0) {
			printf("WSACleanup 실패, 에러 코드 = %u\n", WSAGetLastError());
			return;
		}
	}
}
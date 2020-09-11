//TCP/IP 패킷을 받으면 그대로 되돌려 주는 에코 서버 프로그램을 작성하세요.
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	WSADATA wsaData;
	SOCKET s, cs; //소켓 디스크립터
	struct sockaddr_in sin; //소켓 구조체
	struct sockaddr_in cli_addr;
	int size = sizeof(cli_addr);
	char data[1000] = { 0, };
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

	sin.sin_family = AF_INET; //AF_INET 체계임을 명시
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

	printf("에코 서버를 시작합니다...\n");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size);

	if (cs == INVALID_SOCKET) {
		printf("접속 승인 실패, 에러 코드 = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	while (1) {
		memset(data, 0, sizeof(data));

		ret = recv(cs, data, 1000, 0);

		if (ret == SOCKET_ERROR) {
			printf("데이터 수신 실패, 에러 코드 = %u\n", WSAGetLastError());
			closesocket(cs);
			closesocket(s);
			WSACleanup();
			return;
		}

		printf("%s가 수신되었습니다.\n", data);

		send(cs, data, ret, 0);

		if (strcmp(data, "END") == 0) break;

	}

	if (closesocket(cs) != 0 || closesocket(s) != 0) {
		printf("소켓 제거 실패, 에러 코드 = %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WSACleanup 실패, 에러 코드 = %u\n", WSAGetLastError());
		return;
	}
}
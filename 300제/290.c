//파일을 수신하는 TCP/IP서버 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	SOCKET s, cs; //소켓 디스크립터
	WSADATA wsaData;
	struct sockaddr_in sin; //소켓 구조체
	struct sockaddr_in cli_addr;
	int size = sizeof(cli_addr);
	char data[1024] = { 0, };
	int ret;
	FILE *fp;
	int nTimeOut = 3000; //recv()는 데이터가 들어오지 않으면 무한 대기 상태에 머뭅니다.
	//무한대기상태를 방지하기 위해 3초간 데이터가 들어오지 않으면 타임아웃이 발생하게 합니다.

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

	printf("클라이언트로 부터 접속을 기다리고 있습니다...\n");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size);

	if (cs == INVALID_SOCKET) {
		printf("접속 승인 실패, 에러 코드 = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	fp = fopen("recv.bin", "w+b");

	if (fp == NULL) {
		perror("파일 생성 에러");
		closesocket(cs);
		closesocket(s);
		WSACleanup();
		return;
	}

	setsockopt(cs, SOL_SOCKET, SO_RCVTIMEO, (char*)&nTimeOut, size); //recv함수에 대한 타임아웃을 설정합니다.
	//설정 후, recv()함수는 3초간 데이터가 수신되지 않으면 타임아웃이 발생하고 0이 반환됩니다.

	while (1) {
		ret = recv(cs, data, 1024, 0); //데이터를 수신합니다. 최대 1024바이트까지 수신되며,
		//송신쪽에서 1024바이트 미만의 데이터를 전송하였을 경우 그 크기만큼 수신됩니다.

		if (ret == 0) break;

		if (ret == SOCKET_ERROR) {
			printf("수신 에러, 에러 코드 = (%u)\n", WSAGetLastError());
			closesocket(cs);
			closesocket(s);
			WSACleanup();
			fclose(fp);
			return;
		}

		fwrite(data, 1, ret, fp);
		printf("%d 바이트를 수신하였습니다.\n", ret);
	}
	fclose(fp);

	shutdown(s, SD_BOTH);

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
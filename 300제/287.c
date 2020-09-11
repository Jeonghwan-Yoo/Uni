//286에서 접속된 클라이언트의 주소 및 포트를 출력하는 프로그램을 작성하세요.
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
	char data[10] = { 0, };

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

	printf("클라이언트로부터 접속을 기다리고 있습니다...\n");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size);

	if (cs == INVALID_SOCKET) {
		printf("접속 승인 실패, 에러 코드 = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	printf("연결된 클라이언트 IP:%s, 포트 번호:%d\n",
		inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
	//연결된 클라이언트의 주소를 구하려면 inet_ntoa()함수를 사용하며, 번호를 구하려면 ntohs()함수를 사용합니다.
	//프로그램을 실행하면, 다른 특정 번호로 출력되는데, 이것은 클라이언트 프로그램에서 bind()함수를 통해
	//포트 번호를 설정하지 않았기 때문에, 운영체제가 사용하지 않는 임의의 포트를 자동으로 설정한 것입니다.
	//클라이언트 프로그램에 포트 번호를 설정하려면 서버 프로그램처럼 bind()함수를 사용하면 됩니다.

	if (recv(cs, data, 3, 0) < 3) {
		printf("데이터 수신 실패, 에러 코드 = %u\n", WSAGetLastError());
		closesocket(cs);
		closesocket(s);
		WSACleanup();
		return;
	}

	printf("%s가 클라이언트로부터 수신되었습니다.\n", data);

	if (closesocket(cs) != 0 || closesocket(s) != 0) {
		printf("소켓 제거 실패, 에러 코드 = %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WSACleanup 실패, 에러 콛드 = %u\n", WSAGetLastError());
		return;
	}
}
//send()함수를 통해 1024바이트를 전송하면, 경우에 따라 1024바이트는 여러 개의 조각으로 나누어져서 전송됩니다.
//즉, recv() 함수가 몇 바이트를 수신하였는지 반환값을 꼭 환인하고, 1024바이트를 분할해서 받을 수도 있는 프로그램을 만들어야 합니다.
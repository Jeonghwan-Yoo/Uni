//접속할 주소 및 포트를 설정하는 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

void main(void) {
	SOCKET s; //소켓 디스크립터
	WSADATA wsaData;
	SOCKADDR_IN sin; //소켓 구조체
	//접속할 주소 및 포트를 설정하기 위해.
	/*
	struct sockaddr_in{
		short sin_family;
		u_short sin_port;
		struct in_addr sin_addr;
		char sin_zero[8];
	};
	*/

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

	sin.sin_family = AF_INET; //주소 체계 설정.
	//AF_INET은 TCP/IP 및 UDP프로토콜을 사용한다는 뜻.

	sin.sin_addr.s_addr = inet_addr("127.0.0.1"); //접속 주소 설정.
	//로컬호스트 번지 127.0.0.1

	sin.sin_port = htons(21); //포트 번호 설정.
	//하나의 컴퓨터에서 여러 개의 프로그램이 동시에 실행될 수 있기 때문에 포트번호 설정.
	//운영체제에 의해 1~2000번 사이의 번호가 사용되거나 예약. 21번은 FTP서버의 포트번호. 80이 웹서버 포트.

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) { //서버에 접속을 시도합니다.
		//만약 실행중이 FTP서버가 없다면 연결은 실패.

		printf("접속 실패, 에러 코드 = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
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

	puts("127.0.0.1의 21번 포트에 접속을 성공하였습니다.");
}
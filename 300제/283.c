//TCP/IP서버 프로그램을 작성하세요.
//gcc로 실행하려면 gcc 283.c -o 283 -L/usr/lib32/wine/ -lws2_32 -lwsock32후에 283으로 실행.
#include <stdio.h>
#include <WinSock2.h>

#define WINSOCK_VERSION MAKEWORD(2,2) //gcc할 때 에러방지.

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

void main(void) {
	SOCKET s, cs; //소켓 디스크립터
	WSADATA wsaData;
	struct sockaddr_in sin; //소켓 구조체
	struct sockaddr_in cli_addr;
	int size=sizeof(cli_addr);

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
	//21번은 FTP서버에 의해 사용중이기 때문에 에러가 발생할 수 있다.

	sin.sin_addr.s_addr = htonl(ADDR_ANY); //모든 클라이언트로부 접속 허용.
	//ADDR_ANY라는 것은 모든 IP주소로부터 접근을 허용하겠다는 것이고,
	//특정 IP주소만 접근을 허용하려면, inet_addr()을 이용하면 된다.

	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR) {
		printf("바인드 실패, 에러 코드 = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (listen(s, SOMAXCONN) != 0) { //동시에 몇 개까지의 클라이언트로부터 접속을 승인해 줄지를 설정합니다.
		//SOMAXCONN의 값은 0x7fffffff으로 거의 무한대이다.

		printf("리슨 모드 설정 실패, 에러 코드 =%d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	printf("클라이언트로부터 접속을 기다리고 있습니다...\n");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size); //bind와 listen함수에 의해 클라이언트로부터 접속을 받을 준비가
	//되었으며, 접속이 시도된다면 접속 시도는 큐에 저장되고, accept()함수는 큐에 저장된 클라이언트 정보를 하나 꺼내옵니다.
	//이 함수는 클라이언트로부터 접속이 있을 때까지 더 이상 실행을 진행하지 않고 무한 대기합니다.
	//서버가 연결이 되었을 경우에 cs라는 새로운 소켓 디스크립터가 생성되며, 데이터를 주고 받을 수 있습니다.

	if (cs == INVALID_SOCKET) {
		printf("접속 승인 실패, 에러 코드 = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("클라이언트와 연결되었습니다.");

	if (closesocket(cs) != 0 || closesocket(s) != 0) { //모든 소켓이 제거되어야 합니다.
		printf("소켓 제거 실패, 에러 코드 = %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WSACleanup 실패, 에러 코드 = %d\n", WSAGetLastError());
		return;
	}
}
//포트는 IP주소 표기를 확장하는 개념이라 할 수 있습니다. 보통 소켓을 사용하는 서버-클라이언트 프로그램은
//서버에 연결을 시작하는 클라이언트와 클라이언트로부터 연결을 대기하는 서버 프로그램으로 이루어집니다.
//서버 연결 프로그램이 연결을 수락하면 연결된 클라이언트를 전적으로 담당할 소켓을 새로 생성합니다.
//그러면, 클라이언트와 서버는 개별 소켓으로 데이터를 읽고 쓰면서 통신을 수행합니다.
//송수신중인 데이터를 모두 처리한 후 TCP/IP를 안전하게 종료하는 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"wsock32.lib");
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	SOCKET s; //소켓 디스크립터
	WSADATA wsaData;
	struct sockaddr_in sin; //소켓 구조체
	char data[10] = "abc";

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

	sin.sin_family = AF_INET; //주소 체계 설정
	sin.sin_addr.s_addr = inet_addr("127.0.0.1"); //접속 주소 설정
	sin.sin_port = htons(10000); //포트 번호 설정

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) {
		printf("접속 실패, 에러 코드 = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (send(s, data, 3, 0) < 3) {
		printf("데이터 전송 실패, 에러 코드 = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("abc를 서버 프로그램에 전송하였습니다.");

	shutdown(s, SD_BOTH); //SD_BOTH는 송신 및 수신중인 모든 데이터를 주고받을 때까지 대기한 후 종료하라는 의미이고,
	//송신만 대기하려면 SD_SEND를 사용하고, 수신만 대리하려면 SD_RECEIVE를 사용하세요.
	//closesocket()은 송수신중인 데이터를 잃을 수 있으므로 주의해야 합니다.

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
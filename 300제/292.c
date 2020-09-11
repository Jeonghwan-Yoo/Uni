//내 컴퓨터에서 사용중인 모든 TCP/IP 포트를 출력하는 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(int argc, char *argv[]) {
	WSADATA wsaData;
	SOCKET s; //소켓 디스크립터
	struct sockaddr_in sin; //소켓 구조체
	unsigned short i;

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

	for (i = 1;i <= 65535;i++) { //1~65535까지 모든 포트에 대하여 검사합니다.
		sin.sin_family = AF_INET; //주소 체계 설정
		sin.sin_addr.s_addr = inet_addr("127.0.0.1"); //접속 주소 설정
		sin.sin_port = htons(i); //포트 번호 설정.

		if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) == 0) { //검색후에는 다음 포트를 찾기 위해,
			//생성된 소켓을 closesocket()으로 닫아주고 새로운 소켓을 생성하여 다음 포트 번호를 계속 검색합니다.

			printf("\n%5d 포트가 사용 중입니다.\n", i);
			closesocket(s);

			s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

			if (s == INVALID_SOCKET) {
				printf("소켓 생성 실패, 에러 코드 : %d\n", WSAGetLastError());
				WSACleanup();
				return;
			}
		}
		else { //사용중이지 않을 때,
			printf("."); 
		}
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
//well-known포트는 21번 FTP, 25번 SMTP, 80번 웹서버,.
//CMD에서는 netstat /a를 통해 알 수 있다.
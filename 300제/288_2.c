//브로드캐스팅을 하기 위한 UDP 통신의 예제.
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#pragma comment(lib,"wsock32.lib")
#define PORT 12345

int main(void) {
	WSADATA wsaData;
	SOCKET s;
	int optval = 1;
	int size = sizeof(int);
	char buf[5] = "안녕";
	int len = 4;
	int ret;
	SOCKADDR_IN serv_addr;

	WSAStartup(WINSOCK_VERSION, &wsaData);
	s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP); //UDP용 생성

	setsockopt(s, SOL_SOCKET, SO_BROADCAST, (char*)&optval, sizeof(optval));

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
	serv_addr.sin_port = htons(PORT);
	size = sizeof(SOCKADDR_IN);

	sendto(s, buf, len, 0, (SOCKADDR*)&serv_addr, size);

	closesocket(s);
	WSACleanup();
	return 1;
}
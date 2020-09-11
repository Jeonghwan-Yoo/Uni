//������ �ּ� �� ��Ʈ�� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

void main(void) {
	SOCKET s; //���� ��ũ����
	WSADATA wsaData;
	SOCKADDR_IN sin; //���� ����ü
	//������ �ּ� �� ��Ʈ�� �����ϱ� ����.
	/*
	struct sockaddr_in{
		short sin_family;
		u_short sin_port;
		struct in_addr sin_addr;
		char sin_zero[8];
	};
	*/

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0) {
		printf("WSAStartup ����, ���� �ڵ� = %d\n", WSAGetLastError());
		return;
	}
	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET) {
		printf("���� ���� ����, ���� �ڵ� : %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	sin.sin_family = AF_INET; //�ּ� ü�� ����.
	//AF_INET�� TCP/IP �� UDP���������� ����Ѵٴ� ��.

	sin.sin_addr.s_addr = inet_addr("127.0.0.1"); //���� �ּ� ����.
	//����ȣ��Ʈ ���� 127.0.0.1

	sin.sin_port = htons(21); //��Ʈ ��ȣ ����.
	//�ϳ��� ��ǻ�Ϳ��� ���� ���� ���α׷��� ���ÿ� ����� �� �ֱ� ������ ��Ʈ��ȣ ����.
	//�ü���� ���� 1~2000�� ������ ��ȣ�� ���ǰų� ����. 21���� FTP������ ��Ʈ��ȣ. 80�� ������ ��Ʈ.

	if (connect(s, (struct sockaddr*)&sin, sizeof(sin)) != 0) { //������ ������ �õ��մϴ�.
		//���� �������� FTP������ ���ٸ� ������ ����.

		printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (closesocket(s) != 0) {
		printf("���� ���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WSACleanup ����, ���� �ڵ� = %u\n", WSAGetLastError());
		return;
	}

	puts("127.0.0.1�� 21�� ��Ʈ�� ������ �����Ͽ����ϴ�.");
}
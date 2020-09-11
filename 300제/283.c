//TCP/IP���� ���α׷��� �ۼ��ϼ���.
//gcc�� �����Ϸ��� gcc 283.c -o 283 -L/usr/lib32/wine/ -lws2_32 -lwsock32�Ŀ� 283���� ����.
#include <stdio.h>
#include <WinSock2.h>

#define WINSOCK_VERSION MAKEWORD(2,2) //gcc�� �� ��������.

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

void main(void) {
	SOCKET s, cs; //���� ��ũ����
	WSADATA wsaData;
	struct sockaddr_in sin; //���� ����ü
	struct sockaddr_in cli_addr;
	int size=sizeof(cli_addr);

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

	sin.sin_family = AF_INET; //AF_INET ü������ ���
	sin.sin_port = htons(10000); //10000�� ��Ʈ�� ���
	//21���� FTP������ ���� ������̱� ������ ������ �߻��� �� �ִ�.

	sin.sin_addr.s_addr = htonl(ADDR_ANY); //��� Ŭ���̾�Ʈ�κ� ���� ���.
	//ADDR_ANY��� ���� ��� IP�ּҷκ��� ������ ����ϰڴٴ� ���̰�,
	//Ư�� IP�ּҸ� ������ ����Ϸ���, inet_addr()�� �̿��ϸ� �ȴ�.

	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR) {
		printf("���ε� ����, ���� �ڵ� = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (listen(s, SOMAXCONN) != 0) { //���ÿ� �� �������� Ŭ���̾�Ʈ�κ��� ������ ������ ������ �����մϴ�.
		//SOMAXCONN�� ���� 0x7fffffff���� ���� ���Ѵ��̴�.

		printf("���� ��� ���� ����, ���� �ڵ� =%d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	printf("Ŭ���̾�Ʈ�κ��� ������ ��ٸ��� �ֽ��ϴ�...\n");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size); //bind�� listen�Լ��� ���� Ŭ���̾�Ʈ�κ��� ������ ���� �غ�
	//�Ǿ�����, ������ �õ��ȴٸ� ���� �õ��� ť�� ����ǰ�, accept()�Լ��� ť�� ����� Ŭ���̾�Ʈ ������ �ϳ� �����ɴϴ�.
	//�� �Լ��� Ŭ���̾�Ʈ�κ��� ������ ���� ������ �� �̻� ������ �������� �ʰ� ���� ����մϴ�.
	//������ ������ �Ǿ��� ��쿡 cs��� ���ο� ���� ��ũ���Ͱ� �����Ǹ�, �����͸� �ְ� ���� �� �ֽ��ϴ�.

	if (cs == INVALID_SOCKET) {
		printf("���� ���� ����, ���� �ڵ� = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	puts("Ŭ���̾�Ʈ�� ����Ǿ����ϴ�.");

	if (closesocket(cs) != 0 || closesocket(s) != 0) { //��� ������ ���ŵǾ�� �մϴ�.
		printf("���� ���� ����, ���� �ڵ� = %d\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WSACleanup ����, ���� �ڵ� = %d\n", WSAGetLastError());
		return;
	}
}
//��Ʈ�� IP�ּ� ǥ�⸦ Ȯ���ϴ� �����̶� �� �� �ֽ��ϴ�. ���� ������ ����ϴ� ����-Ŭ���̾�Ʈ ���α׷���
//������ ������ �����ϴ� Ŭ���̾�Ʈ�� Ŭ���̾�Ʈ�κ��� ������ ����ϴ� ���� ���α׷����� �̷�����ϴ�.
//���� ���� ���α׷��� ������ �����ϸ� ����� Ŭ���̾�Ʈ�� �������� ����� ������ ���� �����մϴ�.
//�׷���, Ŭ���̾�Ʈ�� ������ ���� �������� �����͸� �а� ���鼭 ����� �����մϴ�.
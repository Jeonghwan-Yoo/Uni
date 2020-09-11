//283���� ���α׷��� �����͸� �����ϴ� �κ��� �߰��ϼ���.
#include <stdio.h>
#include <WinSock2.h>

#define WINSOCK_VERSION MAKEWORD(2,2)

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

void main(void) {
	SOCKET s, cs; //���� ��ũ����
	WSADATA wsaData;
	struct sockaddr_in sin; //���� ����ü
	struct sockaddr_in cli_addr;
	int size = sizeof(cli_addr);
	char data[10] = { 0, };

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
	sin.sin_addr.s_addr = htonl(ADDR_ANY); //��� Ŭ���̾�Ʈ�κ��� ���� ���
	
	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR) {
		printf("���ε� ����, ���� �ڵ� = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (listen(s, SOMAXCONN) != 0) {
		printf("���� ��� ���� ����, ���� �ڵ� = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	printf("Ŭ���̾�Ʈ�κ��� ������ ��ٸ��� �ֽ��ϴ�...\n");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size);

	if (cs == INVALID_SOCKET) {
		printf("���� ���� ����, ���� �ڵ� = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	if (recv(cs, data, 3, 0) < 3) { //accept()�Լ��� ���� ����� Ŭ���̾�Ʈ�κ��� �����͸� 3����Ʈ ���Ź޽��ϴ�.
		//������ �������̶�� recv()�Լ��� 3�� ��ȯ�մϴ�.

		printf("������ ���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	printf("%s�� Ŭ���̾�Ʈ�κ��� ���ŵǾ����ϴ�.\n", data);

	if (closesocket(cs) != 0 || closesocket(s) != 0) {
		printf("���� ���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WSACleanup ����, ���� �ڵ� = %u\n", WSAGetLastError());
		return;
	}
}
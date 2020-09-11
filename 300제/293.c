//TCP/IP ��Ŷ�� ������ �״�� �ǵ��� �ִ� ���� ���� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	WSADATA wsaData;
	SOCKET s, cs; //���� ��ũ����
	struct sockaddr_in sin; //���� ����ü
	struct sockaddr_in cli_addr;
	int size = sizeof(cli_addr);
	char data[1000] = { 0, };
	int ret;

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

	printf("���� ������ �����մϴ�...\n");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size);

	if (cs == INVALID_SOCKET) {
		printf("���� ���� ����, ���� �ڵ� = %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return;
	}

	while (1) {
		memset(data, 0, sizeof(data));

		ret = recv(cs, data, 1000, 0);

		if (ret == SOCKET_ERROR) {
			printf("������ ���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
			closesocket(cs);
			closesocket(s);
			WSACleanup();
			return;
		}

		printf("%s�� ���ŵǾ����ϴ�.\n", data);

		send(cs, data, ret, 0);

		if (strcmp(data, "END") == 0) break;

	}

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
//286���� ���ӵ� Ŭ���̾�Ʈ�� �ּ� �� ��Ʈ�� ����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

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

	printf("����� Ŭ���̾�Ʈ IP:%s, ��Ʈ ��ȣ:%d\n",
		inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
	//����� Ŭ���̾�Ʈ�� �ּҸ� ���Ϸ��� inet_ntoa()�Լ��� ����ϸ�, ��ȣ�� ���Ϸ��� ntohs()�Լ��� ����մϴ�.
	//���α׷��� �����ϸ�, �ٸ� Ư�� ��ȣ�� ��µǴµ�, �̰��� Ŭ���̾�Ʈ ���α׷����� bind()�Լ��� ����
	//��Ʈ ��ȣ�� �������� �ʾұ� ������, �ü���� ������� �ʴ� ������ ��Ʈ�� �ڵ����� ������ ���Դϴ�.
	//Ŭ���̾�Ʈ ���α׷��� ��Ʈ ��ȣ�� �����Ϸ��� ���� ���α׷�ó�� bind()�Լ��� ����ϸ� �˴ϴ�.

	if (recv(cs, data, 3, 0) < 3) {
		printf("������ ���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		closesocket(cs);
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
		printf("WSACleanup ����, ���� ���� = %u\n", WSAGetLastError());
		return;
	}
}
//send()�Լ��� ���� 1024����Ʈ�� �����ϸ�, ��쿡 ���� 1024����Ʈ�� ���� ���� �������� ���������� ���۵˴ϴ�.
//��, recv() �Լ��� �� ����Ʈ�� �����Ͽ����� ��ȯ���� �� ȯ���ϰ�, 1024����Ʈ�� �����ؼ� ���� ���� �ִ� ���α׷��� ������ �մϴ�.
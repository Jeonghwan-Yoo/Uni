//�� ���� ������ ũ�⸦ 1MB�� �����ϴ� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

#define WINSOCK_VERSION MAKEWORD(2,2)

void main(void) {
	SOCKET s; //���� ��ũ����
	WSADATA wsaData;
	int nSize = 1048576; //�ۼ��� ���� ũ�� 1MB.
	int size = sizeof(int);

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
	
	getsockopt(s, SOL_SOCKET, SO_SNDBUF, (char*)&nSize, (int*)&size); //����ũ�� ���
	printf("���� �۽� ������ ũ�Ⱑ %d�� �����Ǿ����ϴ�.\n", nSize);
	
	getsockopt(s, SOL_SOCKET, SO_RCVBUF, (char*)&nSize, (int*)&size);
	printf("���� ���� ������ ũ�Ⱑ %d�� �����Ǿ����ϴ�.\n", nSize);

	setsockopt(s, SOL_SOCKET, SO_SNDBUF, (char*)&nSize, (int)&size);
	setsockopt(s, SOL_SOCKET, SO_RCVBUF, (char*)&nSize, (int)&size);
	
	getsockopt(s, SOL_SOCKET, SO_SNDBUF, (char*)&nSize, (int*)&size);
	printf("�۽� ������ ũ�Ⱑ %d�� �����Ǿ����ϴ�.\n", nSize);

	getsockopt(s, SOL_SOCKET, SO_RCVBUF, (char*)&nSize, (int*)&size);
	printf("���� ������ ũ�Ⱑ %d�� �����Ǿ����ϴ�.\n", nSize);

	if (closesocket(s) != 0) {
		printf("���� ���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WSAClenaup ����, ���� �ڵ� = %u\n", WSAGetLastError());
		return;
	}
}
//�⺻������ ���Ǵ� �ۼ��� ������ ũ��� 8KB(8196)�Դϴ�. �������� ���� ���ų� �ϰ� ó���ؾ��ϸ� ũ�⸦ �÷���� �մϴ�.
//closesocket()�Լ��� ���� ����Ǿ� �ִ� ������ ���Ƿ� ������ �� ���Ǿ� ���ϴ�.
//SO_SNDTIMEO�۽� Ÿ�Ӿƿ��� �����մϴ�. �����Ϸ��� �����Ͱ� Ÿ�Ӿƿ� �ð� ���� ���۵��� �ʴ´ٸ�, ������ �߻��˴ϴ�.
//SO_RCVTIMEO���� Ÿ�Ӿƿ��� �����մϴ�. �����Ϸ��� �����Ͱ� Ÿ�Ӿƿ� �ð� ���� ���۵��� �ʴ´ٸ�, ������ �߻��˴ϴ�.
//SO_LINGER closesocket()�Լ��� ȣ���ϸ�, �� ��� ��� �������� �����͸� �Ұ� �Ǵµ�, ���� �ð� ���� ������
//����ϱ� ���� �� �ɼ��� ����մϴ�.
//�� �ۿ��� UDP, ��ε�ĳ��Ʈ ��Ƽ����Ʈ���� ���Ǵ� �ɼ����� SO_MAX_MSG_SIZE, SO_BROADCAST, SO_REUSEADDR���� �ִ�.
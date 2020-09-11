//100���� �α����� �����ϴ� ���� ���α׷��� �ۼ��ϼ���.
#include <stdio.h>
#include <WinSock2.h>
#include <ctype.h> //isspace������.

#define USERFILE "userid.txt" //ID�� ��ȣ ����.
#define WINSOCK_VERSION MAKEWORD(2,2)

#pragma comment(lib,"wsock32.lib")
#pragma warning(disable:4996)

typedef struct tagIDList {
	char uid[9];
	char pwd[9];
}IDLIST;

IDLIST id[100];

void getid(void) {
	FILE *fp;
	int i, j;
	char buff[100];

	fp = fopen(USERFILE, "r");

	for (i = 0;i < 100;i++) {
		fgets(buff, 20, fp); 
		strncpy(id[i].uid, &buff[0], 8); //����� id�� �����մϴ�. �ִ� ���� 8����Ʈ.
		strncpy(id[i].pwd, &buff[8], 8);

		for (j = 7;j >= 0;j--) { //���� ����.
			if (isspace(id[i].uid[j])) id[i].uid[j] = 0;
			if (isspace(id[i].pwd[j])) id[i].pwd[j] = 0;
		}
	}
	fclose(fp);
}
void main(void) {
	WSADATA wsaData;
	SOCKET s, cs; //���� ��ũ����
	struct sockaddr_in sin; //���� ����ü
	struct sockaddr_in cli_addr;
	char data[1000];
	int size = sizeof(cli_addr);
	int ret, i;
	IDLIST login; //����� ������ ���� ����ü

	getid();  //����� ���� ������ �о IDLIST�� �ֽ��ϴ�.

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
	sin.sin_port = htons(12345); //12345�� ��Ʈ�� ���
	sin.sin_addr.s_addr = htonl(ADDR_ANY);

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

	puts("���� ������ �����մϴ�...");

	while (1) {
		cs = accept(s, (struct sockaddr*)&cli_addr, &size);

		if (cs == INVALID_SOCKET) {
			printf("���� ���� ����, ���� �ڵ� = %d\n", WSAGetLastError());
			closesocket(s);
			WSACleanup();
			return;
		}

		memset(data, 0, sizeof(data));
		ret = recv(cs, data, 1000, 0);

		if (ret == SOCKET_ERROR) {
			printf("���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
			closesocket(cs);
			closesocket(s);
			WSACleanup();
			return;
		}

		memset(&login, 0, sizeof(login));
		strncpy(login.uid, &data[0], 8); //���������� login����ü�� �����մϴ�.
		strncpy(login.pwd, &data[8], 8);

		for (i = 7;i >= 0;i--) { //����� ID�� ��ȣ�� ������ ������ ����.
			if (isspace(login.uid[i])) login.uid[i] = 0;
			if (isspace(login.pwd[i])) login.pwd[i] = 0;
		}

		for (i = 0;i < 100;i++) { //����.
			if (strcmp(login.uid, id[i].uid) == 0) {
				if (strcmp(login.pwd, id[i].pwd) == 0) {
					printf("%s ����ڰ� �����Ͽ����ϴ�.\n", login.uid);
					send(cs, "1", 1, 0); //���� ����.
					break;
				}
				else {
					printf("%s %s\n", id[i].uid, id[i].pwd);
					printf("%s ������� ��ȣ�� ��Ȯ���� �ʽ��ϴ�.\n", login.uid);
					send(cs, "2", 1, 0); //��ȣ Ʋ��.
					break;
				}

			}
		}

		if (i == 100) {
			printf("��ϵ��� ���� ����ڰ� �α����� �õ��Ͽ����ϴ�.\n");
			printf("����� ID:%s\n", login.uid);
			send(cs, "3", 1, 0); //Ʋ��.
		}

		closesocket(cs);
	}

	if (closesocket(cs) != 0 || closesocket(s) != 0) {
		printf("���� ���� ����, ���� �ڵ� = %u\n", WSAGetLastError());
		WSACleanup();
		return;
	}

	if (WSACleanup() != 0) {
		printf("WASCleanup ����, ���� �ڵ� = %u\n", WSAGetLastError());
		return;
	}
}
//OSI(Open Systems Interconnection) 7���� ���� ���� ������ ���� �ٸ� ��ǻ�Ͱ��� ���� ��ȯ�� ��Ȱ�� �ϱ� ����
//���� ǥ��ȭ�ⱸ ISO���� ������ ������, ��Ʈ��ũ�� �̷�� �ִ� ���� ��ҵ��� ���������� ������ ǥ���� ���Ѱ�.
//7:���ø����̼�:����� ���α׷����� ��Ʈ��ũ�� �̿��ϱ� ���� ���α׷��� �������̽� ����
//6:���������̼�:���ø����̼� �������κ��� ���� �����͸� ���ڵ��Ͽ� ��Ʈ��ũ�� ����
//5:����:���ø����̼� ���� ���� ���� ����
//4:����:�ŷ��� �� �ִ� ������ ��� ����
//3:��Ʈ��ũ:���� �ּҸ� ����Ͽ� LAN �� �� ��忡 ����
//2:�����͸�ũ:������ �ּҸ� ����Ͽ� ������ ��Ʈ��ũ �̿�
//1:����:������, ���̺� ���� ����.
//�Ϲ������� ���� ������ ������ �ƴ� �����ͺ��̽��κ��� ����.
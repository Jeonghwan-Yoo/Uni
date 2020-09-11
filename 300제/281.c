//TCP/IP를 초기화하는 프로그램을 작성하세요.
#include <stdio.h>
#include <WinSock2.h>

#pragma comment(lib, "wsock32.lib"); //C Runtime Lib가 아니기 때문에 반드시 포함.
//#pragma comment는 특정 라이브러리 파일을 포함시킬 때 사용합니다.

void main(void) {
	SOCKET s; //소켓 디스크립터. 소켓을 사용하기 위한 핸들. FILE *fp와 비슷.
	WSADATA wsaData; //WSAStartup()함수에서 현재 사용 가능한 윈속 정보를 얻기 위해 정의한다.

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0) { //윈속버전을 사용할 수 있는지 운영체제에 확인하는 함수이다.
		//운영체제는 사용할 수 있는 버전의 값을 wsaData에 돌려줍니다. 그리고 WS2_32.DLL을 초기화합니다.

		printf("WSAStartup 실패, 에러 코드 = %d\n", WSAGetLastError()); //에러가 발생하면 에러코드 확인.
		return;
	}
	puts(wsaData.szDescription); //사용하고 있는 윈속 버전을 보여줍니다.
	puts(wsaData.szSystemStatus); //사용하고 있는 윈속의 상태를 보여줍니다.

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //TCP/IP용 소켓 생성
	//소켓을 개방합니다. 마치 fopen()과 같다. UDP생성하려면 socket(AF_INET,SOCK_DGRAM,OPPROTO_UDP)처럼 사용

	if (s == INVALID_SOCKET) { //에러가 발생하면,
		printf("소켓 생성 실패, 에러코드 : %d\n", WSAGetLastError());
		WSACleanup(); //WS2_32.DLL의 사용을 종료합니다.
		return;
	}

	if (closesocket(s) != 0) { //소켓을 제거하면, fclose()와 비슷한 기능.
		//만약 송수신중인 데이터가 버퍼에 남아있다면 모든 데이터는 송수신되지 않고 즉시 종료.

		printf("소켓 제거 실패, 에러 코드 = %u\n", WSAGetLastError());
		WSACleanup(); //WS2_32.DLL의 사용을 종료합니다.
		return;
	}
	if (WSACleanup() != 0) { //소켓에서 사용했던 자원들을 모두 비웁니다. 파일을 여러 개 개방해서 사용할 수 있듯이
		//소켓도 여러개 가능하고, 시작시 WSAStartup()한번 종료 시 WSACleanup()한번 호출.
		//단, socket()함수나 closesocket()함수는 fopen(), fclose()함수처럼 여러번 사용가능.

		printf("WSACleanup 실패, 에러 코드 = %u\n", WSAGetLastError());
		return;
	}
	puts("윈속을 사용할 수 있습니다.");
}
//TCP/IP는 원거리의 컴퓨터와 상호 데이터를 주고받기 위한 통신 규약입니다. 
//LAN이나 ADSL을 통해 접근한다.
//TCP/IP 통신 프로그램은 흔히 소켓 프로그램이라고도 합니다.
//데이터를 주고받으려면, 파일을 입출력할 때와 마찬가지로, 소켓의 개방(socket())과 소켓의 제거(closesocket())가 반드시
//윈도우 소켓 프로그램에서는 여러 가지 종류의 소켓 버전이 사용되고, 버전을 설정하는 WSAStartup()과 해제하는 WSAClean()
//TCP/IP:컴퓨터간에 통신을 할 수 있는 프로토콜
//프로토콜:두 컴퓨터간의 주소를 어떻게 정하고, 각각이 어떻게 데이터를 보내는가에 대한 규칙들을 모아놓은 것.
//패킷:네트워크에 전송하는 데이터의 기본 단위
//밴드위스:케이블을 통하여 흐르는 데이터의 양
//서브넷:큰 네트워크를 분할해서 만든 작은 네트워크
//스트림:스트림은 일련의 문자들. 일련의 바이트로 바이트로 구성되는 데이터.
//UDP:비연결성, 비신뢰성의 특징을 갖는 전송 계층의 프로토콜.
//소켓:두 프로그램이 네트워크를 통해 서로 통신을 수행할 수 있도록 양쪽에 생성되는 링크의 단자.
//TCP/IP는 TCP패킷 IP패킷이 합쳐진 형태이며, TCP는 출발지 포트 번호, 도착지 포트 번호, 순차 번호, 승인 번호,
//제어 비트, 윈도우, 긴급 포인터, 데이터 등으로 구성. IP는 버전, 인터넷 헤더 길이, 서비스 형태, 플래그, TTL 프로토콜,
//출발지 IP주소, 도착지 IP주소 등으로 구성.
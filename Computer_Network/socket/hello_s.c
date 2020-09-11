#include <stdio.h>
#include <netinet/in.h> //struct sockaddr_in
#include <sys/socket.h> //bind, accept, connect, listen, socket
#include <string.h> //memset
#include <unistd.h> //close read write

#define PORT 9000 //port number 9000

char buffer[BUFSIZ]="hello, world\n"; //BUFSIZ;for optimizing buffer size.

int main(){
	int c_socket, s_socket;
	struct sockaddr_in s_addr, c_addr; //sin_family(e.g. AF_INET), sin_port(e.g. htons(3490)), sin_addr(see strut in_addr, below), sin_zero[8](zero this if you want to).
	int len;
	int n;

	s_socket=socket(PF_INET, SOCK_STREAM, 0); //socket(domain,type,protocol), PF_INET; ipv4 as protocol, AF_INET; Internet domain, resulting in a stream socket with the TCP.

	memset(&s_addr, 0, sizeof(s_addr)); //memset(void *str, int c, size_t n), str;this is a pointer to the block of memor to fill. c; This is the value to be set. n;This is the number of bytes to be set to the value.
	s_addr.sin_addr.s_addr=htonl(INADDR_ANY); //load with inet_aton(). htonl; converting a u_long from host to TCP/IP network byte order
	s_addr.sin_family=AF_INET; //ipv4 as address
	s_addr.sin_port=htons(PORT); //htons; host to network short.

	if(bind(s_socket,(struct sockaddr *)&s_addr, sizeof(s_addr))==-1){ //(int sockfd,const struct sockaddr *addr, socklen_t addrlen) sockfd;a descriptor representing the socket to perform the bind on. my_addr; a pointer to a sockaddr structure representing the address to bind to.addrlen; a socklen_t field specifying the size of the sockaddr structure, returns 0 on success and -1 if an error occurs.
		printf("Can not Bind\n");
		return -1;
	}
	if(listen(s_socket, 5)==-1){ //(int sockfd, int backlog) sockfd;a valid socket descriptor. backlog; an integer representing the number of pending connections that can be queued up at any one time. On success, 0 is returned. If an error occurs, -1 is returned.
		printf("listen Fail\n");
		return -1;
	}
	while(1){
		len=sizeof(c_addr); //size of client address
		c_socket=accept(s_socket,(struct sockaddr *)&c_addr, &len); //(int sockfd, struct sockaddr *addr, sockeln_t *addrlen, int flags) sockfd;the descriptor of the lisening socket that has the connection queued. cliaddr; a pointer to a sockaddr structure to receive the client's address information. addrlen; a pointer to a socklen_t location that specifies the size of the client address structure passed to accept(). returnss the new socket descriptor for the accepted connection, or -1 if an error occurs.
		n=strlen(buffer);
		write(c_socket, buffer, n); //(int fd, const void *buf, size_t count) fs;the file or socket desciptor. buf; The pointer to the buffer holding the data to be written. n; The length in bytes of the buffer pointed to by the buf parameter.
		close(c_socket); //close client socket.
	}
	close(s_socket); //close server socket.
}

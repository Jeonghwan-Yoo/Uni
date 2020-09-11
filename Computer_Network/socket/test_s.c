#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h> //memset
#include <unistd.h> //close read write

#define PORT 9000

char buffer[BUFSIZ]="hi, inu\n";
char buffer1[BUFSIZ]="welcome, incheon\n";

char rBuffer[BUFSIZ];

int main(){

	int c_socket, s_socket;
	struct sockaddr_in s_addr, c_addr;
	int len;
	int n;
	char *temp; //initialization
	int length; //initialization
	
	s_socket=socket(PF_INET, SOCK_STREAM, 0);

    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    s_addr.sin_family=AF_INET;
    s_addr.sin_port=htons(PORT);

    if(bind(s_socket,(struct sockaddr *)&s_addr, sizeof(s_addr))==-1){
            printf("Can not Bind\n");
            return -1;
    }
    if(listen(s_socket, 5)==-1){
            printf("listen Fail\n");
            return -1;
    }
	while(1){
		len=sizeof(c_addr);
		c_socket=accept(s_socket,(struct sockaddr *)&c_addr,&len);
		loop:
		length=0;
		temp=rBuffer;
		while((n=read(c_socket,temp,1))>0) { //read temp as 1 byte in c_socket  
			if(*temp=='\r') continue; //if \r, continue.
       	    if(*temp=='\n') break; //if \n, break.
            if(*temp=='\0') break; //if \0, break.				
			if(length==BUFSIZ)  break; //if length size is same as BUFSIZ, break.
			temp++; //next character.			length++; //next charater size.
			length++;
		}
		rBuffer[length]='\0'; //last character should be null.

	    if(!strcmp(rBuffer,"inu")){ //if rBuffer is print,
        	n=strlen(buffer); //n is for buffer size.
            write(c_socket,buffer,n); //write buffer.

        }
        if(!strcmp(rBuffer,"incheon")){
            n=strlen(buffer1);
            write(c_socket,buffer1,n);
        }
		goto loop;
		close(c_socket);
	}
	close(s_socket);
}


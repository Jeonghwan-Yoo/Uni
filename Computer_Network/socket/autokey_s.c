#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h> //memset
#include <unistd.h> //close read write

#define PORT 9000

char buffer[BUFSIZ]="helloworld";
char rBuffer[BUFSIZ]; //initialization

int key=5; //autokey(0~25).

int autokey_cipher(char* plain, int _key){
	char stream[20];
    stream[0]=_key;
    for(int i=1;i<strlen(plain);i++){
        stream[i]=plain[i-1]-'a';
    }
	plain[0]=(plain[0]+stream[0])%26+'a';	
    for(int i=1;i<strlen(plain);i++){
        char temp=plain[i]-'a';
        temp=(temp+stream[i])%26;
        plain[i]=temp+'a';
    }
    return 1;
}

int autokey_decipher(char* cipher,int _key){
    char temp[20];
	temp[0]=cipher[0]-'a'-_key;
	for(int i=1;i<strlen(cipher);i++){
		temp[i]=cipher[i]-'a'-temp[i-1];
		if(temp[i]<0){
			temp[i]+=26;
		}
	}
	for(int i=0;i<strlen(cipher);i++){
		cipher[i]=temp[i]+'a';
	}	
    return 1;
}

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

		length=0;
		temp=rBuffer;
		while((n=read(c_socket,temp,1))>0){ //read temp as 1 byte in c_socket  
			if(*temp=='\r') continue; //if \r, continue.
			if(*temp=='\n') break; //if \n, break.
			if(*temp=='\0') break; //if \0, break.

			if(length==BUFSIZ)  break; //if length size is same as BUFSIZ, break.
			temp++; //next character.
			length++; //next charater size.
		}
		rBuffer[length]='\0'; //last character should be null.
		printf("received message : %s\n",rBuffer);
		autokey_decipher(rBuffer,key); //decipher message.
		printf("%s",rBuffer);
		if(!strcmp(rBuffer,"print")){ //if rBuffer is print,
			n=strlen(buffer); //n is for buffer size.
			autokey_cipher(buffer,key); //cipher data.
			write(c_socket,buffer,n); //write buffer.
			autokey_decipher(buffer,key); //reset.
		}
		close(c_socket);
	}
	close(s_socket);
}

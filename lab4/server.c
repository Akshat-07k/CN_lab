#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
int main()
{

    // SOCKET
    int cid = socket(AF_INET, SOCK_DGRAM, 0);
    if (cid == -1)
    {
        printf(" Server is not Ready  ");
        return 0;
    }

    // BIND
    struct sockaddr_in sock;
	sock.sin_family = AF_INET;
	sock.sin_port = 1030;
	sock.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	int bindInt = bind(cid, (struct sockaddr *)&sock, sizeof(sock));
	    if (bindInt == -1)
	    {
		printf(" -------------Bind Uncessfull--------------\n ");
		return 0;
	    }
	    
	  struct sockaddr_in from;
	  char data[100];
	  int recv,k;
	 recv = recvfrom(cid , data , 100, 0 , (struct sockaddr*)&from , &k);
	 if(recv==-1)
	 {
	 	printf(" Error on recv ");
	 	return 0;
	 }
	 printf(" %s",data);
	 

    // close(cid);
    printf(" Khudos SERVER  is ready ");
    return 0;
}

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
// int socket(AF_INET, SOCK_DGRAM, 0);

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
    sock.sin_addr.s_addr = inet_addr("10.5.77.175");

    int bindInt = bind(cid, (struct sockaddr *)&sock, sizeof(sock));
    if (bindInt == -1)
    {
        printf(" -------------Bind Uncessfull--------------\n ");
    }

    struct sockaddr_in from;
    from.sin_family = AF_INET;
    from.sin_port = 1040;
    from.sin_addr.s_addr = inet_addr("10.5.77.175");

    // char send[100]={"abcd"};
    // scanf(" %s",&send);

    // int bc = sendto(cid , send, sizeof(send), 0 , (struct sockaddr*)&to, sizeof(to));
    int bc = bind(cid, (struct sockaddr *)&sock, sizeof(sock));
    if (bc == -1 || bc == 0)
    {
        printf(" Fail ");
        return 0;
    }

    // close(cid);
    printf(" Khudos Client  is ready ");
    return 0;
}
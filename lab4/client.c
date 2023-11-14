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
        printf(" CLient is not Ready  ");
        return 0;
    }

    // BIND
    struct sockaddr_in sock;

    sock.sin_family = AF_INET;
    sock.sin_port = 1040;
    sock.sin_addr.s_addr = inet_addr("10.0.2.15");

    int bindInt = bind(cid, (struct sockaddr *)&sock, sizeof(sock));
    if (bindInt == -1)
    {
        printf(" -------------Bind Uncessfull--------------\n ");
        return 0;
    }

    struct sockaddr_in to;
    to.sin_family = AF_INET;
    to.sin_port = 1030;
    to.sin_addr.s_addr = inet_addr("127.0.0.1");

    char send[100] = {"abcd"};
    // scanf(" %s",&send);

    int bc = sendto(cid, send, sizeof(send), 0, (struct sockaddr *)&to, sizeof(to));
    if (bc == -1 || bc == 0)
    {
        printf(" Fail ");
        return 0;
    }

    // close(cid);
    printf(" Kudos Client  is ready ");
    return 0;
}

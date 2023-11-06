#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>


int main() {
    int cid;
    struct sockaddr_in cadd;

    cid = socket(AF_INET, SOCK_STREAM, 0);
    if (cid == -1) {
        printf("Socket not created on client side");
        exit(0);
    }
    printf("Socket created on client side\n");

    cadd.sin_family = AF_INET;
    cadd.sin_port = htons(1030);
    cadd.sin_addr.s_addr = inet_addr("10.2.244.200");

    if (connect(cid, (struct sockaddr *)&cadd, sizeof(cadd)) == -1) {
        printf("Connection failed");
        exit(0);
    }
    printf("Connected to server\n");

    char cstr[100];
    while (1) {
        printf("Client message: ");
        scanf("%s", cstr);

        send(cid, cstr, strlen(cstr), 0);
        printf("Message sent\n");

        if (strcmp(cstr, "exit") == 0) {
            printf("Chat ended. Closing connection.\n");
            break;
        }
    }

    close(cid);

    return 0;
}
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>


int main() {
    int sid, new_socket;
    struct sockaddr_in sadd, cadd;
    socklen_t addrlen = sizeof(cadd);

    //sock 
    sid = socket(AF_INET, SOCK_STREAM, 0);
    if (sid == -1) {
        printf("Socket not created on server side");
        exit(0);
    }
    printf("Socket created on server side\n");

    sadd.sin_family = AF_INET;
    sadd.sin_port = htons(1030);
    sadd.sin_addr.s_addr = INADDR_ANY;


    //bind
    if (bind(sid, (struct sockaddr *)&sadd, sizeof(sadd)) == -1) {
        printf("Binding unsuccessful");
        exit(0);
    }
    printf("Binding successful\n");

    if (listen(sid, 5) == -1) {
        printf("Listening failed");
        exit(0);
    }
    printf("Listening for incoming connections...\n");

    new_socket = accept(sid, (struct sockaddr *)&cadd, &addrlen);
    if (new_socket == -1) {
        printf("Acceptance failed");
        exit(0);
    }
    printf("Accepted connection from client\n");

    char cstr[100];
    char sstr[100];
    while (1) {
        int bytes_received = recv(new_socket, sstr, sizeof(sstr), 0);
        if (bytes_received <= 0) {
            printf("Message not received"); 
            exit(0);
        }
    sstr[bytes_received] = '\0';
        printf("Received message: %s\n", sstr);

        if (strcmp(sstr, "END") == 0) {
            printf("Chat ended. Closing connection.\n");
            break;
        }

        //after 

        printf("Client message: ");
        scanf("%s", cstr);

        send(sid, cstr, strlen(cstr), 0);
        printf("Message sent\n");

        if (strcmp(cstr, "END") == 0) {
            printf("Chat ended. Closing connection.\n");
            break;
        }
    }

    close(new_socket);
    close(sid);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>




int main() {

    int cliSock;
    char data[1000];


    //  socket
    cliSock = socket(AF_INET, SOCK_STREAM, 0);



    // Server address structure
    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(12345);
    serv.sin_addr.s_addr = inet_addr("10.2.244.200");


    

    // Connect to the server
    connect(cliSock, (struct sockaddr*)&serv, sizeof(serv));
    printf("Connected with server.\n");

    while (true) {


        // Send data to server
        printf("data to send to the server :  ");
        // scanf("%s",data);
        fgets(data, sizeof(data), stdin);
                if(strcmp(data,"END\n")==0){
            // printf(" ___ BYE ___");
            // return 0;
            // exit(0);break;
            break;
        }
        send(cliSock, data, sizeof(data), 0);

         // Receive data - server

        recv(cliSock, &data, sizeof(data), 0);
        if(strcmp(data,"END\n")==0){
            // printf(" ___ BYE ___");
            // return 0;
            // exit(0);break;
            break;
        }
        printf("Received from server : %s", data);
    }

    // Close the socket
    close(cliSock);

    return 0;
}
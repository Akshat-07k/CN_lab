#include <iostream>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

using namespace std;

int main() {
    int sockInt = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockInt < 0) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(1090);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    char data[100];

    cout << "Enter a message to send: ";
    fgets(data, sizeof(data), stdin);

    int sendInt = sendto(sockInt, data, strlen(data), 0, (struct sockaddr*)&server, sizeof(server));

    if (sendInt < 0) {
        perror("Error sending data");
        return 1;
    }

    cout << "Data sent to server" << endl;

    close(sockInt);

    return 0;
}

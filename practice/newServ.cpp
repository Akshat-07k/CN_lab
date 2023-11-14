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

    int bindInt = bind(sockInt, (sockaddr*)&server, sizeof(server));

    if (bindInt < 0) {
        perror("Error binding socket");
        return 1;
    }

    cout << "Binding and socket successful" << endl;

    struct sockaddr_in fromCli;
    socklen_t fromCliLen = sizeof(fromCli);  // Use socklen_t for size parameter

    char data[100];
    int recvInt = recvfrom(sockInt, data, sizeof(data), 0, (struct sockaddr*)&fromCli, &fromCliLen);

    if (recvInt < 0) {
        perror("Error receiving data");
        return 1;
    }

    cout << "Received data: " << data << endl;

    return 0;
}

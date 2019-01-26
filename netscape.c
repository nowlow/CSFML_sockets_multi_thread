#include <SFML/Network.h>
#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include "client.h"

void server(unsigned short port)
{
    Server server = server_create("Chat", port, sfIpAddress_getLocalAddress(), 10);

    printf("[%s:%d]\n", server.address.address, server.port);
    server_start(&server);
    server_destroy(&server);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return -1;
    server((unsigned short) atoi(argv[1]));
    return 0;
}
#include <SFML/Network.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "server.h"
#include "client.h"

Server server_create(char const *name, unsigned short port, sfIpAddress address, int max_clients)
{
    Server server;

    server.name = strdup(name);
    server.listener = sfTcpListener_create();
    server.port = port;
    server.address = address;
    server.clients = malloc(sizeof(Client) * max_clients);
    server.max_clients = max_clients;
    server.current_client = -1;
    return server;
}

void server_start(Server *server)
{
    if (sfTcpListener_listen(server->listener, server->port, server->address) != sfSocketDone)
        return;
    thread_manager(server);
    printf("Sucessfully call threads\n");
}

void server_destroy(Server *server)
{
    free(server->name);
    free(server->listener);
    free(server->clients);
    free(server);
}
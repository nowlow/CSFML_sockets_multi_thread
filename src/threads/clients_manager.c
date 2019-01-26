#include <SFML/Network.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "client.h"
#include "server.h"

void accept_clients(Server *server)
{
    Client client;
    char *name = malloc(sizeof(char) * 24);
    size_t recived;

    while (server->current_client < server->max_clients) {
        memset(name, 0, sizeof(char) * 24);
        client = client_create();
        if (sfTcpListener_accept(server->listener, &client.socket) != sfSocketDone)
            return;
        sfTcpSocket_send(client.socket, "Enter your name : ", 19);
        sfTcpSocket_receive(client.socket, name, 25, &recived);
        name[recived - 1] = 0;
        client_set_name(&client, name);
        client_set_address(&client);
        printf("new client > %s\n", name);
        server->current_client++;
        server->clients[server->current_client] = client;
    }
    while (1) {
        client = client_create();
        if (sfTcpListener_accept(server->listener, &client.socket) != sfSocketDone)
            return;
        sfTcpSocket_send(client.socket, "This server do not accept clients anymore.", 43);
    }
}
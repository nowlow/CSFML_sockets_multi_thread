#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Network.h>
#include "client.h"

Client client_create()
{
    Client client;

    client.socket = sfTcpSocket_create();
    client.address = sfTcpSocket_getRemoteAddress(client.socket);
    return client;
}

void client_set_name(Client *client, char const *name)
{
    client->name = strdup(name);
}

void client_set_address(Client *client)
{
    client->address = sfTcpSocket_getRemoteAddress(client->socket);
}

void client_destroy(Client *client)
{
    free(client->name);
    free(client);
}
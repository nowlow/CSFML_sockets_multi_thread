#ifndef SERVER_H_
#define SERVER_H_

#include "client.h"

typedef struct Server
{
    char *name;
    sfTcpListener *listener;
    unsigned short port;
    sfIpAddress address;
    Client *clients;
    int max_clients;
    int current_client;
} Server;

Server server_create(char const *name, unsigned short port, sfIpAddress address, int max_clients);
void server_start(Server *server);
void accept_clients(Server *server);
void server_destroy(Server *server);
void recive_messages(Server *server);
void thread_manager(Server *server);

#endif /* SERVER_H_ */
#ifndef CLIENT_H_
#define CLIENT_H_

typedef struct Client
{
    char *name;
    sfIpAddress address;
    sfTcpSocket *socket;
    sfSocketStatus status;
} Client;

Client client_create();
void client_set_name(Client *client, char const *name);
void client_set_address(Client *client);
void client_destroy(Client *client);

#endif /*CLIENT_H_*/
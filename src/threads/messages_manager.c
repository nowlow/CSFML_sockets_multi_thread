#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Network.h>
#include "server.h"
#include "client.h"

void send_messages(Client *sender, Server *server, char *message)
{
    for (int i = 0; i <= server->current_client; i += 1) {
        if (strcmp(server->clients[i].address.address, sender->address.address) != 0) {
            sfTcpSocket_send(server->clients[i].socket, sender->name, 24);
            sfTcpSocket_send(server->clients[i].socket, " sent message : ", 17);
            sfTcpSocket_send(server->clients[i].socket, strcat(message, "\n"), 500);
        }
    }
}

void recive_messages(Server *server)
{
    char *message = malloc(sizeof(char) * 500);
    size_t recived;

    while (1) {
        for (int current = 0; current < server->current_client + 1; current += 1) {
            if (sfTcpSocket_receive(server->clients[current].socket, message, 500, &recived) != sfSocketDone)
                return;
            else {
                message[recived - 1] = 0;
                if(message[0] != 0) {
                    printf("%s sent message : %s\n", server->clients[current].name, message);
                    send_messages(&server->clients[current], server, message);
                    memset(message, 0, sizeof(char) * 500);
                }
            }
        }
    }
}

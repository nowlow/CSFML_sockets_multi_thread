#include <SFML/Network.h>
#include <SFML/System/Thread.h>
#include "client.h"
#include "server.h"

void thread_manager(Server *server)
{
    sfThread *clients_accept = sfThread_create((void *) accept_clients, server);
    sfThread *message_manage = sfThread_create((void *) recive_messages, server);

    sfThread_launch(clients_accept);
    sfThread_launch(message_manage);
    sfThread_destroy(clients_accept);
}
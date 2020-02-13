#include "Lobby.hpp"

bool Lobby::addClient(Client *client)
{
    if (clients.size() >= 4)
        return (false);
    clients.push_back(client);
    return (true);
}
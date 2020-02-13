#if !defined(LOBBY_HPP)
#define LOBBY_HPP

#include <list>
#include "Clients/Client.hpp"

// see for thread automatically launch lobby when everybody ready
class Lobby
{
    private:
        int _id;
        std::string _name;
        std::list<Client*>clients;

    public:
        Lobby(int id, std::string name) : _id(id), _name(name) {};
        ~Lobby(){};
        int getId() { return _id; }
        std::string getName() { return _name; };
        int getClientsCount() { return clients.size(); };
        bool addClient(Client *client);
        bool start();
};


#endif // LOBBY_HPP


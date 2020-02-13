
#if !defined(MACRO)
#define MACRO

#include <iostream>

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 7171

#include <vector>

class Connector
{
    private:
    // client information
    private:
        int _id;
        int _lobby_id;
        bool _status;

    public:
        int getClientId() {return _id; };
        int getLobbyId() {return _lobby_id; };
        std::vector<std::string> getLobbies();
        std::string recv();
        bool send(std::string);
        bool connectToServer();

    public:
        Connector();
        ~Connector(){};
};

#endif // MACRO
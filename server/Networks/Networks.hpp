//
// EPITECH PROJECT, 2019
// Networks.hpp
// File description:
// Networks.hpp
//

#include "Clients/Client.hpp"
#include <list>

#if !defined(NETWORKS_HPP)
#define NETWORKS_HPP

#define SERVER_ADDR "127.0.0.1"
#define SERVER_PORT 7171

#include <list>
#include "Lobby.hpp"

class Networks
{
    private:
        boost::asio::io_service ios;
        udp::socket _socket;
        udp::endpoint remote_endpoint;
        std::list<Client*>clients;
  	    boost::array<char, 128> recv_buffer;
        std::list<Lobby*>_lobbies;


    // tools
    public:
        Client *getClient(int id);
        bool sendToClient(int id, std::string message);

    // interpreter commands
    public:
        typedef bool (Networks::*ptr)(std::string);
        std::map<std::string, ptr>_dictionnary;
        bool execute(std::string recv);
        void manageClient(std::string recv);
        bool createClient(std::string);
        bool getLobbies(std::string);
        bool selectLobby(std::string);
        bool createLobby(std::string);
        bool ready(std::string);

    public:
        Networks();
        ~Networks();
        bool run();
        // data receiver
        void handle_receive(const boost::system::error_code& error, std::size_t bytes);
        void start_receive();
};

#endif // NETWORKS_HPP
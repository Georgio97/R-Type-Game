
#if !defined(CLIENT_HPP)
#define CLIENT_HPP

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/thread.hpp>

using boost::asio::ip::udp;

class Client : public boost::enable_shared_from_this<Client>
{
    public:
        void send(const std::string& str);
        std::string recv();
        void start();

        Client(udp::endpoint &endpoint, int id, boost::asio::io_service &ios) :
            _endpoint(endpoint), _id(id)// _socket(ios, udp::endpoint(udp::v4(), 7171))
        {
        };

        int &getId() {return _id; }
        udp::endpoint &getEndp() {return _endpoint; }

    public:
        int _id;
        udp::endpoint _endpoint;
        bool _status;
        int _lobby_id;
};

#endif // CLIENT_HPP
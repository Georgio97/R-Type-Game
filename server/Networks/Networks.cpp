//
// EPITECH PROJECT, 2019
// Networks.cpp
// File description:
// Networks.cpp
//

#include "Networks.hpp"
#include <regex>

Networks::Networks() :
	_socket(ios, udp::endpoint(udp::v4(), SERVER_PORT))
{
	_dictionnary.clear();
	_dictionnary.insert( std::make_pair( "new client", &Networks::createClient ));
	_dictionnary.insert( std::make_pair( "[\\d] create lobby", &Networks::createLobby ));
	_dictionnary.insert( std::make_pair( "[\\d] select lobby [\\d]", &Networks::selectLobby ));
	_dictionnary.insert( std::make_pair( "[\\d] get lobbies", &Networks::getLobbies ));
	start_receive();
	clients.clear();
}

Networks::~Networks()
{
	_dictionnary.clear();
	clients.clear();
}

void Networks::start_receive()
{
	_socket.async_receive_from(
		boost::asio::buffer(recv_buffer), remote_endpoint,
		boost::bind(&Networks::handle_receive, this,
			boost::asio::placeholders::error,
			boost::asio::placeholders::bytes_transferred));
}

void Networks::handle_receive(const boost::system::error_code& error, std::size_t bytes)
{
	if (!error || error == boost::asio::error::message_size) {
		std::string data;
		std::copy(recv_buffer.begin(), recv_buffer.begin()+ bytes, std::back_inserter(data));
		Networks::manageClient(data);
		start_receive();
	}
}

Client *Networks::getClient(int id)
{
	for (Client *client : clients)
		if (client->getId() == id)
			return client;
}


bool Networks::sendToClient(int id, std::string message)
{
	Client *client = getClient(id);
	boost::system::error_code err;
	if (!client) {
		return false;
	}
	_socket.send_to(boost::asio::buffer(message), client->getEndp(), 0, err);
	return (true);
};


bool Networks::run()
{
	ios.run();
}
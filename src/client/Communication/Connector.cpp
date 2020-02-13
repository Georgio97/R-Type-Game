
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "Connector.hpp"

Connector::Connector() : _socket(ios), _endp(boost::asio::ip::address::from_string("127.0.0.1"), 7171)
{
    _socket.open(udp::v4());
    _id = -1;
    _status = false;
    _lobby_id = -1;
}

bool Connector::connectToServer()
{
	_socket.send_to(boost::asio::buffer("new client"), _endp);
	std::string res = recv();
    std::string id_str = res.substr(res.find(":") + 1, res.length());
	_id = std::stoi(id_str);
	return (true);
};

std::string Connector::recv()
{
  	boost::array<char, 128> recv_buf;
    udp::endpoint sender_endpoint;
    size_t len = _socket.receive_from(
        boost::asio::buffer(recv_buf), _endp);

	std::string data;
    std::copy(recv_buf.begin(), recv_buf.begin() + len, std::back_inserter(data));
	std::cout << "=>response: [" << data << "]" << std::endl;
	return data;
}

bool Connector::send(std::string message)
{

    std::string request = std::to_string(_id) + " " + message;
	std::cout << "request: [" << request << "]" << std::endl;
    _socket.send_to(boost::asio::buffer(request), _endp);
    return true;
};

std::vector<std::string> split(std::string stringToBeSplitted, std::string delimeter)
{
     std::vector<std::string> splittedString;
     int startIndex = 0;
     int  endIndex = 0;
     while( (endIndex = stringToBeSplitted.find(delimeter, startIndex)) < stringToBeSplitted.size() )
    {
       std::string val = stringToBeSplitted.substr(startIndex, endIndex - startIndex);
       splittedString.push_back(val);
       startIndex = endIndex + delimeter.size();
     }
     if(startIndex < stringToBeSplitted.size())
     {
       std::string val = stringToBeSplitted.substr(startIndex);
       splittedString.push_back(val);
     }
     return splittedString;
}

std::vector<std::string> Connector::getLobbies()
{
    send("get lobbies");
    std::string recv_string = recv();
    return split(recv_string, ",");
};

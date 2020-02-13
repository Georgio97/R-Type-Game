#include "../Networks.hpp"
#include <regex>

/*
    format:
        incoming message
            -> response
            (&& both response)
            (|| one response)

        new client
            => id

        client_id lobby list
            => ['id', 'persons_count', 'name'], ['id', 'persons_count', 'name']

        client_id select lobby [id]
            -> connected || error

        client_id create lobby
            -> lobby list

        client_id ready [ false || true ]
            -> ok
*/

bool Networks::execute(std::string recv)
{
    std::string input = recv.c_str();

    for(std::pair<std::string, Networks::ptr>command : _dictionnary ) {
        std::regex regex(command.first);
        if (std::regex_match(input, regex)) {
            ptr fp = _dictionnary[command.first];
            return ((this->*fp)(recv));
        }
    }
    return false;
}

void Networks::manageClient(std::string recv)
{
    std::cout << "request: [" << recv << "]" << std::endl;
    if (!execute(recv)) {
        std::string id_str = recv.substr(0, recv.find(" "));
        sendToClient(std::stoi(id_str), "ko");
        std::cout << "=>response: ko" << std::endl;
    }
}
#include "../Networks.hpp"

bool Networks::createClient(std::string input)
{
	int id =  clients.size();

	std::cout << "=> new client connection" << std::endl;
	Client *new_client = new Client(remote_endpoint,id, ios);
	clients.push_back(new_client);
	std::string response = "id:" + std::to_string(id);
    if (!sendToClient(id, response))
		return (false);
	return (true);
}

bool Networks::getLobbies(std::string param)
{
    std::string client_id = param.substr(0, param.find(" "));
	std::string lobbies = "";
	int i = 0;

	for (Lobby *lobby : _lobbies) {
		lobbies += std::to_string(lobby->getId()) + ':' + std::to_string(lobby->getClientsCount()) + "/4:" + lobby->getName();
		if (_lobbies.size() - 1!= i)
			lobbies += ",";
		i++;
	}
	std::cout << "lobbies: " << lobbies << std::endl;
	if (lobbies.length() == 0)
		lobbies =  "";
	sendToClient(std::stoi(client_id), lobbies);
	std::cout << "send message to client:" << lobbies << std::endl;
	return (true);
}

bool Networks::selectLobby(std::string param)
{
    std::string client_id = param.substr(0, param.find(" "));
    std::string lobby_id = param.substr(15, param.length());

	for (auto *lobby : _lobbies) {
		if (std::to_string(lobby->getId()) == lobby_id && lobby->addClient(getClient(std::stoi(client_id)))){
			sendToClient(std::stoi(client_id), "ok");
			std::cout << "=>response: [ok]" << std::endl;
			return true;
		}
	}
	std::cout << "not founded lobby" << std::endl;
	return (false);
}

bool Networks::createLobby(std::string param)
{
    std::string client_id = param.substr(0, param.find(" "));
	_lobbies.push_back(new Lobby(_lobbies.size(), "lobby_" + std::to_string(_lobbies.size())));
	std::string response = "ok lobby_id " + std::to_string(_lobbies.size());
	std::cout << "=>response: [" << response << "]" << std::endl;
	sendToClient(std::stoi(client_id), response);
	return (true);
}

bool Networks::ready(std::string)
{
	return (true);
}

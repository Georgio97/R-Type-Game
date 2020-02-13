//
// EPITECH PROJECT, 2019
// Core.cpp
// File description:
// Core.cpp
//

#include <iostream>
#include "Core.hpp"

#include "../GameManager/GameManager.hpp"
#include "../Networks/Networks.hpp"

bool Core::run()
{
    Networks server;
    GameManager manager;
    try {
        if (server.run()) {
            return (true);
        }
        std::cout << "server launched" << std::endl;

    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return (true);
}

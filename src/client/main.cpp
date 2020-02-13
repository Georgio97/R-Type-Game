//
// EPITECH PROJECT, 2019
// main.cpp
// File description:
// Gautier PLANCQ ~ main.cpp Source file
//

#include <iostream>
#include "Engine/Engine.hpp"
#include "Graphical/GraphicalManager/GraphicalManager.hpp"
#include "Graphical/AudioManager/Audio.hpp"
#include "Communication/Connector.hpp"
#include <SFML/Graphics.hpp>
#include <thread>

int main(int argc, char const *argv[])
{
    Connector connector;
    Engine *engine = new Engine();
    // drawMenu();

    try {
    connector.connectToServer();
    connector.send("create lobby");
    connector.recv();


    std::vector<std::string> lobbies = connector.getLobbies();

    for (auto lobby : lobbies) {
        std::cout << "lobby: " << lobby << std::endl;
    }

    // connector.getLobbies();
    } catch (const exception &e) {
        std::cout << "error:" << e.what() << std::endl;
    }

    engine->launch();
    return 0;
}

// int main(int argc, char const *argv[])
// {
// //    drawMenu();
//      try {
//          Engine *engine = new Engine();

//          engine->launch();
//      } catch (const exception &e) {
//          cerr << e.what() << endl;
//          return 84;
//      }
//      return 0;
// >>>>>>> f1c62e5699d0ed12890047b759785ca192d72316
// }

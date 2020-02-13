//
// EPITECH PROJECT, 2019
// main.cpp
// File description:
// Gautier PLANCQ ~ main.cpp Source file
//

#include <iostream>
#include "Core/Core.hpp"

int main()
{
        Core serverCore;

        try {
                if (serverCore.run())
                        return (0);
                else
                        return (84);
        } catch (const std::exception& ex) {
                std::cerr << "A server already running" << std::endl;
        }
}
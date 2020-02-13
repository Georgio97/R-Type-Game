//
// EPITECH PROJECT, 2020
// R-type
// File description:
// Audio Interface Structure - Georges
//

#ifndef _INTERFACE_AUDIO_HPP_
#define _INTERFACE_AUDIO_HPP_

#include <iostream>
#include <string>

class IAudio
{
private:

public:
    IAudio(){};
    ~IAudio(){};
    virtual void loadSound(const std::string &path) = 0;
    virtual void loadMusic(const std::string &path) = 0;
    virtual void musicPlay() = 0;
    virtual void musicPause() = 0;
    virtual void musicStop() = 0;
    virtual void musicSetVolume(const unsigned int volume) = 0;
    virtual void musicSetLoop(const bool isLoop) = 0;
    virtual void soundPlay() = 0;
    virtual void soundSetVolume(const unsigned int volume) = 0;
    virtual void soundSetLoop(const bool isLoop) = 0;
};

#endif

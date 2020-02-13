//
// EPITECH PROJECT, 2020
// R-Type
// File description:
// Audio structure - Georges
//

#ifndef		_AUDIO_HPP_
# define	_AUDIO_HPP_

#include	<SFML/Audio.hpp>
#include    <iostream>
#include	"IAudio.hpp"

class Audio : public IAudio
{
private:
    sf::Sound   _sound;
    sf::Music   _music;
    sf::SoundBuffer _buffer;
    std::string _path;

public:
    Audio();
    ~Audio() {};
    void loadSound(const std::string &path);
    void loadMusic(const std::string &path);
    void musicPlay();
    void musicPause();
    void musicStop();
    void musicSetVolume(const unsigned int volume);
    void musicSetLoop(const bool isLoop);
    void soundPlay();
    void soundSetVolume(const unsigned int volume);
    void soundSetLoop(const bool isLoop);

};

#endif

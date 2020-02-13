//
// EPITECH PROJECT, 2020
// R-type
// File description:
// Audio Manupilation - Georges
//

#include "Audio.hpp"

Audio::Audio()
{
    std::string path = getenv("PWD");
    std::string project = "CPP_rtype_2019/";
    _path = path.substr(0, path.find(project) + project.length());
}

void Audio::loadSound(const std::string &path)
{
    if (this->_sound.getBuffer())
        this->_sound.resetBuffer();
    try
    {
        if (!this->_buffer.loadFromFile(_path + path))
            throw("SFML AUDIO LOADSOUND: Can't load sound!" + _path + path);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    this->_sound.setBuffer(this->_buffer);
}

void Audio::loadMusic(const std::string &path)
{
    try
    {
        if (!this->_music.openFromFile(_path + path))
            throw("SFML AUDIO LOADMUSIC: Can't load music!" + _path + path);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Audio::musicPlay()
{
    this->_music.play();
}

void Audio::musicSetLoop(const bool isloop)
{
    this->_music.setLoop(isloop);
}

void Audio::musicSetVolume(const unsigned int volume)
{
    this->_music.setVolume(volume);
}

void Audio::musicPause()
{
    this->_music.pause();
}

void Audio::musicStop()
{
    this->_music.stop();
}

void Audio::soundPlay()
{
    this->_sound.play();
}

void Audio::soundSetLoop(const bool isloop)
{
    this->_sound.setLoop(isloop);
}

void Audio::soundSetVolume(const unsigned int volume)
{
    this->_sound.setVolume(volume);
}

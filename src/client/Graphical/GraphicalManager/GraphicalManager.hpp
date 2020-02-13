//
// EPITECH PROJECT, 2019
// GraphicalManager.hpp
// File description:
// Gautier PLANCQ ~ GraphicalManager.hpp Include file
//

#if !defined(GraphicalManager_HPP)
#define GraphicalManager_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include <limits>
#include <memory>

typedef struct sprite_s {
    std::string id;
    sf::Sprite  sprite;
    sf::Texture texture;
    bool isVisible;
} sprite_t;

typedef struct text_s {
    std::string id;
    sf::Font    font;
    sf::Text    text;
    bool isVisible;
} text_t;

typedef struct rclock_s {
    std::string id;
    sf::Clock clock;
} rclock_t;

typedef struct pos_s {
    int x;
    int y;
} pos_t;

typedef struct rect_s {
    int left;
    int top;
    int width;
    int height;
} rect_t;

typedef struct rtime_s {
    int64_t microseconds;
    int32_t milliseconds;
    float seconds;
} rtime_t;

enum Events {
    NOTHING = -1, CLOSE, LEFT_ARROW, RIGHT_ARROW, DOWN_ARROW, UP_ARROW, LEFT_CLICK, RIGHT_CLICK, ESC, ENTER, RETURN
};

class GraphicalManager
{
    private:
        sf::RenderWindow    _window;
        sf::Event           _event;
        std::list<std::shared_ptr<sprite_t>> _sprites;
        std::list<std::shared_ptr<text_t>>   _texts;
        std::list<std::shared_ptr<rclock_t>>   _clocks;
        std::string _path;

        std::list<std::shared_ptr<sprite_t>>::iterator findSpriteById(const std::string &id);
        std::list<std::shared_ptr<text_t>>::iterator findTextById(const std::string &id);
        std::list<std::shared_ptr<rclock_t>>::iterator findClockById(const std::string &id);
    public:
        GraphicalManager(size_t screenWidth, size_t screenHeight, std::string title);
        ~GraphicalManager();
        int createSprite(const std::string &id, const std::string &path, bool isVisible = true);
        int createClock(const std::string &id);
        int createText(const std::string &id, const std::string &path, const std::string &text, size_t fontSize, bool isVisible = true);
        int setSpritePosition(const std::string &id, pos_t pos);
        int setSpriteRotation(const std::string &id, float angle);
        int setSpriteScale(const std::string &id, float xFactor, float yFactor);
        int setSpriteTextureRect(const std::string &id, rect_t rect);
        int setTextPosition(const std::string &id, pos_t pos);
        int removeSprite(const std::string &id);
        int removeText(const std::string &id);
        int removeClock(const std::string &id);
        int restartClock(const std::string &id);
        rtime_t getClockElapsedTime(const std::string &id);
        size_t getNbSprites();

        pos_t getSpritePosition(const std::string &id);
        pos_t getTextPosition(const std::string &id);
        rect_t getSpriteLocalBounds(const std::string &id);
        rect_t getSpriteGlobalBounds(const std::string &id);

        bool spriteIsVisible(const std::string &id);
        bool spriteIsVisible(const std::string &id, bool isVisible);
        bool textIsVisible(const std::string &id);
        bool textIsVisible(const std::string &id, bool isVisible);

        void display();
        void drawAllSprites();
        void drawAllTexts();
        void drawSprite(const std::string &id);
        void drawText(const std::string &id);
        void clearSprites();
        void clearTexts();
        void clearClocks();
        void clear();
        void close();
        bool isOpen();
        
        bool onEvent();
        Events getEvent();
        pos_t getMousePosition();
};

#endif // GraphicalManager_HPPGAME

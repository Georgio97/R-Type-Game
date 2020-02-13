//
// EPITECH PROJECT, 2019
// GraphicalManager.cpp
// File description:
// Gautier PLANCQ ~ GraphicalManager.cpp Source file
//

#include "GraphicalManager.hpp"

int GraphicalManager::createSprite(const std::string &id, const std::string &path, bool isVisible)
{
    std::shared_ptr<sprite_t> newSprite(new sprite_s);

    newSprite->id = id;
    if (!newSprite->texture.loadFromFile(_path + path)) {
        std::cerr << "[ERROR] Couldn't load texture" << std::endl;
        return 84;
    }
    newSprite->isVisible = isVisible;
    newSprite->sprite.setTexture(newSprite->texture);
    _sprites.push_back(newSprite);
    return 0;
}

int GraphicalManager::createText(const std::string &id, const std::string &path, const std::string &text, size_t fontSize, bool isVisible)
{
    std::shared_ptr<text_t> newText(new text_t);

    newText->id = id;
    if (!newText->font.loadFromFile(path)) {
        std::cerr << "[ERROR] Couldn't load font" << std::endl;
        return 84;
    }
    newText->isVisible = isVisible;
    newText->text = sf::Text(text, newText->font, fontSize);
    _texts.push_back(newText);
    return 0;
}

int GraphicalManager::removeSprite(const std::string &id)
{
    auto sprite = findSpriteById(id);

    if (sprite == _sprites.end())
        return 84;
    _sprites.erase(sprite);
    return 0;
}

int GraphicalManager::createClock(const std::string &id)
{
    std::shared_ptr<rclock_t> newClock(new rclock_s);

    newClock->id = id;
    _clocks.push_back(newClock);
    return 0;
}

int GraphicalManager::removeText(const std::string &id)
{
    auto text = findTextById(id);

    if (text == _texts.end())
        return 84;
    _texts.erase(text);
    return 0;
}

int GraphicalManager::removeClock(const std::string &id)
{
    auto clock = findClockById(id);

    if (clock == _clocks.end())
        return 84;
    _clocks.erase(clock);
    return 0;
}

std::list<std::shared_ptr<sprite_t>>::iterator GraphicalManager::findSpriteById(const std::string &id)
{
    for (auto it = _sprites.begin(); it != _sprites.end(); it++)
        if ((*it)->id == id)
            return it;
    return _sprites.end();
}

std::list<std::shared_ptr<text_t>>::iterator GraphicalManager::findTextById(const std::string &id)
{
    for (auto it = _texts.begin(); it != _texts.end(); it++)
        if ((*it)->id == id)
            return it;
    return _texts.end();
}

std::list<std::shared_ptr<rclock_t>>::iterator GraphicalManager::findClockById(const std::string &id)
{
    for (auto it = _clocks.begin(); it != _clocks.end(); it++)
        if ((*it)->id == id)
            return it;
    return _clocks.end();
}

int GraphicalManager::setSpritePosition(const std::string &id, pos_t pos)
{
    std::list<std::shared_ptr<sprite_t>>::iterator sprite = findSpriteById(id);

    if (sprite == _sprites.end())
        return 84;
    (*sprite)->sprite.setPosition(sf::Vector2f(pos.x, pos.y));
    return 0;
}

int GraphicalManager::setSpriteRotation(const std::string &id, float angle)
{
    std::list<std::shared_ptr<sprite_t>>::iterator sprite = findSpriteById(id);

    if (sprite == _sprites.end())
        return 84;
    (*sprite)->sprite.setRotation(angle);
    return 0;
}

int GraphicalManager::setSpriteScale(const std::string &id, float xFactor, float yFactor)
{
    std::list<std::shared_ptr<sprite_t>>::iterator sprite = findSpriteById(id);

    if (sprite == _sprites.end())
        return 84;
    (*sprite)->sprite.setScale(xFactor, yFactor);
    return 0;
}

int GraphicalManager::setSpriteTextureRect(const std::string &id, rect_t rect)
{
    std::list<std::shared_ptr<sprite_t>>::iterator sprite = findSpriteById(id);
    sf::IntRect sfRect = {rect.left, rect.top, rect.width, rect.height};

    if (sprite == _sprites.end())
        return 84;
    (*sprite)->sprite.setTextureRect(sfRect);
    return 0;
}

int GraphicalManager::setTextPosition(const std::string &id, pos_t pos)
{
    std::list<std::shared_ptr<text_t>>::iterator text = findTextById(id);

    if (text == _texts.end())
        return 84;
    (*text)->text.setPosition(sf::Vector2f(pos.x, pos.y));
    return 0;
}

pos_t GraphicalManager::getSpritePosition(const std::string &id)
{
    std::list<std::shared_ptr<sprite_t>>::iterator sprite = findSpriteById(id);
    pos_t pos;

    if (sprite == _sprites.end())
        return {std::numeric_limits<int>::min(), std::numeric_limits<int>::min()};
    pos.x = (*sprite)->sprite.getPosition().x;
    pos.y = (*sprite)->sprite.getPosition().y;
    return pos;
}

rect_t GraphicalManager::getSpriteLocalBounds(const std::string &id)
{
    std::list<std::shared_ptr<sprite_t>>::iterator sprite = findSpriteById(id);
    rect_t rect;

    if (sprite == _sprites.end())
        return {std::numeric_limits<int>::min(), std::numeric_limits<int>::min(),
                std::numeric_limits<int>::min(), std::numeric_limits<int>::min()};
    rect.left = (*sprite)->sprite.getLocalBounds().left;
    rect.top = (*sprite)->sprite.getLocalBounds().top;
    rect.width = (*sprite)->sprite.getLocalBounds().width;
    rect.height = (*sprite)->sprite.getLocalBounds().height;
    return rect;
}

rect_t GraphicalManager::getSpriteGlobalBounds(const std::string &id)
{
    std::list<std::shared_ptr<sprite_t>>::iterator sprite = findSpriteById(id);
    rect_t rect;

    if (sprite == _sprites.end())
        return {std::numeric_limits<int>::min(), std::numeric_limits<int>::min(),
                std::numeric_limits<int>::min(), std::numeric_limits<int>::min()};
    rect.left = (*sprite)->sprite.getGlobalBounds().left;
    rect.top = (*sprite)->sprite.getGlobalBounds().top;
    rect.width = (*sprite)->sprite.getGlobalBounds().width;
    rect.height = (*sprite)->sprite.getGlobalBounds().height;
    return rect;
}

pos_t GraphicalManager::getTextPosition(const std::string &id)
{
    std::list<std::shared_ptr<text_t>>::iterator text = findTextById(id);
    pos_t pos;

    if (text == _texts.end())
        return {std::numeric_limits<int>::min(), std::numeric_limits<int>::min()};
    pos.x = (*text)->text.getPosition().x;
    pos.y = (*text)->text.getPosition().y;
    return pos;
}

void GraphicalManager::drawAllSprites()
{
    for (auto it = _sprites.begin(); it != _sprites.end(); it++)
        if ((*it)->id != "error" && (*it)->isVisible)
            _window.draw((*it)->sprite);
}

void GraphicalManager::drawAllTexts()
{
    for (auto it = _texts.begin(); it != _texts.end(); it++)
        if ((*it)->id != "error" && (*it)->isVisible)
            _window.draw((*it)->text);
}

void GraphicalManager::drawSprite(const std::string &id)
{
    std::list<std::shared_ptr<sprite_t>>::iterator sprite = findSpriteById(id);

    if (sprite != _sprites.end())
        _window.draw((*sprite)->sprite);
}

void GraphicalManager::drawText(const std::string &id)
{
    std::list<std::shared_ptr<text_t>>::iterator text = findTextById(id);

    if (text != _texts.end())
        _window.draw((*text)->text);
}

bool GraphicalManager::spriteIsVisible(const std::string &id)
{
    std::list<std::shared_ptr<sprite_t>>::iterator sprite = findSpriteById(id);

    if (sprite == _sprites.end())
        return false;
    return (*sprite)->isVisible;
}

bool GraphicalManager::spriteIsVisible(const std::string &id, bool isVisible)
{
    std::list<std::shared_ptr<sprite_t>>::iterator sprite = findSpriteById(id);

    if (sprite == _sprites.end())
        return false;
    (*sprite)->isVisible = isVisible;
    return (*sprite)->isVisible;
}

bool GraphicalManager::textIsVisible(const std::string &id)
{
    std::list<std::shared_ptr<text_t>>::iterator text = findTextById(id);

    if (text == _texts.end())
        return false;
    return (*text)->isVisible;
}

bool GraphicalManager::textIsVisible(const std::string &id, bool isVisible)
{
    std::list<std::shared_ptr<text_t>>::iterator text = findTextById(id);

    if (text == _texts.end())
        return false;
    (*text)->isVisible = isVisible;
    return (*text)->isVisible;
}

void GraphicalManager::display()
{
    _window.display();
}

void GraphicalManager::clear()
{
    _window.clear();
}

bool GraphicalManager::isOpen()
{
    return _window.isOpen();
}

void GraphicalManager::close()
{
    _window.close();
}

void GraphicalManager::clearSprites()
{
    _sprites.clear();
}

void GraphicalManager::clearTexts()
{
    _texts.clear();
}

void GraphicalManager::clearClocks()
{
    _clocks.clear();
}

int GraphicalManager::restartClock(const std::string &id)
{
    std::list<std::shared_ptr<rclock_t>>::iterator clock = findClockById(id);

    if (clock == _clocks.end())
        return 84;
    (*clock)->clock.restart();
    return 0;
}

rtime_t GraphicalManager::getClockElapsedTime(const std::string &id)
{
    std::list<std::shared_ptr<rclock_t>>::iterator clock = findClockById(id);
    sf::Time sfTime;
    rtime_t time;

    if (clock == _clocks.end())
        return {-84, -84, -84};
    sfTime = (*clock)->clock.getElapsedTime();
    time.microseconds = sfTime.asMicroseconds();
    time.milliseconds = sfTime.asMilliseconds();
    time.seconds = sfTime.asSeconds();
    return time;
}

bool GraphicalManager::onEvent()
{
    return _window.pollEvent(_event);
}

Events GraphicalManager::getEvent()
{
    if (_event.type == sf::Event::Closed)
        return Events::CLOSE;
    else if (_event.type  == sf::Event::KeyReleased) {
        switch (_event.key.code) {
            case (sf::Keyboard::Left):
                return Events::LEFT_ARROW;
            case (sf::Keyboard::Right):
                return Events::RIGHT_ARROW;
            case (sf::Keyboard::Down):
                return Events::DOWN_ARROW;
            case (sf::Keyboard::Up):
                return Events::UP_ARROW;
            case (sf::Keyboard::Escape):
                return Events::ESC;
            case (sf::Keyboard::Return):
                return Events::ENTER;
            case (sf::Keyboard::BackSpace):
                return Events::RETURN;
        }
    } else {
        if (_event.type == sf::Event::MouseButtonReleased) {
            switch (_event.mouseButton.button) {
                case (sf::Mouse::Button::Left) :
                    return Events::LEFT_CLICK;
                case (sf::Mouse::Button::Right) :
                    return Events::RIGHT_CLICK;
            }
        }
    }
    return Events::NOTHING;
}

size_t GraphicalManager::getNbSprites()
{
    return _sprites.size();
}

pos_t GraphicalManager::getMousePosition()
{
    sf::Vector2i vect = sf::Mouse::getPosition(_window);
    pos_t pos = {vect.x, vect.y};

    return pos;
}

GraphicalManager::GraphicalManager(size_t screenWidth, size_t screenHeight, std::string title)
{
    std::string path = getenv( "PWD" );
    std::string project = "CPP_rtype_2019/";
    _path = path.substr(0, path.find(project) + project.length());
    _window.create(sf::VideoMode(screenWidth, screenHeight), title);
}

GraphicalManager::~GraphicalManager()
{};
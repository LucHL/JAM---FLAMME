/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Car
*/

#include "Car.hpp"

Car::Car() {
    std::srand(std::time(nullptr));
    _color = std::rand() % 4;
    //_type = std::rand() % 2;
    _type = 1;
    _dir = std::rand() % 2;
    _speed = 1;
    _pos.x = 0;
    _pos.y = 0;
    if (_type == 0)
        buildClassic();
    else
        buildBus();
}

Car::~Car() {}

bool Car::isPlayerCollision() {
    return false;
}

void Car::buildClassic() {
    return;
}

void Car::draw(sf::RenderWindow &w) {
    w.draw(_sprite);
}

void Car::buildBus() {
    sf::Vector2i pos = {0, 0};
    sf::IntRect rect;

    if (_color % 2 != 0)
        pos.y += 384;
    if (_color > 1)
        pos.x += 432;
    if (_dir == 1)
        pos.y += 192;
    rect.top = pos.y;
    rect.left = pos.x;
    rect.height = 192;
    rect.width = 336;
    _texture.loadFromFile("assets/characters/bus_2.png", rect);
    _sprite.setTexture(_texture, true);
}

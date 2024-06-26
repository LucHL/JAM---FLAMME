/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Car
*/

#include "Car.hpp"

Car::Car(int id, int pos_y, int road_size, unsigned int *gameSeed) {
    std::srand(*gameSeed);
    *gameSeed += 324;
    _color = std::rand() % 4;
    _type = std::rand() % 2;
    _dir = std::rand() % 2;
    _speed = 1;
    if (_type == 0) {
        _pos.x = (_dir == 1) ? -55 : 1840;
        _pos.y = pos_y - road_size * 0.92f + 3 + id * 96 - id * 15;
        buildClassic();
        _sprite.setScale((sf::Vector2f){0.65f, 0.65f});
    } else {
        _pos.x = (_dir == 1) ? -75 : 1830;
        _pos.y = pos_y - road_size * 0.92f + 10 + id * 96 - id * 15;
        buildBus();
        _sprite.setScale((sf::Vector2f){0.45f, 0.45f});
    }
    _sprite.setPosition(_pos);
}

Car::~Car() {}

bool Car::isPlayerCollision(const sf::Sprite &playerSprite) {
    sf::FloatRect collisionBox1 = _sprite.getGlobalBounds();
    sf::FloatRect collisionBox2 = playerSprite.getGlobalBounds();

    return collisionBox1.intersects(collisionBox2);
}

void Car::draw(sf::RenderWindow &w) {
    w.draw(_sprite);
}

void Car::buildClassic() {
    sf::Vector2i pos = {192, 0};
    sf::IntRect rect;

    pos.y += 144 * _color;
    if (_dir == 0){
        pos.x += 384;
        pos.y += 96;
    }
    rect.top = pos.y;
    rect.left = pos.x;
    rect.height = 144;
    rect.width = 192;
    _texture.loadFromFile("assets/characters/car.png", rect);
    _sprite.setTexture(_texture, true);
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

void Car::moveCar() {
    _pos.x = (_dir == 1) ? _pos.x + 20 * _speed : _pos.x - 20 * _speed;
    _sprite.setPosition(_pos);
}

void Car::moveWorldCar() {
    _pos.y += (32 * 0.92f);
    _sprite.setPosition(_pos);
}

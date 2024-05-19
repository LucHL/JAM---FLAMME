/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Road
*/

#include "Road.hpp"

Road::Road(bool isHighway, int maxCarCount) {
    std::srand(std::time(nullptr));
    _isHighway = isHighway;
    _type = std::rand() % 4;
    _maxCarCount = maxCarCount;
    _pos.x = 0;
    _pos.y = 0;
    // remplir de voitures jusqu'à lim voie + luck
    createCar(std::make_shared<Car>());
    if (_isHighway)
        buildHighway();
    else
        buildGrass();
}

Road::~Road() {}

void Road::draw(sf::RenderWindow &w) {
    w.draw(_spriteRoad);
    w.draw(_spriteCollision);
    for (auto &car : _list)
        (*car).draw(w);
}

void Road::createCar(std::shared_ptr<Car> car) {
    _list.push_back(car);
}

void Road::buildHighway() {
    sf::Vector2i pos = {0, 0};
    sf::IntRect rect;

    if (_type == 0)
        pos.y += 864;
    if (_type == 2)
        pos.y += 384;
    if (_type == 3)
        pos.y += 1152;
    rect.top = pos.y;
    rect.left = pos.x;
    rect.height = 96 * (_type + 1);
    rect.width = 2112;
    _textureRoad.loadFromFile("assets/map.png", rect);
    _spriteRoad.setTexture(_textureRoad, true);
    _textureCollision.loadFromFile("assets/collision.png", rect);
    _spriteCollision.setTexture(_textureCollision, true);
}

void Road::buildGrass() {
    sf::Vector2i pos = {0, 1728};
    sf::IntRect rect;

    pos.y += (_type * 288);
    rect.top = pos.y;
    rect.left = pos.x;
    rect.height = 96;
    rect.width = 2112;
    _textureRoad.loadFromFile("assets/map.png", rect);
    _spriteRoad.setTexture(_textureRoad, true);
    _textureCollision.loadFromFile("assets/collision.png", rect);
    _spriteCollision.setTexture(_textureCollision, true);
}

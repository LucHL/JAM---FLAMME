/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Road
*/

#include "Road.hpp"

Road::Road(bool isHighway, int maxCarCount, int *builderPos, unsigned int *gameSeed) {
    std::srand(*gameSeed);
    *gameSeed += 324;
    _isHighway = isHighway;
    _type = std::rand() % 4;
    _carCount = 0;
    _maxCarCount = maxCarCount;
    _pos.x = 0;
    _pos.y = *builderPos;
    if (_isHighway) {
        for (int i = 0; i < _type + 1; ++i)
            createCar(std::make_shared<Car>(_carCount++, *builderPos, (_type + 1) * 96, gameSeed)); // remplir de voitures jusqu'à lim voie + luck
        buildHighway(builderPos);
    } else
        buildGrass(builderPos);
    _spriteRoad.setScale((sf::Vector2f){0.92f, 0.92f});
    _spriteRoad.setPosition(_pos);
    _spriteCollision.setPosition(_pos);
}

Road::~Road() {}

void Road::draw(sf::RenderWindow &w) {
    w.draw(_spriteRoad);
    w.draw(_spriteCollision);
    for (auto &car : _list)
        car->draw(w);
}

void Road::moveWorldRoad() {
    _pos.y += (32 * 0.92f);
    _spriteCollision.setPosition(_pos);
    _spriteRoad.setPosition(_pos);
    for (auto &car : _list)
        car->moveWorldCar();
}

void Road::createCar(std::shared_ptr<Car> car) {
    _list.push_back(car);
}

sf::Sprite &Road::getCollisionSprite() {
    return _spriteCollision;
}

void Road::update() {
    for (auto &car : _list){
        (*car).moveCar();
        if ((*car).isPlayerCollision())
            exit(0);
    }
}

void Road::buildHighway(int *builderPos) {
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
    *builderPos -= (rect.height * 0.92f);
    _pos.y -= (rect.height * 0.92f);
}

void Road::buildGrass(int *builderPos) {
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
    *builderPos -= (rect.height * 0.92f);
    _pos.y -= (rect.height * 0.92f);
}

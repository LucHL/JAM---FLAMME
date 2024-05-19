/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Road
*/

#pragma once
#include "../scene/IScene.hpp"
#include "Car.hpp"

class Road {
public:
    Road(bool isHighway, int maxCarCount);
    ~Road();

    void buildHighway();
    void buildGrass();
    void createCar(std::shared_ptr<Car> car);
    void update();
    void draw(sf::RenderWindow &w);

private:
    sf::Texture _textureRoad;
    sf::Texture _textureCollision;
    sf::Sprite _spriteRoad;
    sf::Sprite _spriteCollision;
    sf::Vector2f _pos;
    std::vector<std::shared_ptr<Car>> _list;
    bool _isHighway;
    int _type;
    int _carCount;
    int _maxCarCount;
};

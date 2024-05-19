/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Car
*/

#pragma once
#include "../scene/IScene.hpp"

class Car {
public:
    Car();
    ~Car();

    bool isPlayerCollision();
    void buildClassic();
    void buildBus();
    void draw(sf::RenderWindow &w);

private:
    int _dir;
    int _speed;
    int _type;
    int _color;
    sf::Vector2i _pos;
    sf::Sprite _sprite;
    sf::Texture _texture;
};
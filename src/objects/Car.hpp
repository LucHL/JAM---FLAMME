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
    Car(int id, int pos_y, int road_size, unsigned int *gameSeed);
    ~Car();

    bool isPlayerCollision();
    void buildClassic();
    void buildBus();
    void moveCar();
    void draw(sf::RenderWindow &w);

private:
    int _dir;
    int _speed;
    int _type;
    int _color;
    sf::Vector2f _pos;
    sf::Sprite _sprite;
    sf::Texture _texture;
};

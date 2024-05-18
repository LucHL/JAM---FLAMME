/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Road
*/

#pragma once
#include "IScene.hpp"

typedef enum road_s {
    ROAD_GRASS,
    ROAD_ONE,
    ROAD_TWO,
    ROAD_THREE,
    ROAD_FOUR
} road_t;

class Road {
public:
    Road(bool is_highway);
    ~Road();

    void draw(sf::RenderWindow &w);

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Vector2i _pos;
    int _id;
};

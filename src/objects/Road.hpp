/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Road
*/

#pragma once
#include "../scene/IScene.hpp"
#include "Car.hpp"

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

private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::Vector2i _pos;
    std::vector<Car> _list;
    int _type;
    int _max_car_count;
};

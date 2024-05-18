/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Road
*/

#include "Road.hpp"

Road::Road(bool is_highway) {
    std::srand(std::time(nullptr));
    _id = is_highway ? std::rand() % 4 + 1 : 0;
}

Road::~Road() {}

void Road::draw(sf::RenderWindow &w) {
    w.draw(_sprite);
}

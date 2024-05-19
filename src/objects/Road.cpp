/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Road
*/

#include "Road.hpp"

Road::Road(bool is_highway) {
    std::srand(std::time(nullptr));
    _type = is_highway ? std::rand() % 4 + 1 : 0;
}

Road::~Road() {}

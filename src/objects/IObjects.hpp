/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** IObjects
*/

#pragma once
#include "../main.hpp"

class IObjects {
    public:
        virtual ~IObjects() = default;
        virtual void draw(sf::RenderWindow &w) = 0;
        virtual bool isHittable() = 0;
};

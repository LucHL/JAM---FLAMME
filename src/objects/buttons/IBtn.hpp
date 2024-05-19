/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** IObjects
*/

#pragma once
#include "../../main.hpp"
#include "../../scene/IScene.hpp"

class IBtn {
    public:
        virtual ~IBtn() = default;
        virtual void draw(sf::RenderWindow &w) = 0;
        virtual void update(sf::Event &e, sf::RenderWindow &w) = 0;
    private:
        virtual bool isMouseOver(sf::RenderWindow &w) = 0;
};

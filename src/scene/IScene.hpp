/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** IScene
*/

#pragma once
#include "../main.hpp"

enum sceneType {
    MAINMENU
};

class IScene {
    public:
        virtual ~IScene() = default;

        virtual void update(sf::Event &e) = 0;
        virtual void draw(sf::RenderWindow &w) = 0;
        virtual void initialize() = 0;
        virtual sceneType &getType() = 0;
};

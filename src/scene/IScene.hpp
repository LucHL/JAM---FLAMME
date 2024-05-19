/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** IScene
*/

#pragma once
#include "../main.hpp"

enum sceneType {
    MAINMENU,
    SETTINGS,
    GAMESCENE,
    LevelSelection
};

// extern sceneType currentScene = MAINMENU;

class IScene {
    public:
        virtual ~IScene() = default;

        virtual void draw() = 0;
        virtual void update(sf::Event &e) = 0;
        virtual void initialize() = 0;
};

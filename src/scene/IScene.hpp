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

        virtual void event() = 0;
        virtual void update() = 0;
        virtual void draw() = 0;
};

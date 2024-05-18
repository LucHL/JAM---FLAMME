/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Start
*/

#pragma once
#include "IScene.hpp"

class Start : public IScene {
    public:
        Start(std::string backgroundPath, std::string musicPath);
        ~Start();

        void event();
        void update();
        void draw();

    private:
        sf::Texture _backgroundText;
        sf::Sprite _backgroundSprite;
        sf::Music _m;
};

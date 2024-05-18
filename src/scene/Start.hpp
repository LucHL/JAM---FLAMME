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
        Start(std::string backgroundPath);
        ~Start();

        void update(sf::Event &e);
        void draw(sf::RenderWindow &w);
        void initialize();
        sceneType &getType();

    private:
        sf::Texture _backgroundText;
        sf::Sprite _backgroundSprite;
        sceneType _t;
};

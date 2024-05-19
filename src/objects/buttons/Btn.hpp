/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Btn
*/

#pragma once
#include "IBtn.hpp"
#include "../main.hpp"
#include "../scene/IScene.hpp"

class Btn : public IBtn {
    public:
        Btn(std::string path, sf::Vector2f p, sf::Vector2f len);
        ~Btn();

        void draw(sf::RenderWindow &w);
        void update(sf::Event &e, sceneType t);

    protected:
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Vector2f _pos;
        sf::Vector2f _len;
        sf::Vector2f _relPos;
};

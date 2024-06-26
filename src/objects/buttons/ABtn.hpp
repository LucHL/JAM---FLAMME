/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** ABtn
*/

#pragma once
#include "IBtn.hpp"

class ABtn : public IBtn {
    public:
        ABtn() {};
        ABtn(std::string path, sf::Vector2f p);
        ~ABtn();

        void draw(sf::RenderWindow &w);
        virtual void update(sf::Event &e, sf::RenderWindow &w) = 0;
        bool isMouseOver(sf::RenderWindow &w);

    protected:
        sf::Texture _texture;
        sf::Sprite _sprite;
};

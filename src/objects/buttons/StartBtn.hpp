/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** StartBtn
*/

#pragma once
#include "ABtn.hpp"

class StartBtn : public ABtn {
    public:
        StartBtn();
        ~StartBtn();

        void update(sf::Event &e);
        sf::Vector2f _pos;
        sf::Vector2f _len;
        sf::Vector2f _relPos;
};

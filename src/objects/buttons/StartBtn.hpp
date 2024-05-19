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

        void update(sf::Event &e, sf::RenderWindow &w);
};

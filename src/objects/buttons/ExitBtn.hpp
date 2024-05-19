/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** ExitBtn
*/

#pragma once
#include "ABtn.hpp"

class ExitBtn : public ABtn {
    public:
        ExitBtn(sf::Vector2f);
        ~ExitBtn();

        void update(sf::Event &e, sf::RenderWindow &w);
};

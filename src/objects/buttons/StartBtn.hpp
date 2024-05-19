/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** StartBtn
*/

#pragma once
#include "ABtn.hpp"
#include "../../scene/SceneManager.hpp"

class StartBtn : public ABtn {
    public:
        StartBtn(sf::Vector2f pos);
        ~StartBtn();

        void update(sf::Event &e, sf::RenderWindow &w);
};

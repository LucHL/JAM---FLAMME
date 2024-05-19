/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** SettingsBtn
*/

#pragma once
#include "ABtn.hpp"

class SettingsBtn : public ABtn {
    public:
        SettingsBtn(sf::Vector2f pos);
        ~SettingsBtn();

        void update(sf::Event &e, sf::RenderWindow &w);
};

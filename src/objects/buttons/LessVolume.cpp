/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** LessVolume.cpp
*/

#include "LessVolume.hpp"

LessVolumeBtn::LessVolumeBtn(sf::Vector2f pos): ABtn("assets/button/less.png", pos) {}

LessVolumeBtn::~LessVolumeBtn()
{
}

void LessVolumeBtn::update(sf::Event &e, sf::RenderWindow &w) {
    sf::Vector2i mp = sf::Mouse::getPosition();
    sf::Color base = _sprite.getColor();
    sf::Color over(base.r - 10, base.g - 10, base.b - 10);
    if (isMouseOver(w)) {
        _sprite.setColor(over);
        if (e.type == sf::Event::MouseButtonPressed) {
            float volume;
            volume = sf::Listener::getGlobalVolume();
            if (volume >= 10)
                sf::Listener::setGlobalVolume(volume - 10);
        }
    } else
        _sprite.setColor(base);
}
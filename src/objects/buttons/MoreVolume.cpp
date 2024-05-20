/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** MoreVolume.cpp
*/

#include "MoreVolume.hpp"

MoreVolumeBtn::MoreVolumeBtn(sf::Vector2f pos): ABtn("assets/button/plus.png", pos) {
    _sprite.scale(0.1f, 0.1f);
}

MoreVolumeBtn::~MoreVolumeBtn() {}

void MoreVolumeBtn::update(sf::Event &e, sf::RenderWindow &w) {
    sf::Vector2i mp = sf::Mouse::getPosition();
    sf::Color base = _sprite.getColor();
    sf::Color over(base.r - 10, base.g - 10, base.b - 10);
    if (isMouseOver(w)) {
        _sprite.setColor(over);
        if (e.type == sf::Event::MouseButtonPressed) {
            float volume;
            volume = sf::Listener::getGlobalVolume();
            if (volume != (float)100)
                sf::Listener::setGlobalVolume(volume + 10);
        }
    } else
        _sprite.setColor(base);
}
/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** StartBtn
*/

#include "StartBtn.hpp"

StartBtn::StartBtn(): ABtn("assets/button/new_play.png", sf::Vector2f(100, 100)) {
    _pos = sf::Vector2f(100, 100);
    _len = sf::Vector2f(300, 108);
    _relPos = sf::Vector2f(_pos.x + _len.x, _pos.y + _len.y);
}

StartBtn::~StartBtn() {}

void StartBtn::update(sf::Event &e) {
    sf::Vector2i mp = sf::Mouse::getPosition();
    sf::Color base = _sprite.getColor();
    sf::Color over(base.r - 10, base.g - 10, base.b - 10);
    if (mp.x >= _pos.x && mp.x <= _relPos.x && mp.y >= _pos.y && mp.y <= _relPos.y) {
        _sprite.setColor(over);
        // if (e.type == sf::Event::MouseButtonPressed)
        //     currentScene = t;
    } else
        _sprite.setColor(base);
}

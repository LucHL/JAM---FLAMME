/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** StartBtn
*/

#include "StartBtn.hpp"

StartBtn::StartBtn(): ABtn("assets/button/new_play.png", sf::Vector2f(100, 100)) {}

StartBtn::~StartBtn() {}

void StartBtn::update(sf::Event &e, sf::RenderWindow &w) {
    sf::Vector2i mp = sf::Mouse::getPosition(w);
    sf::Color base = _sprite.getColor();
    sf::Color over(base.r - 10, base.g - 10, base.b - 10);
    if (isMouseOver(w)) {
        _sprite.setColor(over);
        std::cerr << "in" << std::endl;
        if (e.type == sf::Event::MouseButtonPressed)
            std::cerr << "click" << std::endl;

            // currentScene = t;
    } else
        _sprite.setColor(base);
}

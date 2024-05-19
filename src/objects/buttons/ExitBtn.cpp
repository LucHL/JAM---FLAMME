/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** ExitBtn
*/

#include "ExitBtn.hpp"

ExitBtn::ExitBtn(sf::Vector2f pos) : ABtn("assets/button/new_exit.png", pos) {}

ExitBtn::~ExitBtn() {}

void ExitBtn::update(sf::Event &e, sf::RenderWindow &w) {
    sf::Vector2i mp = sf::Mouse::getPosition(w);
    sf::Color base = _sprite.getColor();
    sf::Color over(base.r - 10, base.g - 10, base.b - 10);
    if (isMouseOver(w)) {
        _sprite.setColor(over);
        if (e.type == sf::Event::MouseButtonPressed)
            w.close();

    } else
        _sprite.setColor(base);
}

/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Btn
*/

#include "Btn.hpp"

Btn::Btn(std::string path, sf::Vector2f p, sf::Vector2f l) {
    _pos = p;
    _len = l;
    _relPos = sf::Vector2f(_pos.x + _len.x, _pos.y + _len.y);
    _texture.loadFromFile(path);
    _sprite.setTexture(_texture);
    _sprite.setPosition(p.x, p.y);
}

Btn::~Btn() {}

void Btn::update(sf::Event &e, sceneType t) {
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

void Btn::draw(sf::RenderWindow &w) {
    w.draw(_sprite);
}

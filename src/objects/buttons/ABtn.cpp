/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Btn
*/

#include "ABtn.hpp"

ABtn::ABtn(std::string path, sf::Vector2f p) {
    _texture.loadFromFile(path);
    _sprite.setTexture(_texture);
    _sprite.setPosition(p.x, p.y);
}

ABtn::~ABtn() {}

void ABtn::draw(sf::RenderWindow &w) {
    w.draw(_sprite);
}

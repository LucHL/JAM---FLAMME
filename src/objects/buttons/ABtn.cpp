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
    _sprite.setTexture(_texture);
    w.draw(_sprite);
}

bool ABtn::isMouseOver(sf::RenderWindow &w) {
    sf::FloatRect bounds = _sprite.getGlobalBounds();
    sf::Vector2i mousePos = sf::Mouse::getPosition(w);

    return bounds.contains(static_cast<sf::Vector2f>(mousePos));
}
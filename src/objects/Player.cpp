/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** Player.cpp
*/

#include "Player.hpp"

Player::Player()
{
    _texture.loadFromFile("assets/characters/car.png");
    _sprite.setTexture(_texture);
    _pos.x = 0;
    _pos.y = 0;
}

Player::~Player()
{
}

sf::Sprite &Player::getSprite()
{
    return _sprite;
}

void Player::setPosition(sf::Vector2f pos)
{
    _pos.x += pos.x;
    _pos.y += pos.y;
    _sprite.setPosition(_pos);
}

void Player::update(sf::Event &e)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        _sprite.setPosition((sf::Vector2f){-50, 0});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        _sprite.setPosition((sf::Vector2f){50, 0});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        std::cout << "Flèche de haut" << std::endl;
}

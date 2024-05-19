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

sf::Sprite &Player::getSprite() {
    return _sprite;
}

void Player::setPosition(sf::Vector2f pos)
{
    _pos.x += pos.x;
    _pos.y += pos.y;
    _sprite.setPosition(_pos);
}

Player::~Player()
{
}
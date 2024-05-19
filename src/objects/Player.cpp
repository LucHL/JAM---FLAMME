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

void Player::changePlayerPos(sf::Vector2f pos)
{
    _pos.x += pos.x;
    _pos.y += pos.y;
    _sprite.setPosition(_pos);
}

void Player::update(sf::Event &e)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        changePlayerPos((sf::Vector2f){-50, 0});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        changePlayerPos((sf::Vector2f){50, 0});
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        std::cout << "Flèche de haut" << std::endl;
}

void Player::draw(sf::RenderWindow &w)
{
    w.draw(_sprite);
}

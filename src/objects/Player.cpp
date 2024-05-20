/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** Player.cpp
*/

#include "Player.hpp"
#include "Road.hpp"

Player::Player()
{
    _rect.top = 64;
    _rect.left = 192;
    _rect.width = 32;
    _rect.height = 64;
    _texture.loadFromFile("assets/characters/char_chef.png", _rect);
    _sprite.setTexture(_texture, true);
    _pos.x = 944;
    _pos.y = 920;
    _sprite.setPosition(_pos);
    _state = 0;
}

Player::~Player()
{
}

void Player::changePlayerPos(sf::Vector2f pos)
{
    _pos.x += pos.x;
    if (_pos.x < 0)
        _pos.x = 0;
    if (_pos.x > 1888)
        _pos.x = 1888;
    _pos.y += pos.y;
    _sprite.setPosition(_pos);
}

void Player::changePlayerSkin(int top, int left)
{
    _rect.top = top;
    _rect.left = left;
    _texture.loadFromFile("assets/characters/char_chef.png", _rect);
    _sprite.setTexture(_texture, true);
}

void Player::movePlayerUp(std::vector<std::shared_ptr<Road>> road, int *builderPos) {
    if (_state == 0)
        changePlayerSkin(64, 192);
    if (_state == 1)
        changePlayerSkin(128, 224);
    if (_state == 2)
        changePlayerSkin(128, 320);
    for (auto &rod : road)
        rod->moveWorldRoad(builderPos);
}

void Player::movePlayerLeft() {
    if (_state == 0)
        changePlayerSkin(128, 448);
    if (_state == 1)
        changePlayerSkin(128, 416);
    if (_state == 2)
        changePlayerSkin(128, 480);
    changePlayerPos((sf::Vector2f){-50, 0});
}

void Player::movePlayerRight() {
    if (_state == 0)
        changePlayerSkin(128, 64);
    if (_state == 1)
        changePlayerSkin(128, 32);
    if (_state == 2)
        changePlayerSkin(128, 96);
    changePlayerPos((sf::Vector2f){50, 0});
}

void Player::update(sf::Event &e, std::vector<std::shared_ptr<Road>> road, int *builderPos)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        movePlayerUp(road, builderPos);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        movePlayerLeft();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        movePlayerRight();
}

void Player::draw(sf::RenderWindow &w)
{
    w.draw(_sprite);
}

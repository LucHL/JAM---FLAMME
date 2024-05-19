/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** Player.hpp
*/

#pragma once
#include "../main.hpp"

class Player
{
private:
    sf::Vector2f _pos;
    sf::Texture _texture;
    sf::Sprite _sprite;
public:
    Player(/* args */);
    sf::Sprite &getSprite();
    void setPosition(sf::Vector2f pos);
    ~Player();
};
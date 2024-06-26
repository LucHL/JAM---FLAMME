/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** Player.hpp
*/

#pragma once
#include "../main.hpp"
#include "Road.hpp"

class Player
{
    public:
        Player();
        ~Player();

        void movePlayerUp(std::vector<std::shared_ptr<Road>> road, int *builderPos);
        void movePlayerLeft(std::vector<std::shared_ptr<Road>> road);
        void movePlayerRight(std::vector<std::shared_ptr<Road>> road);
        bool checkPlayerCollision(const sf::Sprite &collision, sf::Vector2f newPos);
        void changePlayerPos(sf::Vector2f pos);
        void changePlayerSkin(int top, int left);
        sf::Sprite &getCollisionSprite();
        void update(sf::Event &e, std::vector<std::shared_ptr<Road>> _list, int *builderPos);
        void draw(sf::RenderWindow &w);

    private:
        sf::Vector2f _pos;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Clock _clock;
        sf::IntRect _rect;
        int _state;
};

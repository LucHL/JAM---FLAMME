/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AScene
*/

#include "AScene.hpp"

AScene::AScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t) : _window(win), _t(t)
{
    _texture.loadFromFile(backgroundPath);
    _sprite = sf::Sprite(_texture);
    _sprite.setScale(sf::Vector2f(1.57,1.5));
}

AScene::~AScene() {}

void AScene::update(sf::Event &e)
{
    _sprite.setTexture(_texture);
    _window.draw(_sprite);
}

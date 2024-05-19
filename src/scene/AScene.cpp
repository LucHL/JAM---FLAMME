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
    _button = Btn("assets/button/new_play.png", sf::Vector2f(100,100), sf::Vector2f(300,108));
}

AScene::~AScene() {}

void AScene::update(sf::Event &e)
{
    return;
}

void AScene::draw()
{
    _sprite.setTexture(_texture);
    _window.draw(_sprite);
    _button.draw(_window);
}

void AScene::initialize()
{
    
}

sceneType &AScene::getType()
{
    return _t;
}

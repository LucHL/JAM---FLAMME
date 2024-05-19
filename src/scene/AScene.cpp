/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** AScene
*/

#include "AScene.hpp"

AScene::AScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t) : _window(win), _t(t)
{
    _bgTexture.loadFromFile(backgroundPath);
    _bgSprite = sf::Sprite(_bgTexture);
    _bgSprite.setScale(sf::Vector2f(1.57,1.5));
}

AScene::~AScene() {}

void AScene::update(sf::Event &e)
{
    _bgSprite.setTexture(_bgTexture);
    _window.draw(_bgSprite);
}

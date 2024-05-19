/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** GameScene.cpp
*/

#include "GameScene.hpp"

GameScene::GameScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t)
    : AScene(backgroundPath, win, t)
{
}

GameScene::~GameScene()
{
}

void GameScene::draw()
{
    _player.draw(_window);
}

void GameScene::update(sf::Event &e)
{
    _player.update(e);
}

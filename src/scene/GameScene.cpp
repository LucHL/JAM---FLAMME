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

void GameScene::initialize() {}

void GameScene::draw()
{
    _player.draw(_window);
}

void GameScene::update(sf::Event &e)
{
    _player.update(e);
}

// createText("score ici", 50, sf::Color::Cyan, sf::Vector2f(20, 20));
// createRect(sf::Color::White, sf::Color::Black, 1.0f, sf::Vector2f(0, 0),
//     sf::Vector2f(1810, 45), 0.0f, sf::Vector2f(70, 50), false);

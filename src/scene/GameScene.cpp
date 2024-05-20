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
    _builderPos = 920;
    _isHighway = false;
}

GameScene::~GameScene()
{
}

void GameScene::draw()
{
    for (auto &road : _list)
        road->draw(_window);
    _player.draw(_window);
}

void GameScene::update(sf::Event &e)
{
    while (_builderPos > 0){
        createRoad(std::make_shared<Road>(_isHighway, 4, &_builderPos));
        _isHighway = _isHighway ? false : true;
    }
    _player.update(e);
}

int GameScene::createRoad(std::shared_ptr<Road> road) {
    _list.push_back(road);
    return road->getRoadSize();
}

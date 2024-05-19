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
    _pos_y = 920;
    _isHighway = false;
}

GameScene::~GameScene()
{
}

void GameScene::draw()
{
    _player.draw(_window);
    for (auto &road : _list)
        road->draw(_window);
}

void GameScene::update(sf::Event &e)
{
    while (_pos_y > 0){
        _pos_y -= createRoad(std::make_shared<Road>(_isHighway, 4, _pos_y));
        _isHighway = _isHighway ? false : true;
    }
    _player.update(e);
}

int GameScene::createRoad(std::shared_ptr<Road> road) {
    _list.push_back(road);
    return road->getRoadSize();
}

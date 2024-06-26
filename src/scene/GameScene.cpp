/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** GameScene.cpp
*/

#include "GameScene.hpp"
#include <chrono>
#include <thread>

GameScene::GameScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t)
    : AScene(backgroundPath, win, t)
{
    _music = std::make_unique<sf::Music>();
    if (!_music->openFromFile("assets/music/SUBWAY-SURFERS-_Main-Theme_.ogg"))
        std::cerr << "Fail to load music." << std::endl;
    _music->play();
    _builderPos = 1007;
    _isHighway = false;
    _gameSeed = std::time(nullptr);
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
    _time = _clock.restart();
    _player.update(e, _list, &_builderPos);

    while (_builderPos > 0){
        createRoad(std::make_shared<Road>(_isHighway, 4, &_builderPos, &_gameSeed));
        _isHighway = _isHighway ? false : true;
    }
    if (_time.asMilliseconds() >= 4 || _time.asMilliseconds() == 0) {
        for (auto &road : _list)
            road->update(_player.getCollisionSprite());
        _clock.restart();
    }
    if (_list.size() > 15)
        _list.erase(_list.begin());
}

void GameScene::createRoad(std::shared_ptr<Road> road) {
    _list.push_back(road);
}

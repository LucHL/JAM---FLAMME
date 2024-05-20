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
    while (_builderPos > 0){
        createRoad(std::make_shared<Road>(_isHighway, 4, &_builderPos, &_gameSeed));
        _isHighway = _isHighway ? false : true;
    }
    _player.update(e);
}

void GameScene::createRoad(std::shared_ptr<Road> road) {
    _list.push_back(road);
}

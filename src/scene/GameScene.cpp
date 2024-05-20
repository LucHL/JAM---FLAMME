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
    _pos_y = 920;
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

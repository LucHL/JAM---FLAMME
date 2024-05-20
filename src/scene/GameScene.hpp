/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** GameScene.hpp
*/

#pragma once
#include "AScene.hpp"
#include "../objects/Player.hpp"
#include "../objects/Road.hpp"

class GameScene : public AScene {
    public:
        GameScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t);
        ~GameScene();

        void draw() override;
        void update(sf::Event &e) override;
        void createRoad(std::shared_ptr<Road> road);

    private:
        bool _isHighway;
        int _builderPos;
        unsigned int _gameSeed;
        Player _player;
        sf::Clock _clock;
        std::vector<std::shared_ptr<Road>> _list;
};

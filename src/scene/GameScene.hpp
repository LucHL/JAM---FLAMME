/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** GameScene.hpp
*/

#pragma once
#include "AScene.hpp"

class GameScene : public AScene {
    public:
        GameScene(std::string backgroundPath, sf::RenderWindow &win, sceneType t);
        ~GameScene();

        void draw() override;
        void update(sf::Event &e) override;
        void initialize() override;

    private:
};
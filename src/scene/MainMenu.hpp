/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** MainMenu.hpp
*/

#pragma once
#include "AScene.hpp"

class MainMenu : public AScene {
    public:
        MainMenu(std::string backgroundPath, sf::RenderWindow &win, sceneType t);
        ~MainMenu();

        void draw() override;
        void update(sf::Event &e) override;
        void initialize() override;

    private:
};

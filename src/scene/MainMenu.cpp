/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** MainMenu.cpp
*/

#include "MainMenu.hpp"

MainMenu::MainMenu(std::string backgroundPath, sf::RenderWindow &win, sceneType t)
    : AScene(backgroundPath, win, t)
{
}

MainMenu::~MainMenu() {}

void MainMenu::draw()
{
    for (auto &i : _button)
        i->draw(_window);
}

void MainMenu::update(sf::Event &e)
{

}

void MainMenu::initialize()
{
    _button.push_back(std::make_shared<StartBtn>(StartBtn()));
}

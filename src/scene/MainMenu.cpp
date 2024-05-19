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

MainMenu::~MainMenu()
{
    
}

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
    _button.push_back(std::make_shared<Btn>
        (Btn("assets/button/new_play.png", sf::Vector2f(800,350), sf::Vector2f(330,108))));
    _button.push_back(std::make_shared<Btn>
        (Btn("assets/button/new_settings.png", sf::Vector2f(550,550), sf::Vector2f(330,108))));
    _button.push_back(std::make_shared<Btn>
        (Btn("assets/button/new_exit.png", sf::Vector2f(1050,550), sf::Vector2f(330,108))));
}

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
    _button.push_back(std::make_unique<StartBtn>(sf::Vector2f(800,300)));
    _button.push_back(std::make_unique<SettingsBtn>(sf::Vector2f(600,500)));
    _button.push_back(std::make_unique<ExitBtn>(sf::Vector2f(1000, 500)));
}

MainMenu::~MainMenu() {}

void MainMenu::draw()
{
    _bgSprite.setTexture(_bgTexture);
    _window.draw(_bgSprite);
    for (auto &i : _button)
        i->draw(_window);
}

void MainMenu::update(sf::Event &e)
{
    for (auto &i : _button)
        i->update(e, _window);
}

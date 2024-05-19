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
    _sprite.setTexture(_texture);
    _window.draw(_sprite);
    for (auto &i : _button)
        i->draw(_window);
}

void MainMenu::update(sf::Event &e)
{
    for (auto &i : _button)
        i->update(e, _window);
}

void MainMenu::initialize()
{
    _button.push_back(std::make_shared<StartBtn>(StartBtn(sf::Vector2f(780,300))));
    _button.push_back(std::make_shared<SettingsBtn>(SettingsBtn(sf::Vector2f(600,500))));
}

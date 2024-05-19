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
    createSprite(sf::Vector2f(0, 0), backgroundPath, sf::Vector2f(100, 100), true);
}

MainMenu::~MainMenu()
{
    
}

void MainMenu::draw()
{
    for (auto &i : _sprite)
        _window.draw(i);
    for (auto &i : _rect)
        _window.draw(i);
    for (auto &i : _text)
        _window.draw(i);
}

void MainMenu::update(sf::Event &e)
{
    // for (auto i : _rect)
}

void MainMenu::initialize()
{
    createText("Jouer", 50, sf::Color::Green, sf::Vector2f(880, 440));
    createRect(sf::Color::White, sf::Color::Black, 1.0f, sf::Vector2f(440, 600),
        sf::Vector2f(1000, 1000), 0.0f, sf::Vector2f(780, 150), false);
    createText("Option", 50, sf::Color::Yellow, sf::Vector2f(670, 610));
    createRect(sf::Color::White, sf::Color::Black, 1.0f, sf::Vector2f(440, 430),
        sf::Vector2f(1000, 1000), 0.0f, sf::Vector2f(380, 150), false);
    createText("Quitter", 50, sf::Color::Red, sf::Vector2f(1070, 610));
    createRect(sf::Color::White, sf::Color::Black, 1.0f, sf::Vector2f(40, 430),
        sf::Vector2f(1000, 1000), 0.0f, sf::Vector2f(380, 150), false);
}
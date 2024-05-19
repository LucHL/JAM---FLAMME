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

void MainMenu::update(sf::Event &e)
{
    // for (auto i : _rect)
        
}

void MainMenu::initialize()
{
    createRect(sf::Color::White, sf::Color::Black)
}
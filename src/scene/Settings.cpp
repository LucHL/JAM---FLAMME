/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Settings
*/

#include "Settings.hpp"

Settings::Settings(std::string backgroundPath, sf::RenderWindow &win, sceneType t)
    : AScene(backgroundPath, win, t) {}

Settings::~Settings() {}

void Settings::draw() {
    _bgSprite.setTexture(_bgTexture);
    _window.draw(_bgSprite);
}

void Settings::update(sf::Event &e)
{

}

void Settings::initialize()
{

}

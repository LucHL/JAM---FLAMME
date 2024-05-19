/*
** EPITECH PROJECT, 2023
** JAM---FLAMME
** File description:
** MainMenu.cpp
*/

#include "MainMenuBtn.hpp"

MainMenuBtn::MainMenuBtn(sf::Vector2f pos): ABtn("assets/button/new_exit.png", pos) {}

MainMenuBtn::~MainMenuBtn()
{
}

void MainMenuBtn::update(sf::Event &e, sf::RenderWindow &w) {
    sf::Vector2i mp = sf::Mouse::getPosition();
    sf::Color base = _sprite.getColor();
    sf::Color over(base.r - 10, base.g - 10, base.b - 10);
    if (isMouseOver(w)) {
        _sprite.setColor(over);
        if (e.type == sf::Event::MouseButtonPressed) {
            SceneManager &inst = SceneManager::getInstance();
            inst.setChange(true);
            inst.changeScene(sceneType::MAINMENU);
        }
    } else
        _sprite.setColor(base);
}

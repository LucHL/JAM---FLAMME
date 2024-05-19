/*
** EPITECH PROJECT, 2024
** JAM---FLAMME
** File description:
** Game
*/

#include "Game.hpp"
#include "scene/AScene.hpp"
#include "scene/Settings.hpp"
#include "scene/MainMenu.hpp"
#include "scene/GameScene.hpp"
#include "objects/Pixel.hpp"

Game::Game(sf::RenderWindow &win, sf::Event &event) : _window(win), _event(event)
{
    createWindow();
}

Game::~Game() {}

void Game::createWindow()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    _window.create(sf::VideoMode(1920, 1080), "FLAMME", sf::Style::Default, settings);
    _s = std::make_shared<MainMenu>(MainMenu("assets/startmenu.png", _window, sceneType::MAINMENU));
    // _s = std::make_shared<Settings>(Settings("assets/startmenu.png", _window, sceneType::SETTINGS));
}

void Game::gameLoop()
{
    _s->initialize();

    while (_window.isOpen()) {
        _window.clear(sf::Color::Black);

        handleEvent();
        _window.display();
    }
}

void Game::handleEvent()
{
    if (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _window.close();
        }
        _s->update(_event);
    }
    _s->draw();
}

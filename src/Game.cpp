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

Game::Game(sf::RenderWindow &win, sf::Event &event) : _window(win), _event(event) {
    createWindow();
}

Game::~Game() {}

void Game::createWindow() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    _window.create(sf::VideoMode(1920, 1080), "FLAMME", sf::Style::Default, settings);
    _s = std::make_unique<MainMenu>("assets/startmenutest.png", _window, sceneType::MAINMENU);
}

void Game::gameLoop()
{
    while (_window.isOpen()) {
        _window.clear(sf::Color::White);
        handleEvent();
        _window.display();
    }
}

void Game::changeScene(sceneType t) {
    switch (t)
    {
    case sceneType::SETTINGS:
        _s.reset(std::make_unique<Settings>("assets/settings.png", _window, sceneType::SETTINGS).release());
        break;
    case sceneType::GAMESCENE:
        _s.reset(std::make_unique<GameScene>("", _window, sceneType::GAMESCENE).release());
        break;
    default:
        _s.reset(std::make_unique<MainMenu>("assets/startmenutest.png", _window, sceneType::MAINMENU).release());
    }
}

void Game::handleEvent() {
    if (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _window.close();
        }

        SceneManager &inst = SceneManager::getInstance();
        if (inst.isChange()) {
            changeScene(inst.whatchange());
            inst.setChange(false);
        }

    }
    _s->update(_event);
    _s->draw();
}
